#include <time.h>
#include "../ordenadores.h"

static int particionar(int vetor[], int baixo, int alto) {
    int pivo = vetor[alto];
    int i = baixo - 1;
    int temp;

    for (int j = baixo; j < alto; j++) {
        if (vetor[j] <= pivo) {
            i++;

            temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }

    temp = vetor[i + 1];
    vetor[i + 1] = vetor[alto];
    vetor[alto] = temp;

    return i + 1;
}

void quickSort(int vetor[], int baixo, int alto) {
    if (baixo < alto) {
        int indicePivo = particionar(vetor, baixo, alto);

        quickSort(vetor, baixo, indicePivo - 1);
        quickSort(vetor, indicePivo + 1, alto);
    }
}

double medirTempoQuick(int vetor[], int n) {
    clock_t inicio, fim;

    inicio = clock();
    quickSort(vetor, 0, n - 1);
    fim = clock();

    return ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;
}