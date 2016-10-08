// Algoritmo para ler ordenar palavras de um arquivo .txt
// Tony Freitas

#include <fstream>
#include <iostream>
#include <string>
//#include <stdio.h>
//#include <string.h>
//#include "tarefa5.hpp"

using namespace std;

int main (int argc, char* argv[]){

    if (argc < 3 || argc > 4){
        cout << "QUANTIDADE DE PARÂMETROS DE ENTRADA INCORRETA" << endl;
        return 1;
    }

    if (argc == 3){

        ifstream infile;
        infile.open(argv[1]);

        if (!infile.is_open())
            cout << "Arquivo não encotrado" << endl;
        
        else{
            ofstream outfile;
            outfile.open(argv[2]);
            string palavras[MAXPALAVRAS];
            int ii;

            for(ii=0; infile >> palavras[ii]; ii++)
                //cout << palavras[ii] << endl;

            insertionSort(palavras, ii, 0);
            //quickSort(palavras, ii, 0);
            //ordenaTexto( palavras, ii, 0, selecionaFuncao(1));
            //ordenaTexto(palavras, ii, 0, pFuncao);

            for(int jj=0; jj < ii; jj++)
                cout << palavras[jj] << endl;
        }
    }
    return 0; 
}