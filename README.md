# tp3

O trabalho tem como objetivo simular uma situação de exames em hospital e a geração de eventos significativos, tais como: a chegada de pacientes, o início/fim dos exames e o início/fim dos laudos. 

Para essa tarefa foram usadas algumas estruturas como: 
    1. Exame: uma estrutura que contém como informação o identificador do paciente, o instante de tempo em que o exame foi gerado e a condição do paciente. Ele conta com as funções de criação de exame, imprimir na tela e de imprimir em um arquivo.
    2. Paciente: essa estrutura possui como informações o identificador do paciente, a idade, o CPF e o nome do paciente. Ela é auxiliada pelas funções de criação de um registro de um paciente, de impressão desse registro na tela e de impressão desse registro em um arquivo.
    3. Log: uma estrutura que conta com dois campos: um que possui a mensagem de qual evento ocorreu (chegada de pacientes, o início/fim dos exames e o início/fim dos laudos) e o instante de tempo. Conta com funções de criação de um novo evento, de impressão do evento na tela e em um arquivo.
    4. Lista encadeada genérica: uma estrutura que é usada no contexto dessa simulação para armazenar as estruturas de exame, paciente e de log. Conta com funções de criar lista, de inserir no final, uma função que retorna a quantidade de elementos da lista, uma função de imprimir os elementos da lista na tela, uma de imprimir em um arquivo , uma que retorna o primeiro elemento da lista e uma função que libera a memória alocada para a lista.
    5. Fila de inteiros: uma estrutura que armazena números inteiros, usada nesse contexto para guardar valores de identificação de pacientes. É auxiliada por funções de criação de uma nova lista, de inserir no final da fila, de calcular a quantidade de elementos da fila, de imprimir a fila na tela, de retornar o primeiro elemento da fila, de retirar (o primeiro elemento) da fila e de liberar a memória na fila.

Também foi usada nesse trabalho uma biblioteca de minha autoria para manipulação de CPF’s. Essa biblioteca conta com funções de verificação de cpf (passando como parâmetro um valor do tipo long int entre 10000000000 e 99999999999) uma função que gera um valor de CPF válido passando como parâmetro um número entre 1 e 9 que será o primeiro algarismo e que retorna um número de CPF com o primeiro algarismo que foi passado.
Uma função que converte um CPF passado como long int e retorna esse CPF como string não formatada (ex:  10000000000 vira “10000000000”). E uma função que converte um CPF passado como long int e retorna esse CPF como string formatada (ex:  10000000000 vira “100.000.000-00”).

O arquivo main.c contém a função main que por sua vez possui a lógica da simulação. Existem comentários ao longo do código que explicam como entendi o problema proposto e como implementei sua lógica.
