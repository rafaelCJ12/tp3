#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "gerador_cpfs.h"

int verifica_cpf(long unsigned int cpf) {
    long unsigned int aux;
    
    int i = 0, acumulador = 0, multiplicador = 2;
    
    if(cpf < 10000000000) {
        return 0;
    }
    
    aux = cpf;
    
    while(i < 11) {
        if(i > 1) {
            acumulador += (aux % 10) * multiplicador;
            
            multiplicador++;
        }
        
        aux = (long unsigned int) aux / 10;
        
        i++;
    }
    
    aux = (long unsigned int) cpf / 10;
    
    if((acumulador % 11 == 0) || (acumulador % 11 == 1)) {
        if(aux % 10 != 0) {
            return 0;
        }
        
    }
    
    else {
        if(aux % 10 != 11 - (acumulador % 11)) {
            return 0;
        }
    }
    
    aux = cpf;
    
    i = 0;
    
    multiplicador = 2;
    
    acumulador = 0;
    
    while(i < 11) {
        if(i > 0) {
            acumulador += (aux % 10) * multiplicador;
            
            multiplicador++;
        }
        
        aux = (long unsigned int) aux / 10;
        
        i++;
    }
    
    aux = cpf;
    
    if((acumulador % 11 == 0) || (acumulador % 11 == 1)) {
        if(aux % 10 != 0) {
            return 0;
        }
        
    }
    
    else {
        if(aux % 10 != 11 - (acumulador % 11)) {
            return 0;
        }
    }
    
    return 1;
    
}

long unsigned int gera_cpf_valido(unsigned int primeiro_digito) {
    long unsigned int cpf = primeiro_digito * 10000000000;
    
    
    if((primeiro_digito <= 0) || (primeiro_digito > 9)) {
        return 0;
    }
    
    srand(time(NULL));
    
    while((cpf < ((primeiro_digito + 1) * 10000000000)) && !(verifica_cpf(cpf))) {
            cpf = (primeiro_digito * 10000000000) + rand() % 10000000000;
        }
        
    return cpf;
}

char* converte_cpf_para_string(long unsigned int cpf) {
    short int i;
    
    char *str_cpf = (char *) malloc(12 * sizeof(char)), lista_alg[] = "0123456789";
    
    for(i = 10; i > -1; i -= 1) {
        str_cpf[i] = lista_alg[cpf % 10];
    
        cpf = cpf / 10;
        
    }
    
    str_cpf[11] = '\0';
    
    return str_cpf;
    
}

char* converte_cpf_para_string_formatado(long unsigned int cpf) {
    short int i = 0, j = 0;
    
    char *str_cpf_f = (char *) malloc(15 * sizeof(char));
    
    char* str_cpf = converte_cpf_para_string(cpf);
    
    while(i < 14) {
        if((i == 3) || (i == 7) || (i == 11)) {
            if(i == 11) {
                str_cpf_f[i] = '-';
                
            }
            
            else{
                str_cpf_f[i] = '.';
            }
            
        }
        
        else{
            str_cpf_f[i] = str_cpf[j];
            j++;
        }
        
        i++;
        
    }
    
    str_cpf_f[14] = '\0';
    
    return str_cpf_f;
    
    
}