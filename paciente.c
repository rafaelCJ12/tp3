#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"

struct paciente {
    unsigned long int id;
    
    unsigned int idade;
    
    char cpf[15];
    
    char nome[101];
    
    
};


Paciente *cria_paciente(const char *n, const char *c, unsigned long int identificador, unsigned int i) {
    Paciente *p = (Paciente *) malloc(sizeof(Paciente));
    
    strcpy(p -> nome, n);
    
    strcpy(p -> cpf, c);
    
    p -> id = identificador;
    
    p -> idade = i;
    
    return p;
}

void imprime_paciente_info(Paciente *p) {
    printf("\n\nNOME: %s\n\n", p -> nome);
    
    printf("CPF: %s\n\n", p -> cpf);
    
    printf("IDADE: %i\n\n", p -> idade);
    
    printf("ID: %li\n\n", p -> id);
}


void escreve_paciente_info(Paciente *p, FILE *file) {
    fprintf(file, "\n\nNOME: %s\n\n", p -> nome);
    fprintf(file, "CPF: %s\n\n", p -> cpf);
    fprintf(file, "IDADE: %i\n\n", p -> idade);
    fprintf(file, "ID: %li\n\n", p -> id);
    
}