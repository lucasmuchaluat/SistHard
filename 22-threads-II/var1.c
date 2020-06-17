#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <semaphore.h>

struct soma_parcial_args {
    double *vetor;
    int start, end;

    pthread_mutex_t *m;
};

struct computa_media_variancia_args {
    double *vetor;
    int start, end;
    int q;
    sem_t *semaphore;

    pthread_mutex_t *m;
};

double soma = 0;
void *soma_parcial(void *_arg) {
    struct soma_parcial_args *spa = _arg;

    for (int i = spa->start; i < spa->end; i++) {
        if (spa->m != NULL) pthread_mutex_lock(spa->m);
        soma += spa->vetor[i];
        if (spa->m != NULL) pthread_mutex_unlock(spa->m);
    }

    return NULL;
}

double variancia = 0;
void *computa_media_variancia(void *_arg) {
    struct computa_media_variancia_args *spa = _arg;

    sem_wait(spa->semaphore);

    double avg = soma/spa->q; 
    for (int i = spa->start; i < spa->end; i++) {
        if (spa->m != NULL) pthread_mutex_lock(spa->m);
        variancia += pow ((spa->vetor[i] - avg), 2);
        printf("Var: %f\n", variancia);
        if (spa->m != NULL) pthread_mutex_unlock(spa->m);
    }

    return NULL; 

}


int main(int argc, char *argv[]) {
    double *vetor = NULL;
    int n;
    scanf("%d", &n);

    vetor = malloc(sizeof(double) * n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &vetor[i]);
    }

    pthread_t ids[8];
    struct soma_parcial_args args[4];
    struct computa_media_variancia_args args_var[4];
    sem_t semaforo;
    sem_init(&semaforo, 0, 0);
    pthread_mutex_t m;
    pthread_mutex_init(&m, NULL);

    for (int i = 0; i < 4; i++) {
        args[i].vetor = vetor;
        args[i].start = i * n / 4;
        args[i].end = (i + 1) * n / 4;
        args[i].m = &m;
        if (i == 3) args[i].end = n;

        pthread_create(&ids[i], NULL, soma_parcial, &args[i]);

        args_var[i].vetor = vetor;
        args_var[i].start = i * n / 4;
        args_var[i].end = (i + 1) * n / 4;
        args_var[i].q = n;
        args_var[i].semaphore = &semaforo;
        args_var[i].m = &m;
        if (i == 3) args_var[i].end = n;

        pthread_create(&ids[i+4], NULL, computa_media_variancia, &args_var[i]);

    }

    for (int i = 0; i < 4; i++) {
        pthread_join(ids[i], NULL);
        sem_post(&semaforo);
    }
    

    for (int i = 4; i < 8; i++) {
        pthread_join(ids[i], NULL);
    }

    pthread_mutex_destroy(&m);

    printf("Soma Global: %lf\n", soma);
    printf("Variancia: %lf\n", variancia/n);

    return 0;
}
