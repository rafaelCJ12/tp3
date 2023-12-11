#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "log.h"

struct logEvent {
    char message[256];
    
    time_t timestamp;
    
};


LogEvent *create_log_event(const char *message) {
    LogEvent *novo_evento = (LogEvent *) malloc(sizeof(LogEvent));
    
    strcpy(novo_evento -> message, message);
    
    novo_evento -> timestamp = time(NULL);
    
    return novo_evento;
    
}

void imprime_log(LogEvent *l) {
    printf("%li ", l -> timestamp);
    printf("%s\n\n", l -> message);
}

void escreve_no_arquivo_log(LogEvent *l, FILE *file) {
    fprintf(file, "%li ", l -> timestamp);
    fprintf(file, "%s\n\n", l -> message);
}