//
// Created by nicholas on 31/12/17.
//

#include "exit.hpp"
#include "render.hpp"
#include <fstream>
#include <stdlib.h>

//Arquivos de Configuração
FILE *arq = fopen("hand.conf", "rt");
int tempoAtivoSegundos = 0;
char arqRead;
FILE *arqNumberTeste = fopen("resultados//NumberTeste.txt", "rt");
char numberTesteArray[10];
int numberTeste;
FILE *arqResultadoTestes = fopen("resultados//Resultados.txt", "a");
std::string resultadoTestes;

void sairPrincipal() {
    fgets(numberTesteArray, 10, arqNumberTeste);
    numberTeste = strtol(numberTesteArray, NULL, 10);
    resultadoTestes = "\nID: " + std::to_string(numberTeste) + " | Tempo: " + std::to_string(tempoAtivoSegundos) +
                      " segundos | ";
    if (levelImage == 0) {
        resultadoTestes += "Fase 1: No | Fase 2: No | Fase 3: No";
    }
    else if (levelImage == 1) {
        resultadoTestes += "Fase 1: Sim | Fase 2: No | Fase 3: No";
    }
    else if (levelImage == 2) {
        resultadoTestes += "Fase 1: Sim | Fase 2: Sim | Fase 3: No";
    }
    else if (levelImage == 3) {
        resultadoTestes += "Fase 1: Sim | Fase 2: Sim | Fase 3: Sim";
    }

    //Gravando dados em novo arquivo
    fputs(resultadoTestes.c_str(), arqResultadoTestes);
    fclose(arqResultadoTestes);

    //Mudando ID
    numberTeste += 1;
    fclose(arqNumberTeste);

    FILE *arqNumberTeste = fopen("resultados//NumberTeste.txt", "wt");
    //_itoa(numberTeste, numberTesteArray, 10);
    sprintf(numberTesteArray,"%d",numberTeste);
    fputs(numberTesteArray, arqNumberTeste);
    fclose(arqNumberTeste);
    fcloseall();
    exit(0);
}

void sairEsc(unsigned char key, int x, int y) {
    if (key == 27) {
        sairPrincipal();
    }
    if (key == 32 && tut < 4) {

        tut = 5;
        start = false;
        againTime = false;
        hover = false;
    }
}

void TempoAtivo (int value) {
    tempoAtivoSegundos = tempoAtivoSegundos+1;
    glutTimerFunc(1000, TempoAtivo, 1);
}