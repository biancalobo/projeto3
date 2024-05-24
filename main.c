      #include <stdio.h>
      #include "tarefas.h"

      int main() {
          funcao fs[] = {adicionar, listar, deletar, salvar, carregar};
          Contato contatos[TOTAL];
          int pos = 0;
          ERROS erro;

          // Carregar os contatos do arquivo ao iniciar o programa
          erro = fs[4](contatos, &pos);
          if (erro != OK) {
              printf("Erro ao carregar os contatos: %d\n", erro);
          }

          int opcao;
          do {
              printf("\nMenu Principal\n");
              printf("1 - Adicionar contato\n");
              printf("2 - Listar contatos\n");
              printf("3 - Deletar contato\n");
              printf("0 - Sair\n");
              printf("Escolha uma opcao: ");

              if (scanf("%d", &opcao) != 1) {
                  clearBuffer();
                  printf("Entrada invalida\n");
                  opcao = -1;
              }

              if (opcao > 3 || opcao < 0) {
                  printf("Opcao invalida\n");
              } else if (opcao > 0) {
                  erro = fs[opcao - 1](contatos, &pos);
                  if (erro != OK) {
                      printf("Erro ao executar a opcao %d: %d\n", opcao, erro);
                  }
              } else {
                  printf("Saindo...\n");
              }
          } while (opcao != 0);

          erro = fs[3](contatos, &pos);  // Chama a função 'salvar' antes de sair
          if (erro != OK) {
              printf("Erro ao salvar os contatos: %d\n", erro);
          }

          return 0;
      }
