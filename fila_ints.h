#ifndef FILA_INTEIROS
#define FILA_INTEIROS

typedef struct no NO;

typedef struct fila_int Fila_int;

Fila_int *cria_fila(void);

static int fila_vazia(Fila_int *f);

void append_fila(Fila_int *f, long int elem);

long int quant_elementos_fila(Fila_int *f);

long int retorna_o_primeiro_f(Fila_int *f);

void libera_fila(Fila_int *f);

void imprime_fila(Fila_int *f);

void retira_da_fila(Fila_int *f);

#endif