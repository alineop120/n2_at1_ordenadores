#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../ordenadores.h"

static void merge(int vetor[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *esquerda = (int *) malloc(n1 * sizeof(int));
    int *direita = (int *) malloc(n2 * sizeof(int));

    if (esquerda == NULL || direita == NULL) {
        printf("Erro ao alocar memoria no Merge Sort.\n");
        exit(1);
    }

    for (int i = 0; i < n1; i++) {
        esquerda[i] = vetor[inicio + i];
    }

    for (int j = 0; j < n2; j++) {
        direita[j] = vetor[meio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        } else {
            vetor[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = direita[j];
        j++;
        k++;
    }

    free(esquerda);
    free(direita);
}

void mergeSort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);

        merge(vetor, inicio, meio, fim);
    }
}

double medirTempoMerge(int vetor[], int n) {
    clock_t inicio, fim;

    inicio = clock();
    mergeSort(vetor, 0, n - 1);
    fim = clock();

    return ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
}