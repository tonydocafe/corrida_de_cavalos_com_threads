# Simulação de Corrida de Cavalos com Threads em C

## Descrição
Este programa simula uma corrida de cavalos utilizando threads em C. Cada cavalo é representado por uma thread que progride aleatoriamente ao longo da pista até atingir a linha de chegada. A corrida é dividida em estágios, e há sincronização entre os cavalos para garantir que todos completem os estágios antes de avançar.

## Funcionalidades
- Simulação de uma corrida com 10 cavalos (threads)
- Progresso aleatório para cada cavalo
- Sincronização de etapas utilizando barreiras (`pthread_barrier_t`)
- Uso de mutex (`pthread_mutex_t`) para garantir consistência ao acessar recursos compartilhados
- Exibição do vencedor ao final da corrida

## Compilação e Execução
### Compilar o código:
```sh
gcc -o corrida p_thread.c -pthread
```

### Executar o programa:
```sh
./corrida
```

## Dependências
- Compilador compatível com C (ex: `gcc`)
- Biblioteca `pthread` para manipulação de threads

## Estrutura do Código
- `corrida(void* id)`: Função executada por cada thread que simula o progresso do cavalo.
- `main()`: Inicializa os recursos, cria e gerencia as threads e finaliza a execução.

## Explicação Técnica
- O progresso de cada cavalo é incrementado aleatoriamente dentro de um loop até atingir a distância total.
- A cada estágio concluído, um mutex garante que a exibição das mensagens ocorra sem concorrência.
- A barreira (`pthread_barrier_wait`) sincroniza as threads, garantindo que todas avancem juntas para o próximo estágio.
- O primeiro cavalo a completar a corrida é declarado vencedor e encerramos a simulação.

## Exemplo de Saída
```sh
Cavalo 3 chegou à etapa 1!
Cavalo 7 chegou à etapa 1!
Cavalo 1 chegou à etapa 1!
...
CAVALO 5 É O VENCEDOR!
```

## Autor
Tony Hudson Candido Junior



























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

