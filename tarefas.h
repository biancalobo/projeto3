#define TAREFAS.H

#define TOTAL 255
#define NOME 255
#define TELEFONE 255

typedef struct {
    char nome[NOME];
    int telefone;

} Contato;

typedef enum {
OK, ERRO_ADICIONAR, ERRO_LISTAR, ERRO_DELETAR, ERRO_SALVAR, ERRO_CARREGAR, CONTATO_INEXISTENTE
} ERROS;


typedef ERROS (*funcao)(Contato[], int*);

ERROS adicionar(Contato[], int*);
ERROS listar(Contato[], int);
ERROS deletar(Contato[], int*);
ERROS salvar(Contato[], int);
ERROS carregar(Contato[], int*);

