#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "lista_encadeada_generica.h"
#include "fila_ints.h"
#include "paciente.h"
#include "exame.h"
#include "gerador_cpfs.h"
#include "log.h"

#define PACIENTE 0
#define EXAME 1
#define LOG 2

int main(void) {
    Paciente *pac;

    Exame *exm;
    
    LogEvent *evento;
    
    Fila_int *fila_exame = cria_fila();
    
    Fila_int *fila_ids = cria_fila(), *fila_ids2 = cria_fila();

    Lista_generica *lista_pacientes = cria_lista(), *fila_laudo = cria_lista(), *logging = cria_lista();
    
    unsigned long int i = 0, j = 0;
    
    long int t_total_br = 0, t_total_pn = 0, t_total_ff = 0, t_total_ap = 0, t_total_ld = 0;
    
    int condicoes[] = {1,1,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,5,5,5};
    
    long int *condicao, radiologistas[] = {-1, -1, -1}, *vetor_tempos, *vetor_tempos2, *vetor_tempos3, x, y;
    
    long int aparelhos[] = {-1, -1, -1, -1, -1}, n_pac_br, n_pac_pn, n_pac_ff, n_pac_ap;
    
    condicao = (long int *) malloc(9000 * sizeof(long int));
    
    vetor_tempos = (long int *) malloc(9000 * sizeof(long int));
    
    vetor_tempos2 = (long int *) malloc(9000 * sizeof(long int));
    
    vetor_tempos3 = (long int *) malloc(9000 * sizeof(long int));
    
    srand(time(NULL));
    
    for(i = 0; i < 9000; i++) {
        vetor_tempos[i] = -1;
        condicao[i] = -1;
        vetor_tempos2[i] = -1;
        vetor_tempos3[i] = -1;
    }
    
    i = 0;
    
    
    
    while(i < 43200) {
        
        //a probabilidade de chegar um paciente eh de 20%
        if(rand() % 5 == 0) {
            // um registro do paciente eh criado
            pac = cria_paciente("Fulano de Tal", converte_cpf_para_string_formatado(gera_cpf_valido((rand() % 9) + 1)), j, rand() % 100);
            
            //o registro eh adicionado a uma lista de pacientes
            append_lista(lista_pacientes, pac, PACIENTE);
            
            //o id do paciente eh adicionado a fila de exame
            append_fila(fila_exame, j);
            
            append_fila(fila_ids, j);
            
            evento = create_log_event("Chegada de paciente");
            
            append_lista(logging, evento, LOG);
            
            j++;
            
        }
        
        
        //checa se ha aparelho disponivel
        for(x = 0; (x < 5) && (aparelhos[x] != -1); x++);
        
        //se tem alguem na fila esperando para ser atentido e aparelho disponivel...
        if((x < 5) && (quant_elementos_fila(fila_ids) > 0)) {
            //ocupa o aparelho x com o primeiro da fila
            aparelhos[x] = retorna_o_primeiro_f(fila_ids);
            
            //identifica a condicao do paciente e coloca no vetor 'condicao'
            condicao[retorna_o_primeiro_f(fila_ids)] = condicoes[rand() % 20];
            
            //o tempo de duracao exame eh inserido na posicao 'id' do paciente
            vetor_tempos[retorna_o_primeiro_f(fila_ids)] = (rand() % 6) + 5;
            
            //retira o primeiro que estava esperando para fazer o exame
            retira_da_fila(fila_ids);
            
            evento = create_log_event("Inicio do exame");
            
            append_lista(logging, evento, LOG);
            
        }
        
        //hora de checar se o exame ja acabou
        for(x = 0; x <= j; x++) {
            //checa se o exame acabou
            if(vetor_tempos[x] == 0) {
                //checa se a condicao do paciente eh normal
                if(condicao[x] == 1) {
                    //se for normal, as informacoes do exame sao criadas passando a condicao Normal
                    exm = cria_exame(x, i, "Normal");
                }
                
                else{
                    //se nao for normal, as informacoes do exame sao criadas passando a condicao Patologica
                    exm = cria_exame(x, i, "Patologica");
                }
                
                //adiciona o registro do exame na fila de laudos
                append_lista(fila_laudo, exm, EXAME);
                
                //desocupa o aparelho apos o termino do exame
                y = 0;
                
                while((y < 5) && (aparelhos[y] != x)) {
                    y++;
                    
                }
                
                if(aparelhos[y] == x) {
                    aparelhos[y] = -1;
                }
                
                append_fila(fila_ids2, x);
                
                //instante de tempo que paciente de id 'x' saiu do exame
                vetor_tempos3[x] = i;
                
                evento = create_log_event("Fim do exame");
                
                append_lista(logging, evento, LOG);
                
            }
        
        }
        
        //fim da checagem
        
        //checa se ha radiologista disponivel
        for(x = 0; (x < 3) && (radiologistas[x] != -1); x++);
        
        //se tem alguem na fila esperando para ser atentido e radiologista disponivel...        
        if((x < 3) && (quant_elementos_fila(fila_ids2) > 0)) {
            //o radiologistas x atende o primeiro da fila
            radiologistas[x] = retorna_o_primeiro_f(fila_ids2);
            
            //o tempo de duracao da preparacao do laudo eh inserido na posicao 'id' do paciente
            vetor_tempos2[retorna_o_primeiro_f(fila_ids2)] = (rand() % 21) + 10;
            
            //retira o primeiro que estava esperando para fazer o laudo
            retira_da_fila(fila_ids2);
            
            evento = create_log_event("Inicio do laudo");
            
            append_lista(logging, evento, LOG);
            
        }
        
        //hora de checar se o laudo ja acabou
        for(x = 0; x <= j; x++) {
            //se laudo acabou
            if(vetor_tempos2[x] == 0) {
                //desocupa o radiologista apos o termino do laudo
                y = 0;
                
                while((y < 3) && (radiologistas[y] != x)) {
                    y++;
                }
                
                if(radiologistas[y] == x) {
                    radiologistas[y] = -1;
                }
                
                //calcula a diferenca de tempo que o exame demorou para receber um laudo
                vetor_tempos3[x] = i - vetor_tempos3[x];
                
                evento = create_log_event("Fim do laudo");
                
                append_lista(logging, evento, LOG);
                
            }
            
        }
        //fim da checagem
        
        //hora de calcular as metricas
        if((i % 100 == 0) && (i != 0)) {
            y = 0;
            t_total_ld = 0;
            
            //vai somando os tempos gastos para as preparacao do laudos dos pacientes apos eles sairem do exame
            for(x = 0; x <= j; x++) {
                if(vetor_tempos3[x] > -1) {
                    t_total_ld += vetor_tempos3[x];
                    
                    if(vetor_tempos3[x] > 7200) {
                        y++;
                    }
                }
                
            }
            
            t_total_br = 0;
            n_pac_br = 0;
            
            t_total_pn = 0;
            n_pac_pn = 0;
            
            t_total_ff = 0;
            n_pac_ff = 0;
            
            t_total_ap = 0;
            n_pac_ap = 0;
            
            //vai somando os tempos gastos para as preparacao do laudos dos pacientes apos eles sairem do exame para cada patologia
            for(x = 0; x <= j; x++) {
                if(condicao[x] == 2) {
                    t_total_br += vetor_tempos3[x];
                    n_pac_br++;
                        
                }
                    
                if(condicao[x] == 3) {
                    t_total_pn += vetor_tempos3[x];
                    n_pac_pn++;
                        
                }
                    
                if(condicao[x] == 4) {
                    t_total_ff += vetor_tempos3[x];
                    n_pac_ff++;
                }
                    
                if(condicao[x] == 5) {
                    t_total_ap += vetor_tempos3[x];
                    n_pac_ap++;
                }
                
            }
            
            printf("\n\nTEMPO MEDIO PARA LAUDO: %.2f", (float) t_total_ld / (j + 1));
            
            if(n_pac_br != 0) {
                printf("\n\nTEMPO MEDIO PARA LAUDO BRONQUITE: %.2f", (float) t_total_br / n_pac_br);
                
            }
            
            if(n_pac_pn != 0) {
                printf("\n\nTEMPO MEDIO PARA LAUDO PNEUMONIA: %.2f", (float) t_total_pn / n_pac_pn);
                
            }
            
            if(n_pac_ff != 0) {
                printf("\n\nTEMPO MEDIO PARA LAUDO FRATURA NO FEMUR: %.2f", (float) t_total_ff / n_pac_ff);
                
            }
            
            if(n_pac_ap != 0) {
                printf("\n\nTEMPO MEDIO PARA LAUDO APENDICITE: %.2f", (float) t_total_ap / n_pac_ap);
                
            }
            
            printf("\n\nQUANTIDADE DE EXAMES REALIZADOS APOS O LIMITE DE TEMPO ESTABELECIDO: %li", y);
            
            printf("\n...............................................................................................................");
            
            sleep(1);
            
        }
        
        
        if(j > 9000) {
            condicao = realloc(condicao, 18000 * sizeof(long int));
            vetor_tempos = realloc(vetor_tempos, 18000 * sizeof(long int));
            vetor_tempos2 = realloc(vetor_tempos2, 18000 * sizeof(long int));
            vetor_tempos3 = realloc(vetor_tempos3, 18000 * sizeof(long int));
            
            if(j > 18000) {
                condicao = realloc(condicao, 36000 * sizeof(long int));
                vetor_tempos = realloc(vetor_tempos, 36000 * sizeof(long int));
                vetor_tempos2 = realloc(vetor_tempos2, 36000 * sizeof(long int));
                vetor_tempos3 = realloc(vetor_tempos3, 36000 * sizeof(long int));
            }
            
        }
        
        //vai descontando uma unidade de tempo da duracao do exame e da preparacao do laudo do radiologista
        for(x = 0; x <= j; x++) {
            vetor_tempos[x] = vetor_tempos[x] - 1;
            vetor_tempos2[x] = vetor_tempos2[x] - 1;
            
        }
        

        
        i++;
    
    }
    
    escreve_lista_no_arquivo(logging, "log");
    
    
    free(condicao);
    free(vetor_tempos);
    free(vetor_tempos2);
    free(vetor_tempos3);
    

    libera_lista(lista_pacientes);

    libera_lista(fila_laudo);
    
    libera_fila(fila_exame);
    
    libera_fila(fila_ids);
    
    libera_fila(fila_ids2);
    
    libera_lista(logging);
    

    return 0;
}