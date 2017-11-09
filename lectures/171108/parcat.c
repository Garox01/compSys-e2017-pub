#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* print_file(void *arg) {
  FILE *f = arg;
  char c;
  int cont = 1;
   while (cont) {
    pthread_mutex_lock(&mutex);
    cont = fread(&c, sizeof(char), 1, f) == 1;
    if (cont) {
      putchar(c);
    }
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

int main(int argc, char **argv) {
  const char *filename = argv[1];

  FILE *file = fopen(filename, "r");
  assert(file != NULL);

  pthread_t thread_a, thread_b;
  assert(pthread_create(&thread_a, NULL, print_file, file) == 0);
  assert(pthread_create(&thread_b, NULL, print_file, file) == 0);

  assert(pthread_join(thread_a, NULL) == 0);
  assert(pthread_join(thread_b, NULL) == 0);

  return 0;
}
