#include <time.h>
#include "../ordenadores.h"

void bubbleSort(int vetor[], int n) {
    int temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

double medirTempoBubble(int vetor[], int n) {
    clock_t inicio, fim;

    inicio = clock();
    bubbleSort(vetor, n);
    fim = clock();

    return ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
}