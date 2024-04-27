#include <stdio.h>
#include "tarefas.c"
#include "tarefas.h"

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







void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
