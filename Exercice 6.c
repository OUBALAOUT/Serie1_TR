#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int tab[12]={1,3,4,4,6,4,7,9,2,4,9,5};
int somme=0;

typedef struct {
    int start;
    int end;
    //pthread_mutex_t *lock;
} PartialSumArgs;

void *sum_partial(void *arg){
	PartialSumArgs *indice=(PartialSumArgs *) arg;
	int i;
	for(i=indice->start;i<=indice->end;i++){
		somme=somme+tab[i];
	}
	return NULL;
}

int main(){
	pthread_t t1;
	pthread_t t2;
	pthread_t t3;
	PartialSumArgs ps1,ps2,ps3;
	ps1.start=0;
	ps1.end=4;
	
	ps2.start=5;
	ps2.end=8;
	
	ps3.start=9;
	ps3.end=11;
	
	if (pthread_create(&t1, NULL, sum_partial, &ps1) != 0) {
		perror("thread creation error");
		return EXIT_FAILURE;
	}
	
	if (pthread_create(&t2, NULL, sum_partial, &ps2) != 0) {
		perror("thread creation error");
		return EXIT_FAILURE;
	}

	if (pthread_create(&t3, NULL, sum_partial, &ps3) != 0) {
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
    
    if(pthread_join(t3, NULL) !=0){
        perror("Error");
        EXIT_FAILURE;
    }
    
    printf("%d",somme);
	
	return EXIT_SUCCESS;
}
