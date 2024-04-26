#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	int period;
} PeriodicTask;

void *taskFunction(void *arg){
	PeriodicTask *task = (PeriodicTask *) arg;
	while(1){
		sleep(task->period);
		printf("Task %d executed.\n", task->id);
	}
	return NULL;
}

int main(int argc, char *argv[]){
	PeriodicTask task1,task2;
	task1.id=1;
	task1.period=1;
	task2.id=2;
	task2.period=2;
	
	pthread_t t1;
	pthread_t t2;
	
	if (pthread_create(&t1, NULL, taskFunction, &task1) != 0) {
		perror("thread creation error");
		return EXIT_FAILURE;
	}
	
	if (pthread_create(&t2, NULL, taskFunction, &task2) != 0) {
		perror("thread creation error");
		return EXIT_FAILURE;
	}
	
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
