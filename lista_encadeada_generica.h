#ifndef LISTA_GENERICA
#define LISTA_GENERICA

typedef struct no NO;

typedef struct lista_generica Lista_generica;

Lista_generica *cria_lista(void);

static int lista_vazia(Lista_generica *l);

void append_lista(Lista_generica *l, void *elem, int t);

long int quantidade_elementos_lista(Lista_generica *l);

void libera_lista(Lista_generica *l);

void imprime_lista(Lista_generica *l);

void escreve_lista_no_arquivo(Lista_generica *l, const char *filename);

void retira_o_primeiro(Lista_generica *l);

#endif