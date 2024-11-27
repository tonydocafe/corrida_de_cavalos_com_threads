#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


#define distancia 1000 
#define estagio 5      

int main() {
    int thread_final = -1;
    int estagio_diatancia = distancia / estagio; 

    #pragma omp parallel num_threads( 10 )
    {
        int n_thread = omp_get_thread_num() + 1;
        int progresso = 0;
        int posicao = 1;

//-------- Simulando o progressoo de cada cavalo-----------------------------------------------
        while (progresso < distancia) {
            
             progresso += rand() % 10;// velocidade decidida aléatoriamente

            
            if (progresso >= posicao * estagio_diatancia) {// análise de velocidade e etapa
                #pragma omp critical
                {
                    
                    printf("Cavalo %d chegou à etapa %d!\n", n_thread, posicao);
                }
                posicao++;

               
                #pragma omp barrier // sincornização para cada etapa 
            }
//------------ Verifica o campeão --------------------------------------------------------------
            if (posicao > estagio && thread_final == -1) {
                #pragma omp critical
                {
                    
                    if (thread_final == -1) {
                        thread_final = n_thread;
                        printf("CAVALO %d È O VENCEDOR!\n", n_thread);
                    }
                }
                break; 
            }
        }
    }

    return 0;
}
