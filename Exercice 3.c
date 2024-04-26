#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//execute tache1
void *Tache1(void *arg) {
    int i = 0;
    while (i < 5) {
        printf("Exécution de la Tâche 1\n");
        sleep(1);
        i++;
    }
    return NULL;
}


//execute tache2
void *Tache2(void *arg) {
    int j = 0;
    while (j < 3) {
        printf("Exécution de la Tâche 2\n");
        sleep(2);
        j++;
    }
    return NULL;
}


//Test 1
int main(int argc, char *argv[]){
    pthread_t thread1, thread2;
    
    // Création du premier thread et attente de sa terminaison
    pthread_create(&thread1, NULL, Tache1, NULL); 
    pthread_join(thread1, NULL);
    
    // Création du deuxième thread et attente de sa terminaison
    pthread_create(&thread2, NULL, Tache2, NULL);
    pthread_join(thread2, NULL);
    
    return EXIT_SUCCESS;
}




