#include <pthread.h>   
#include <stdio.h>     
#include <stdlib.h>    

void *func(void *arg) {
    // Convertir l'argument en pointeur vers char
    char *msg = (char *) arg;
    printf("Message = %s\n", msg);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t t;  // Déclaration d'une variable de type pthread_t pour stocker l'identifiant du thread
    char *msg = "Threads are awesome!";  // Déclaration d'un pointeur vers char contenant le message à afficher dans le thread

    // Créer un nouveau thread et vérifier s'il est créé avec succès
    if (pthread_create(&t, NULL, func, msg) != 0) {
        perror("thread creation error");  // message d'erreur
        return EXIT_FAILURE; 
    }

    // Attendre que le thread se termine et vérifier s'il se termine avec succès
    if (pthread_join(t, NULL) != 0) {
        perror("Error");  // message d'erreur
        return EXIT_FAILURE; 

    return EXIT_SUCCESS;  
}
