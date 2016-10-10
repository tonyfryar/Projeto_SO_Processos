/*
 * Universidade Federal do Rio Grande do Norte
 * Instituto Metropole Digital
 *
 * copyright: Carlos Jośe, Diogo Vitor, Tony Freitas
 *
 * Tópico: Análise de desempenho de algoritmos de ordenação em diferentes processos simultâneos
 * Programa: NULL
 */
#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
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

//Funcao signal handler responsavel por tratar o alarme
void detectarAlarme (int sig){
  printf("O sinal %d foi recebido: SIGALRM\n", sig);
  printf("Vontando para o programa principal\n");
  printf("----------------------------------------------------------------------------\n");
  kill(getpid(),SIGTERM);
}

void help(){
  printf("...Análise de desempenho de algoritmos de ordenação em diferentes processos simultâneos...\n\nPara executar o programa temos duas opções:\n");
  printf("1- ./executavel\n2- ./executavel QualquerArquivo.txt\n");
}

int main(int argc, char* argv[]){

	if (argc > 2 ){
		cout << "QUANTIDADE DE PARÂMETROS DE ENTRADA INCORRETA, PARA AJUDA: ./executavel help" << endl;
    	return 1;
  	}
  	//Trabalhando com ordenações de inteiros
  	else if (argc == 1){
  		printf("Iniciando o programa\n\n");

    	//Identificador do processo
    	pid_t idProcesso;

    	// Instalar o tratamento do alarme
    	signal(SIGALRM,detectarAlarme);

    	//Inicializando o vetor de inteiros
    	int* vetor = new int[64000];

    	//Atribuindo valores randomicos ao vetor
    	for(int i = 0; i<64000; i++){
    		vetor[i] = i*rand();
    	}
    
    	//Criando o processo
    	idProcesso = fork();
    
    	switch(idProcesso){
      		case -1:       //Erro na abertura do processo filho
      		exit(1);

      		case 0:
        	while(1){    //Retorno de fork para processo filho
        		unsigned int tempoRestanteAlarmeAnterior;
          		int* vetorFilho = new int[64000];
          		for(int i = 0 ; i < 64000; i++){
            		vetorFilho[i] = vetor[i];
          		}
          		//Tratamento da função que cronometra o tempo
          		high_resolution_clock::time_point t1 = high_resolution_clock::now();
          		tempoRestanteAlarmeAnterior = alarm(5); //Colocando o alarme pra funcionar após 2 seg
          		insertionSort(vetorFilho,64000,0);
          		//for(int i = 0 ; i < 64000; i++){
          		//		cout<<vetorFilho[i]<<endl;
          		//}
          		high_resolution_clock::time_point t2 = high_resolution_clock::now(); // fim da medição
          		auto duracao = duration_cast<nanoseconds>(t2-t1).count();
          		cout<<"Insertion Sort:"<<endl;
          		cout<<"Tempo de duracao do algoritmo: "<<duracao<<" ns"<<endl;
        
          		printf("Sou o processo filho 1 ID: %d, pai ID: %d\n", getpid(), getppid());
          		printf("----------------------------------------------------------------------------\n");
          		sleep(1);
        	}
       		break;
        	default: //processo pai   
        	while(1){
        		printf("Sou o processo pai com ID: %d, pai ID: %d, filho ID: %d\n\n", getpid(), getppid(),idProcesso);
          		sleep(1);
          		idProcesso = fork(); //Inicia o pai e filho 2
          		switch(idProcesso){
            		case -1:
              		exit(1);

            		case 0:
            		while(1){
            			unsigned int tempoRestanteAlarmeAnterior2;
              			int* vetorFilho2 = new int[64000];
              			for(int i = 0 ; i < 64000; i++){
                			vetorFilho2[i] = vetor[i];
              			}

              			//Tratamento da função que cronometra o tempo
              			high_resolution_clock::time_point t1 = high_resolution_clock::now();
              			tempoRestanteAlarmeAnterior2 = alarm(5); //Colocando o alarme pra funcionar após 2 seg
		            	selection_sort(vetorFilho2,64000);
		            	high_resolution_clock::time_point t2 = high_resolution_clock::now(); // fim da medição
		            	auto duracao = duration_cast<nanoseconds>(t2-t1).count();
		            	cout<<"Selection Sort:"<<endl;
		            	cout<<"Tempo de duracao do algoritmo: "<<duracao<<" ns"<<endl;
		            	printf("Sou o processo filho 2 ID: %d, pai ID: %d\n", getpid(), getppid());
		            	printf("----------------------------------------------------------------------------\n");
		            	sleep(1);
		        	}
		        	break;
		        	default:
		        	int cont = 0;
		        	while(1){
		        		unsigned int tempoRestanteAlarmeAnterior3;
              			int *vetorPai = new int[64000];
              			for(int i = 0 ; i < 64000; i++){
              				vetorPai[i] = vetor[i];
              			}

              			//Tratamento da função que cronometra o tempo
              			high_resolution_clock::time_point t1 = high_resolution_clock::now();
              			tempoRestanteAlarmeAnterior3 = alarm(5); //Colocando o alarme pra funcionar após 2 seg
              			quickSort(vetorPai,0,64000);
              			high_resolution_clock::time_point t2 = high_resolution_clock::now(); // fim da medição
              			auto duracao = duration_cast<nanoseconds>(t2-t1).count();
              			cout<<"Quick Sort:"<<endl;
              			cout<<"Tempo de duracao do algoritmo: "<<duracao<<" ns"<<endl;
              			printf("Sou o processo pai com ID: %d, pai ID: %d, filho ID: %d\n", getpid(), getppid(),idProcesso);
              			printf("----------------------------------------------------------------------------\n");
              			sleep(1);
            		}
          		}
        	}
        	break;
    	}
  	}
  	//Trabalhando com ordenações de strings
  	else if (argc == 2){
    	if(strcmp(argv[1],"help") == 0){
      		help();
    	}

    	else{
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
            		unsigned int tempoRestanteAlarmeAnterior4;
            		tempoRestanteAlarmeAnterior4 = alarm(5);
            		ordenarTextoInsertion(argv[1]);
            		high_resolution_clock::time_point t2 = high_resolution_clock::now(); // fim da medição
            		auto duracao = duration_cast<nanoseconds>(t2-t1).count();
            		cout<<"Insertion Sort:"<<endl;
            		cout<<"Tempo de duracao do algoritmo: "<<duracao<<" ns"<<endl;
          
            		printf("Sou o processo filho 1 ID: %d, pai ID: %d\n", getpid(), getppid());
            		printf("----------------------------------------------------------------------------\n");
            		sleep(1);;
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
              				//Tratamento da função que cronometra o tempo
                			high_resolution_clock::time_point t1 = high_resolution_clock::now();
                			unsigned int tempoRestanteAlarmeAnterior5;
                			tempoRestanteAlarmeAnterior5 = alarm(5);
                			ordenarTextoQuick(argv[1]);
                			high_resolution_clock::time_point t2 = high_resolution_clock::now(); // fim da medição
                			auto duracao = duration_cast<nanoseconds>(t2-t1).count();
                			cout<<"Quick Sort:"<<endl;
                			cout<<"Tempo de duracao do algoritmo: "<<duracao<<" ns"<<endl;
                			printf("Sou o processo filho 2 ID: %d, pai ID: %d\n", getpid(), getppid());
                			printf("----------------------------------------------------------------------------\n");
                			sleep(1);
              			}
              			break;
              			default:  
              			while(1){
              				//Tratamento da função que cronometra o tempo
                			high_resolution_clock::time_point t1 = high_resolution_clock::now();
                			unsigned int tempoRestanteAlarmeAnterior6;
                			tempoRestanteAlarmeAnterior6 = alarm(5);
                			//ordernarTextoSelection(argv[1]);
                			high_resolution_clock::time_point t2 = high_resolution_clock::now(); // fim da medição
                			auto duracao = duration_cast<nanoseconds>(t2-t1).count();
                			cout<<"Selection Sort:"<<endl;
                			cout<<"Tempo de duracao do algoritmo: "<<duracao<<" ns"<<endl;
                			printf("Sou o processo pai com ID: %d, pai ID: %d, filho ID: %d\n", getpid(), getppid(),idProcesso);
                			printf("----------------------------------------------------------------------------\n");
                			sleep(1);;                
              			}
            		}
          		}
        		break;
      		}
    	}
    }   
	return 0;
}
