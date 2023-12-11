#ifndef PACIENTE_H
#define PACIENTE_H
#include <stdio.h>

typedef struct paciente Paciente;

Paciente *cria_paciente(const char *n, const char *c, unsigned long int identificador, unsigned int i);

void imprime_paciente_info(Paciente *p);

void escreve_paciente_info(Paciente *p, FILE *file);

#endif