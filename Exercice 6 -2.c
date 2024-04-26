#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY 10  // Taille du tableau
#define NUM_THREADS 4    // Nombre de threads


int totalSum = 0;


typedef struct {
    int *start;
    int *end;
    pthread_mutex_t *lock;
} PartialSumArgs;


void *sum_partial(void *args) {
    PartialSumArgs *partialArgs = (PartialSumArgs *)args;

    int partialSum = 0;

    int *p;
    for (p = partialArgs->start; p < partialArgs->end; p++) {
        partialSum += *p;
    }

    pthread_mutex_lock(partialArgs->lock);

    totalSum += partialSum;

    pthread_mutex_unlock(partialArgs->lock);

    pthread_exit(NULL);
}

int main() {
    int array[ARRAY];
    int i;

    for (i = 0; i < ARRAY; ++i) {
        array[i] = i + 1;
    }

    pthread_mutex_t lock;
    pthread_mutex_init(&lock, NULL);


    pthread_t threads[NUM_THREADS];

    PartialSumArgs threadArgs[NUM_THREADS];

    int sectionSize = ARRAY / NUM_THREADS;
    for (i = 0; i < NUM_THREADS; ++i) {
        threadArgs[i].start = (array+i * sectionSize);
        threadArgs[i].end = (array + ((i == NUM_THREADS - 1) ? ARRAY : (i + 1) * sectionSize));
        threadArgs[i].lock = &lock;

        if (pthread_create(&threads[i], NULL, sum_partial, (void *)&threadArgs[i]) != 0) {
            fprintf(stderr, "Erreur lors de la création du thread %d\n", i);
            return 1;
        }
    }

    for (i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("Somme totale : %d\n", totalSum);

    pthread_mutex_destroy(&lock);

    return 0;
}
