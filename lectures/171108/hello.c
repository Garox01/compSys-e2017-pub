/*
 * gcc hello.c csapp.c -o hello -pthread
 */
#include "csapp.h"

void *thread(void *vargp);

int main()
{
    pthread_t tid;
    Pthread_create(&tid, NULL, thread, NULL);
    //    Pthread_join(tid, NULL);
    pthread_exit(0);
}

void *thread(void *vargp) /* thread routine */
{
    printf("Hello, world!\n");
    return NULL;
}
