#ifndef EXAME_H
#define EXAME_H
#include <stdio.h>

typedef struct exame Exame;

Exame *cria_exame(unsigned long int i, unsigned long int inst_t, char *cond);

void imprime_exame(Exame *e);

void escreve_no_arquivo_exame_info(Exame *e, FILE *file);

#endif