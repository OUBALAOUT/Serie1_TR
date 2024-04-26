#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_func1(void *arg) {
	printf("Thread 1: Bonjour !\n");
	return NULL;//La fonction thread_func1 est exécutée par le premier thread. 
	
}

void *thread_func2(void *arg) {
	printf("Thread 2: Salut !\n");
	return NULL;//La fonction thread_func2 est exécutée par le deuxième thread.
}

int main(int argc, char *argv[]) {
	pthread_t t1;
	pthread_t t2;
	
// Creation d'un thread avec la fonction PThread_Create()
	if (pthread_create(&t1, NULL, thread_func1, NULL) != 0) {
		perror("thread creation error");
		return EXIT_FAILURE;
	}
// Creation d'un 2eme thread .
	if (pthread_create(&t2, NULL, thread_func2, NULL) != 0) {
		perror("thread creation error");
		return EXIT_FAILURE;
	}
	//utilise pthread_join() pour attendre que chaque thread se termine.
	if(pthread_join(t1, NULL) !=0){
        perror("Error");
        EXIT_FAILURE;
    }
    
    if(pthread_join(t2, NULL) !=0){
        perror("Error");
        EXIT_FAILURE;
    }
	
	return EXIT_SUCCESS;
}
