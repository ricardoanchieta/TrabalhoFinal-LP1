#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 0

void shuffle(int *array, int qtd) {
    for (int i = qtd - MIN - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
    }
}
void algoritmoBaixo(int qtd) {
    srand(time(NULL));

    int *numeros = malloc((qtd - MIN) * sizeof(int));

    if (!numeros) exit(EXIT_FAILURE);

    for (int i = 0; i < qtd - MIN; i++) {
        numeros[i] = i + MIN;

    }
    shuffle(numeros,qtd);

    for (int i = 0; i < qtd; i++) {
        printf("funcionario %d para a tarefa %d\n", i, numeros[i]);
    }

    return 0;
 }
