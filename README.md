###
O programa é para teste da OpenMP(Open Multi-Processing) que é uma API de programação paralela usada para criar programas
paralelos em sistemas que suportam múltiplos processadores ou núcleos. Ela fornece uma interface para paralelizar 
tarefas de forma simples, usando diretivas de compilador e funções para controlar threads. 

#### Script
Esse script cria 10 threads para executar a mesma seção de código paralelamente,
cada thread recebe um "número" que representa um cavalo.

##### #pragma omp critical
Apenas uma thread por vez pode acessar essa seção,
garantindo que as mensagens de progresso e o vencedor sejam processados corretamente.

##### #pragma omp barrier

Nenhuma thread pode avançar para o próximo estágio da corrida até que todas tenham chegado à etapa atual.

###### execução
./corrida

gcc corrida_de_cavalo.c -o corrida -fopenmp

gcc p_threads.c -o corrida -pthreads

