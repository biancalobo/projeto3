#ifndef TAREFAS_H
#define TAREFAS_H

#define TOTAL 255
#define NOME 255
#define TELEFONE 255
#define INFORMACAO 255

typedef struct {
    char nome[NOME];
    int telefone;
    char informacao[INFORMACAO];
} Contato;

typedef enum {
    OK, ERRO_ADICIONAR, ERRO_LISTAR, ERRO_DELETAR, ERRO_SALVAR, ERRO_CARREGAR, CONTATO_INEXISTENTE, MAXIMO_CONTATOS, ERRO_ABRIR, ERRO_LER, ERRO_FECHAR, ERRO_ESCREVER
} ERROS;

typedef ERROS (*funcao)(Contato[], int*);

ERROS adicionar(Contato[], int*);
ERROS listar(Contato[], int*);
ERROS deletar(Contato[], int*);
ERROS salvar(Contato[], int*);
ERROS carregar(Contato[], int*);
ERROS alterar(Contato[], int*);



void clearBuffer();

#endif
