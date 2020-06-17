#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct
{
    int id;
    pthread_mutex_t *m;
} thread_barrier_args;

pthread_barrier_t barreira;

void *thread_n(void *v)
{
    thread_barrier_args *args = (thread_barrier_args *)v;

    printf("Parte 1 thread %d\n", args->id);
    pthread_mutex_lock(args->m);
    pthread_mutex_unlock(args->m);

    // TODO: a barreira vai aqui
    pthread_barrier_wait(&barreira);

    printf("Pós barreira thread %d\n", args->id);
    pthread_mutex_lock(args->m);
    pthread_mutex_unlock(args->m);

    return NULL;
}

int main()
{
    int N = 10;

    // TODO: inicializar todas variáveis da barreira
    pthread_barrier_init(&barreira, NULL, 2);

    // TODO: criar e esperar N threads
    pthread_t ids[N];
    thread_barrier_args args[N];
    pthread_mutex_t m;
    pthread_mutex_init(&m, NULL);

    for (int i = 0; i < N; i++)
    {
        args[i].id = i;
        args[i].m = &m;

        pthread_create(&ids[i], NULL, thread_n, &args[i]);
    }

    for (int i = 0; i < N; i++)
    {
        /* TODO: preencher args e lançar thread */
        pthread_join(ids[i], NULL);
    }

    /* TODO: esperar pela conclusão*/
    pthread_mutex_destroy(&m);

    return 0;
}
