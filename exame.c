#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exame.h"

struct exame
{
    unsigned long int id;

    unsigned long int instante_tempo;

    char condicao[11];


};

Exame *cria_exame(unsigned long int i, unsigned long int inst_t, char *cond) {
    Exame *e = (Exame *) malloc(sizeof(Exame));

    e -> id = i;
    e -> instante_tempo = inst_t;
    strcpy(e -> condicao, cond);

    return e;

}

void imprime_exame(Exame *e) {
    printf("\n\nID DO PACIENTE: %li\n\n", e -> id);
    printf("INSTANTE DE TEMPO EM QUE O REGISTRO FOI GERADO: %li\n\n", e -> instante_tempo);
    printf("CONDICAO DO PACIENTE: %s\n\n", e -> condicao);
}

void escreve_no_arquivo_exame_info(Exame *e, FILE *file) {
    fprintf(file, "\n\nID DO PACIENTE: %li\n\n", e -> id);
    fprintf(file, "INSTANTE DE TEMPO EM QUE O REGISTRO FOI GERADO: %li\n\n", e -> instante_tempo);
    fprintf(file, "CONDICAO DO PACIENTE: %s\n\n", e -> condicao);
    
    
}



