#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenadores.h"

void copiarVetor(int origem[], int destino[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

void gerarVetorAleatorio(int vetor[], int n) {
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 100000;
    }
}

int main() {
    srand(time(NULL));

    int tamanhos[] = {100, 300, 500, 1000, 10000};
    int quantidadeTamanhos = 5;

    FILE *arquivo = fopen("resultados/resultados.csv", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo resultados/resultados.csv.\n");
        return 1;
    }

    fprintf(arquivo, "Tamanho;Bubble Sort (ms);Merge Sort (ms);Quick Sort (ms)\n");

    for (int i = 0; i < quantidadeTamanhos; i++) {
        int n = tamanhos[i];

        int *vetorOriginal = (int *) malloc(n * sizeof(int));
        int *vetorBubble = (int *) malloc(n * sizeof(int));
        int *vetorMerge = (int *) malloc(n * sizeof(int));
        int *vetorQuick = (int *) malloc(n * sizeof(int));

        if (
            vetorOriginal == NULL ||
            vetorBubble == NULL ||
            vetorMerge == NULL ||
            vetorQuick == NULL
        ) {
            printf("Erro ao alocar memoria.\n");
            fclose(arquivo);
            return 1;
        }

        gerarVetorAleatorio(vetorOriginal, n);

        copiarVetor(vetorOriginal, vetorBubble, n);
        copiarVetor(vetorOriginal, vetorMerge, n);
        copiarVetor(vetorOriginal, vetorQuick, n);

        double tempoBubble = medirTempoBubble(vetorBubble, n);
        double tempoMerge = medirTempoMerge(vetorMerge, n);
        double tempoQuick = medirTempoQuick(vetorQuick, n);

        fprintf(arquivo, "%d;%.0f;%.0f;%.0f\n", n, tempoBubble, tempoMerge, tempoQuick);

        free(vetorOriginal);
        free(vetorBubble);
        free(vetorMerge);
        free(vetorQuick);
    }

    fclose(arquivo);

    printf("\nArquivo resultados/resultados.csv criado com sucesso!\n");

    return 0;
}