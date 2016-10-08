#include <iostream>
using namespace std;

void insertionSort(int* vetor, int fim, int inicio){
    int ii, jj; 
    int chave;
    cout << "insertion" << endl; 

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

/*
Função para trocar elementos do vetor
*/
void troca (int vetor[], int esq, int dir){
    int aux = vetor[esq];
    vetor[esq] = vetor[dir];
    vetor[dir] = aux;
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