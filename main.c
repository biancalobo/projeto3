#include <stdio.h>
#include "tarefas.h"

int main(){
  funcao fs[] = {adicionar, listar, deletar, salvar, carregar};

  Contato contatos[TOTAL];
  ERROS erro = fs[4](contatos, &pos);
  
  int opcao;
  do{
    printf("\nMenu Principal\n");
    printf("1 - Adicionar contato\n");
    printf("2 - Listar contatos\n");
    printf("3 - Deletar contato\n");
    printf("0 - Sair\n");

opcao--;
      if(opcao > 2)
          printf("Opcao invalida\n");
      else if(opcao >= 0)
{
            ERROS erro = fs[opcao](contatos, &pos);
            if (erro != OK) {
                printf("Erro ao executar a opcao %d: %d\n", opcao + 1, erro);
            }
        } else
            printf("Sair...\n");

    } while (opcao >= 0);

    ERROS erro_salvar = fs[3](contatos, &pos);
    if (erro_salvar != OK) {
        printf("Erro ao salvar os contatos: %d\n", erro_salvar);
    }

    return 0;
}

