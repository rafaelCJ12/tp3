#ifndef GERADOR_CPFS
#define GERADOR_CPFS

int verifica_cpf(long unsigned int cpf);

long unsigned int gera_cpf_valido(unsigned int primeiro_digito);

char* converte_cpf_para_string(long unsigned int cpf);

char* converte_cpf_para_string_formatado(long unsigned int cpf);

#endif