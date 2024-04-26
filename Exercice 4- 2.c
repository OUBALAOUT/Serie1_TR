#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void * thread_func1(void * args)
{
    while(1)
    {
        printf("Thread 1: Bonjour !\n");
        sleep(1);
    }
    return;
}

void * thread_func2(void * args)
{
    while(1)
    {
        printf("Thread 2: Salut !\n");
        sleep(2);
    }
    return;
}

int main()
{
    pthread_t th1,th2;
//Avec chaque thread se termine en appelant pthread_join.
    pthread_create(&th1,NULL,thread_func1,NULL);
    pthread_create(&th2,NULL,thread_func2,NULL);
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);

    return 0;
}
