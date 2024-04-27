#include <stdio.h>
#include "con.c"
#include "con.h"

ERROS adicionar(Contato contatos[], int *pos);
if(*pos >= TOTAL)
  return maximo_contatos;

printf("Digite o nome do contato: ");
scanf("%s", contatos[*pos].nome);

printf("Digite o email do contato: ");
scanf("%s", contatos[*pos].email);

clearBuffer();
  printf("Digite o telefone do contato: ");
  scanf("%d", &contatos[*pos].telefone);


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

