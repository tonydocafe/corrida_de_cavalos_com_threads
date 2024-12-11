#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define DISTANCIA 1000
#define ESTAGIO 5

pthread_mutex_t mutex;
pthread_barrier_t barrier;
int thread_final = -1;

void* corrida(void* id) {
    int n_thread = (int)(long)id;
    int progresso = 0;
    int posicao = 1;
    int estagio_diatancia = DISTANCIA / ESTAGIO;

    // Simulando o progresso de cada cavalo
    while (progresso < DISTANCIA) {
        progresso += rand() % 10;  // Velocidade decidida aleatoriamente

        if (progresso >= posicao * estagio_diatancia) {  // Análise de velocidade e etapa
            pthread_mutex_lock(&mutex);
            printf("Cavalo %d chegou à etapa %d!\n", n_thread, posicao);
            pthread_mutex_unlock(&mutex);
            posicao++;

            // Sincronização de etapas
            pthread_barrier_wait(&barrier);
        }

        // Verifica o campeão
        if (posicao > ESTAGIO && thread_final == -1) {
            pthread_mutex_lock(&mutex);
            if (thread_final == -1) {
                thread_final = n_thread;
                printf("CAVALO %d É O VENCEDOR!\n", n_thread);
            }
            pthread_mutex_unlock(&mutex);
            break;
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[10];  // Criando 10 threads
    srand(time(NULL));

    // Inicializando o mutex e a barreira
    pthread_mutex_init(&mutex, NULL);
    pthread_barrier_init(&barrier, NULL, 10);  // Sincronização de 10 threads

    // Criando as threads
    for (long i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, corrida, (void*)i + 1);  // Passando o número do cavalo
    }

    // Aguardando as threads terminarem
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destruindo o mutex e a barreira
    pthread_mutex_destroy(&mutex);
    pthread_barrier_destroy(&barrier);

    return 0;
}
