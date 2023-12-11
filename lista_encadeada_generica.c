#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada_generica.h"
#include "paciente.h"
#include "exame.h"
#include "log.h"

#define PACIENTE 0
#define EXAME 1
#define LOG 2

struct no {
    int tipo;
    
    void *info;
    
    struct no *next;
       
};

struct lista_generica{
    NO *inicio;
    
    NO *fim;
    
};

Lista_generica *cria_lista(void) {
    Lista_generica *l = (Lista_generica *) malloc(sizeof(Lista_generica));
    
    l -> inicio = NULL;
    
    l -> fim = NULL;
    
    return l;
}

static int lista_vazia(Lista_generica *l) {
    return l -> inicio == NULL;
}

void append_lista(Lista_generica *l, void *elem, int t) {
    NO *novo = (NO *) malloc(sizeof(NO));
    
    novo -> tipo = t;
    novo -> info = elem;
    novo -> next = NULL;
    
    if(lista_vazia(l)) {
        l -> inicio = novo;
        l -> fim = novo;
    }
    
    else {
        l -> fim -> next = novo;
        l -> fim = novo;
    }
}


long int quantidade_elementos_lista(Lista_generica *l) {
    int contador  = 0;
    
    NO *p = l -> inicio;
    
    while(p != NULL) {
        contador++;
        
        p = p -> next;
    }
    
    return contador;
}

void libera_lista(Lista_generica *l) {
    NO *p = l -> inicio, *q;
    
    while(p != NULL) {
        q = p -> next;
        
        free(p);
        
        p = q;
    }
    
    free(l);
    
}

void imprime_lista(Lista_generica *l) {
    NO *p = l -> inicio;

    while(p != NULL) {
        if(p-> tipo == PACIENTE) {
            imprime_paciente_info(p -> info);
        }

        if(p-> tipo == EXAME) {
            imprime_exame(p -> info);
        }
        
        if(p -> tipo == LOG) {
            imprime_log(p -> info);
        }

        p = p -> next;
    }

}

void escreve_lista_no_arquivo(Lista_generica *l, const char *filename) {
    NO *p = l -> inicio;
    
    // Open the file for writing
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
        return;
    }
    
    while(p != NULL) {
        if(p-> tipo == PACIENTE) {
            escreve_paciente_info(p -> info, file);
        }

        if(p-> tipo == EXAME) {
            escreve_no_arquivo_exame_info(p -> info, file);
        }
        
        if(p -> tipo == LOG) {
            escreve_no_arquivo_log(p -> info, file);
        }

        p = p -> next;
    }
    
    fclose(file);
}

void retira_o_primeiro(Lista_generica *l) {
    NO *p = l -> inicio;
    
    l -> inicio = p -> next;
    
    free(p);
    
}

