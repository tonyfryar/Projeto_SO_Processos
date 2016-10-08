/*
 * Universidade Federal do Rio Grande do Norte
 * Instituto Metropole Digital
 *
 * copyright: Ivanovitch Silva
 * e-mail: ivan@imd.ufrn.br
 *
 * Tópico: tratando sinais no linux
 * Programa: IPC através da função kill
 */
#include <fstream>
#include <iostream>
#include <string>

#include <sys/types.h>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <csignal>
#include <chrono>
#include <cstring>
#include "funcoesOrdenacao.h"
using namespace std;
using namespace std::chrono;

 int* vetor = new int[10000000];


int main(int argc, char* argv[])
{ 
    if (argc < 3|| argc > 0){
        cout << "QUANTIDADE DE PARÂMETROS DE ENTRADA INCORRETA" << endl;
        return 1;
    }

    if (argc == 1){
    // Identificador do processo
    pid_t idProcesso;
    printf("Iniciando o programa\n\n");
     for(int i = 0; i<10000000; i++){
        vetor[i] = i*rand();
      }
    // Criando o processo
    idProcesso = fork();
    
    switch(idProcesso){
      case -1:       // erro na abertura do processo filho
        exit(1);
      case 0:
                
        while(1){    // retorno de fork para processo filho
          int* vetorFilho = new int[10000000];
          for(int i = 0 ; i < 10000000; i++){
                    vetorFilho[i] = vetor[i];
          }

          high_resolution_clock::time_point t1 = high_resolution_clock::now();
          insertionSort(vetorFilho,8,0);
          //for(int i = 0 ; i < 10000000; i++){
          //          cout<<vetorFilho[i]<<endl;
          //}
          high_resolution_clock::time_point t2 = high_resolution_clock::now(); // fim da medição
          auto duracao = duration_cast<nanoseconds>(t2-t1).count();
          cout<<"Insertion Sort:"<<endl;
          cout<<"Tempo de duracao do algoritmo: "<<duracao<<" ns"<<endl;
        
          printf("Sou o processo filho 1 ID: %d, pai ID: %d\n", getpid(), getppid());
          printf("----------------------------------------------------------------------------\n");
          sleep(5);
        }
        break;
      default:	// processo pai
        
        while(1){
          printf("Sou o processo pai com ID: %d, pai ID: %d, filho ID: %d\n\n", getpid(), getppid(),idProcesso);
          sleep(1);
          idProcesso = fork(); // inicia o pai e filho 2

            switch(idProcesso){
              case -1:
                exit(1);
              case 0:
                while(1){
                  int* vetorFilho2 = new int[10000000];
                  for(int i = 0 ; i < 10000000; i++){
                    vetorFilho2[i] = vetor[i];
                  }

                  high_resolution_clock::time_point t1 = high_resolution_clock::now();
                  quickSort(vetorFilho2,0,8);
                  //for(int i =0 ; i < 9; i++){
                  //  cout<<vetorFilho2[i]<<endl;
                  //}
                  high_resolution_clock::time_point t2 = high_resolution_clock::now(); // fim da medição
                  auto duracao = duration_cast<nanoseconds>(t2-t1).count();
                  cout<<"Quick Sort:"<<endl;
                  cout<<"Tempo de duracao do algoritmo: "<<duracao<<" ns"<<endl;
                  printf("Sou o processo filho 2 ID: %d, pai ID: %d\n", getpid(), getppid());
                  printf("----------------------------------------------------------------------------\n");
                  sleep(5);
                }
                break;
              default:
                int cont = 0;
                while(1){
                  int *vetorPai = new int[10000000];
                  for(int i =0 ; i<10000000;i++){
                  vetorPai[i] = vetor[i];
                  }
                  high_resolution_clock::time_point t1 = high_resolution_clock::now();
                  selection_sort(vetorPai,9);
                  //for(int i =0 ; i < 9; i++){
                  // cout<<vetorPai[i]<<endl;
                  //}
                  high_resolution_clock::time_point t2 = high_resolution_clock::now(); // fim da medição
                  auto duracao = duration_cast<nanoseconds>(t2-t1).count();
                  cout<<"Selection Sort:"<<endl;
                  cout<<"Tempo de duracao do algoritmo: "<<duracao<<" ns"<<endl;
                  printf("Sou o processo pai  com ID: %d, pai ID: %d, filho ID: %d\n", getpid(), getppid(),idProcesso);
                  printf("----------------------------------------------------------------------------\n");
                  sleep(5);
                
                }
            }
        }
        break;
    }
  }
    if (argc == 2){
      pid_t idProcesso;
      printf("Iniciando o programa\n\n");
      
    // Criando o processo
    idProcesso = fork();
    
    switch(idProcesso){
      case -1:       // erro na abertura do processo filho
        exit(1);
      case 0:
                
        while(1){    // retorno de fork para processo filho
          high_resolution_clock::time_point t1 = high_resolution_clock::now();
          ordenarTextoInsertion(argv[1]);
          high_resolution_clock::time_point t2 = high_resolution_clock::now(); // fim da medição
          auto duracao = duration_cast<nanoseconds>(t2-t1).count();
          cout<<"Insertion Sort:"<<endl;
          cout<<"Tempo de duracao do algoritmo: "<<duracao<<" ns"<<endl;
        
          printf("Sou o processo filho 1 ID: %d, pai ID: %d\n", getpid(), getppid());
          printf("----------------------------------------------------------------------------\n");
          sleep(5);
        }
        break;
      default:  // processo pai
        
        while(1){
          printf("Sou o processo pai com ID: %d, pai ID: %d, filho ID: %d\n\n", getpid(), getppid(),idProcesso);
          sleep(1);
          idProcesso = fork(); // inicia o pai e filho 2

            switch(idProcesso){
              case -1:
                exit(1);
              case 0:
                while(1){
                  

                  high_resolution_clock::time_point t1 = high_resolution_clock::now();
                  ordenarTextoQuick(argv[1]);
                  high_resolution_clock::time_point t2 = high_resolution_clock::now(); // fim da medição
                  auto duracao = duration_cast<nanoseconds>(t2-t1).count();
                  cout<<"Quick Sort:"<<endl;
                  cout<<"Tempo de duracao do algoritmo: "<<duracao<<" ns"<<endl;
                  printf("Sou o processo filho 2 ID: %d, pai ID: %d\n", getpid(), getppid());
                  printf("----------------------------------------------------------------------------\n");
                  sleep(5);
                }
                break;
              default:
                
                while(1){
                  
                  high_resolution_clock::time_point t1 = high_resolution_clock::now();
                  //ordernarTextoSelection(argv[1]);
                  high_resolution_clock::time_point t2 = high_resolution_clock::now(); // fim da medição
                  auto duracao = duration_cast<nanoseconds>(t2-t1).count();
                  cout<<"Selection Sort:"<<endl;
                  cout<<"Tempo de duracao do algoritmo: "<<duracao<<" ns"<<endl;
                  printf("Sou o processo pai  com ID: %d, pai ID: %d, filho ID: %d\n", getpid(), getppid(),idProcesso);
                  printf("----------------------------------------------------------------------------\n");
                  sleep(5);
                
                }
            }
        }
        break;
    }
  }
    return 0; 
}
