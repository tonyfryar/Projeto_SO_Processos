#ifndef FUNCOESORDENACAO_H
#define FUNCOESORDENACAO_H

void insertionSort(int* vetor,int fim ,int inicio);
//void troca (int vetor[], int esq, int dir);
void quickSort(int *vet, int esq, int dir);
void selection_sort(int num[], int tam);
/*template <typename T>
void quickSort(T vetor[], int fim, int inicio){
    int esq, dir;
    esq = inicio;
    dir = fim;
    if (dir - esq >= 1){
        T pivo = vetor[inicio];
        esq= esq +1;
        while (esq < dir){
            while (vetor[esq] <= pivo && esq <= fim && dir > esq)
                esq++;
            while (vetor[dir] > pivo && dir >= inicio && dir >= esq)
                dir--;
            if (vetor[esq] > vetor[dir]){
            	troca(vetor,esq,dir);
            }
        }
        vetor[inicio] = vetor[dir];
        vetor[dir] = pivo;

       quickSort<T>(vetor, dir-1, inicio);
       quickSort<T>(vetor, fim, dir+1);   
    }
}*/

#endif 