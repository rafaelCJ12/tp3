#include <stdio.h>
#include <stdlib.h>
#include "fila_ints.h"

struct no {
    long int info;
    
    struct no *next;
       
};

struct fila_int{
    NO *inicio;
    
    NO *fim;
    
};

Fila_int *cria_fila(void) {
    Fila_int *f = (Fila_int *) malloc(sizeof(Fila_int));
    
    f -> inicio = NULL;
    
    f -> fim = NULL;
    
    return f;
}

static int fila_vazia(Fila_int *f) {
    return f -> inicio == NULL;
}

void append_fila(Fila_int *f, long int elem) {
    NO *novo = (NO *) malloc(sizeof(NO));
    
    novo -> info = elem;
    novo -> next = NULL;
    
    if(fila_vazia(f)) {
        f -> inicio = novo;
        f -> fim = novo;
    }
    
    else {
        f -> fim -> next = novo;
        f -> fim = novo;
    }
}

long int quant_elementos_fila(Fila_int *f) {
    long int contador = 0;
    
    NO *p = f -> inicio;
    
    while(p != NULL) {
        contador++;
        
        p = p -> next;
    }
    
    return contador;
}

long int retorna_o_primeiro_f(Fila_int *f) {
    if(f -> inicio == NULL) {
        return -1;
    }
    
    return f -> inicio -> info;
}

void libera_fila(Fila_int *f) {
    NO *p = f -> inicio, *q;
    
    while(p != NULL) {
        q = p -> next;
        
        free(p);
        
        p = q;
    }
    
    free(f);
    
}

void imprime_fila(Fila_int *f) {
    NO *p = f -> inicio;

    while(p != NULL) {
        printf("%li ", p -> info);

        p = p -> next;
    }
}

void retira_da_fila(Fila_int *f) {
    NO *p = f -> inicio;
    
    f -> inicio = p -> next;
    
    free(p);
}
