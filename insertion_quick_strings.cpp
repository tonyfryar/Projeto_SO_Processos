// Algoritmos de Ordenação Insertion e Quick
// Tony Freitas

#include <fstream>
#include <iostream>
#include <string>
//#include <stdio.h>
//#include <string.h>
//#include "tarefa5.hpp"

using namespace std;

//Insertion Sort
void insertionSort(string vetor, int fim, int inicio){
    int ii, jj; 
    string chave;
    cout << "insertion" << endl; 

    for (ii = 1; ii <= fim; ii++){
        chave = vetor[ii];
        jj = ii - 1;

        while ((jj >= 0) && (chave.compare(vetor[jj]) < 0)){
            vetor[jj + 1] = vetor[jj];
            jj = jj - 1;
        }
        vetor[jj + 1] = chave;
    }
}

//QuickSort
void quickSort(string vetor[], int fim, int inicio){
    int esq, dir;
    esq = inicio;
    dir = fim;
    if (dir - esq >= 1){
        string pivo = vetor[esq];
        while (esq < dir){
            while (vetor[esq].compare(pivo) <= 0 && esq <= fim && dir > esq)
                esq++;
            while (vetor[dir].compare(pivo) > 0 && dir >= inicio && dir >= esq)
                dir--;
            if (esq < dir)
                troca(vetor, esq, dir);
        }
        vetor[inicio] = vetor[dir];
        vetor[dir] = pivo;

        quickSort(vetor, dir-1, inicio);
        quickSort(vetor, fim, dir+1);   
    }
}

//Função para trocar elementos do vetor
void troca (string vetor[], int esq, int dir){
    string aux = vetor[esq];
    vetor[esq] = vetor[dir];
    vetor[dir] = aux;
}


