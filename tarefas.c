#include <stdio.h>
#include "tarefas.c"
#include "tarefas.h"


ERROS listar(Contato contatos[], int *pos){
    if(*pos == 0)
        return CONTATO_INEXISTENTE;

  char informacao[255];
  printf("Entre com a categoria que deseja listar: ");
  clearBuffer();
  fgets(informacao, 255, stdin);

    int encontradas = 0;
    for(int i=0; i<*pos; i++){
        printf("Contato: %d\t", i+1);
        printf("Nome: %d\t", contatos[i].nome);
        printf("Email: %s\t", contatos[i].email);
        printf("Telefone: %s\n", contatos[i].telefone);
        encontradas++;
    }

  if(encontradas == 0)
      printf("Nenhum contato encontrado com a informação '%s'.\n", informacao);
  return CONTATO_INEXISTENTE;
}

  return OK;

  vazio = 0

  if listar == 0
    printf("%d", listar)
}
=======

ERROS deletar(Contato contatos[], int *pos){
    if(*pos == 0)
        return CONTATO_INEXISTENTE;

    int pos_deletar;
    printf("Entre com a posicao da tarefa a ser deletada: ");
    scanf("%d", &pos_deletar);
    pos_deletar--;
    if(pos_deletar >= *pos || pos_deletar < 0)
        return CONTATO_INEXISTENTE;

    for(int i = pos_deletar; i < *pos; i++){
        contatos[i].nome = contatos[i+1].nome;
        strcpy(contatos[i].email, contatos[i+1].email);
        strcpy(contatos[i].telefone,  contatos[i+1].telefone);
    }

    *pos = *pos - 1;

    return OK;
}
=======
ERROS adicionar(Contato contatos[], int *pos);
if(*pos >= TOTAL)
  return maximo_contatos;

printf("Digite o nome do contato: ");
scanf("%s", contatos[*pos].nome);







