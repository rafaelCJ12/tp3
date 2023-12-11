#ifndef LOG_H
#define LOG_H
#include <stdio.h>

typedef struct logEvent LogEvent;

LogEvent *create_log_event(const char *message);

void imprime_log(LogEvent *l);

void escreve_no_arquivo_log(LogEvent *l, FILE *file);

#endif