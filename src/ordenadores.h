#ifndef ORDENADORES_H
#define ORDENADORES_H

void copiarVetor(int origem[], int destino[], int n);
void gerarVetorAleatorio(int vetor[], int n);

void bubbleSort(int vetor[], int n);
void mergeSort(int vetor[], int inicio, int fim);
void quickSort(int vetor[], int baixo, int alto);

double medirTempoBubble(int vetor[], int n);
double medirTempoMerge(int vetor[], int n);
double medirTempoQuick(int vetor[], int n);

#endif