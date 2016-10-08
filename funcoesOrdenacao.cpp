

#include <fstream>
#include <cstring>
#include <iostream>
#include <string>
#include "funcoesOrdenacao.h"
using namespace std;

void insertionSortString(string* vetor, int fim, int inicio){
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

//Função para trocar elementos do vetor
void troca (string vetor[], int esq, int dir){
    string aux = vetor[esq];
    vetor[esq] = vetor[dir];
    vetor[dir] = aux;
}

//QuickSort
void quickSortString(string vetor[], int fim, int inicio){
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

        quickSortString(vetor, dir-1, inicio);
        quickSortString(vetor, fim, dir+1);   
    }
}

void insertionSort(int* vetor, int fim, int inicio){
    int ii, jj; 
    int chave;

    for (ii = 1; ii <= fim; ii++){
        chave = vetor[ii];
        jj = ii - 1;

        while ((jj >= 0) && (chave < vetor[jj])){
            vetor[jj + 1] = vetor[jj];
            jj = jj - 1;
        }
        vetor[jj + 1] = chave;
    }
}
void quickSort(int *vet, int esq, int dir){

    int pivo = esq, i,ch,j;         //Declaração das variavés e inicialização do pivo com o primeiro algarismo da sequencia

    for(i=esq+1;i<=dir;i++){        //Percorre todos os espaços do vetor

        j = i;                      //atribuição de valor

        if(vet[j] < vet[pivo]){     //verifica se o vetor da posição pivo é maior que de outra posição

         ch = vet[j];               //ch recebe o valor que é menor

         while(j > pivo){           //repeti enquanto o j que é a posição do algarismo menor que o pivo ficar na posição 0

            vet[j] = vet[j-1];      //reorganiza a posição de vetores

            j--;                    //decremento para a organização

         }

         vet[j] = ch;               // atribuição da variavel menor que o pivo na posição inicial

         pivo++;                    // aumenta a posição do pivo em uma unidade

        }  

    }

    if(pivo-1 >= esq){              // verifica se o valor do pivo é maior que o final do vetor.

        quickSort(vet,esq,pivo-1);      //final da execursão da função

    }

    if(pivo+1 <= dir){              //verifica se o valor do pivo é menor, indicando que ainda estar dentro das limitações do vetor

        quickSort(vet,pivo+1,dir);      //chama a função para eecutar novamente

    }

 }

void selection_sort(int num[], int tam) 
{ 
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++) 
  {
     min = i;
     for (j = (i+1); j < tam; j++) {
       if(num[j] < num[min]) 
         min = j;
     }
     if (i != min) {
       aux = num[i];
       num[i] = num[min];
       num[min] = aux;
     }
  }
}

void ordenarTextoInsertion(char* argv){
        ifstream infile;
       
        infile.open(argv);

        if (!infile.is_open())
            cout << "Arquivo não encotrado" << endl;
        
        else{
            ofstream outfile;
            outfile.open(argv);
            string palavras[MAXPALAVRAS];
            int ii;

            for(ii=0; infile >> palavras[ii]; ii++)
                //cout << palavras[ii] << endl;

            insertionSortString(palavras, ii, 0);
            //quickSort(palavras, ii, 0);
            //ordenaTexto( palavras, ii, 0, selecionaFuncao(1));
            //ordenaTexto(palavras, ii, 0, pFuncao);

            for(int jj=0; jj < ii; jj++)
                outfile << palavras[jj] << endl;
        }
    }

void ordenarTextoQuick(char* argv){

    ifstream infile;
    
    infile.open(argv);

    if (!infile.is_open())
        cout << "Arquivo não encotrado" << endl;
    
    else{
        ofstream outfile;
        outfile.open(argv);
        string palavras[MAXPALAVRAS];
        int ii;

        for(ii=0; infile >> palavras[ii]; ii++)
            //cout << palavras[ii] << endl;

        //insertionSort(palavras, ii, 0);
        quickSortString(palavras, ii, 0);
        //ordenaTexto( palavras, ii, 0, selecionaFuncao(1));
        //ordenaTexto(palavras, ii, 0, pFuncao);

        for(int jj=0; jj < ii; jj++)
            outfile << palavras[jj] << endl;
    }
}

void ordenarTextoSelection(char* argv){
    ifstream infile;
    infile.open(argv);

    if (!infile.is_open())
        cout << "Arquivo não encotrado" << endl;
    
    else{
        ofstream outfile;
        outfile.open(argv);
        string palavras[MAXPALAVRAS];
        int ii;

        for(ii=0; infile >> palavras[ii]; ii++)
            //cout << palavras[ii] << endl;

        //insertionSort(palavras, ii, 0);
        //quickSort(palavras, ii, 0);
        //ordenaTexto( palavras, ii, 0, selecionaFuncao(1));
        //ordenaTexto(palavras, ii, 0, pFuncao);

        for(int jj=0; jj < ii; jj++)
            outfile << palavras[jj] << endl;
    }
}
