#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_TASKS 3



typedef struct {
    int id;
    int period;  // in seconds
} PeriodicTask;


void *taskFunction(void *arg) {
    PeriodicTask *task = (PeriodicTask *)arg;

    while (1) {
        sleep(task->period);
        printf("Task %d executed.\n", task->id);
    }

    return NULL;
}

int main() {
    int TASK_PERIODS[]={1, 2, 3};
    pthread_t threads[NUM_TASKS];
    PeriodicTask tasks[NUM_TASKS];
    int i;


    for (i = 0; i < NUM_TASKS; ++i) {
        tasks[i].id = i + 1;
        tasks[i].period = TASK_PERIODS[i];
        pthread_create(&threads[i], NULL, taskFunction, (void *)&tasks[i]);
    }

    sleep(10);

    for (i = 0; i < NUM_TASKS; ++i) {
        pthread_cancel(threads[i]);
        pthread_join(threads[i], NULL);
    }
    return 0;
}
