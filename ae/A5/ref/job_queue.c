#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "job_queue.h"

int job_queue_init(struct job_queue *job_queue, int capacity) {
  job_queue->capacity = capacity;
  job_queue->first = 0;
  job_queue->num_used = 0;
  job_queue->dead = 0;
  job_queue->buffer = calloc(capacity, sizeof(void*));

  if (pthread_mutex_init(&job_queue->mutex, NULL) != 0) {
    return -1;
  }

  if (pthread_cond_init(&job_queue->cond, NULL) != 0) {
    return -1;
  }

  if (job_queue->buffer == NULL) {
    return -1;
  }

  return 0;
}

int job_queue_destroy(struct job_queue *job_queue) {
  assert(pthread_mutex_lock(&job_queue->mutex) == 0);

  while (job_queue->num_used != 0) {
    pthread_cond_wait(&job_queue->cond, &job_queue->mutex);
  }

  // Queue is now empty.  Let's kill it!
  job_queue->dead = 1;
  free(job_queue->buffer);
  pthread_cond_broadcast(&job_queue->cond);

  assert(pthread_mutex_unlock(&job_queue->mutex) == 0);

  return 0;
}

int job_queue_push(struct job_queue *job_queue, void *data) {
  assert(pthread_mutex_lock(&job_queue->mutex) == 0);

  // Wait until there is room in the job_queue.
  while (job_queue->num_used == job_queue->capacity && !job_queue->dead) {
    pthread_cond_wait(&job_queue->cond, &job_queue->mutex);
  }

  if (job_queue->dead) {
    assert(pthread_mutex_unlock(&job_queue->mutex) == 0);
    return -1;
  }

  // If we made it past the loop, there is room in the job_queue.
  job_queue->buffer[(job_queue->first + job_queue->num_used) % job_queue->capacity] = (unsigned char*)data;
  job_queue->num_used++;

  // Signal a reader (if any) that there is now an element.
  pthread_cond_broadcast(&job_queue->cond);

  assert(pthread_mutex_unlock(&job_queue->mutex) == 0);

  return 0;
}

int job_queue_pop(struct job_queue *job_queue, void **data) {
  assert(pthread_mutex_lock(&job_queue->mutex) == 0);

  // Wait until the job_queue contains an element.
  while (job_queue->num_used == 0 && !job_queue->dead) {
    pthread_cond_wait(&job_queue->cond, &job_queue->mutex);
  }

  if (job_queue->dead) {
    assert(pthread_mutex_unlock(&job_queue->mutex) == 0);
    return -1;
  }

  // We now know that num_used is nonzero.
  job_queue->num_used--;
  *data = job_queue->buffer[job_queue->first];
  job_queue->first = (job_queue->first + 1) % job_queue->capacity;

  // Signal a writer (if any) that there is now room for more.
  pthread_cond_broadcast(&job_queue->cond);

  assert(pthread_mutex_unlock(&job_queue->mutex) == 0);

  return 0;
}
