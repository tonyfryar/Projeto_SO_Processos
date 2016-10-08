


#ifndef FUNCOESORDENACAO_H
#define FUNCOESORDENACAO_H

#define MAXPALAVRAS 1000

using namespace std;

void troca (string vetor[],int esq, int dir);
//void troca (int vetor[], int esq, int dir);
void ordenarTextoSelection(char* argv);
void ordenarTextoInsertion(char* argv);
void ordenarTextoQuick(char* argv);

void quickSort(int *vet, int esq, int dir);
void selection_sort(int num[], int tam);
void insertionSort(int* vetor,int fim ,int inicio);

void insertionSortString(string vetor[], int fim, int inicio);
void quickSortString(string vetor[],int fim, int inicio);

#endif 
