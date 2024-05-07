#include <stdio.h>
#include "tarefas.h"

int main() {
    funcao fs[] = {adicionar, listar, deletar, salvar, carregar};
    Contato contatos[TOTAL];
    int pos = 0; 
    ERROS erro = fs[0](contatos, &pos);
  
  int opcao;
  do{
    printf("\nMenu Principal\n");
    printf("1 - Adicionar contato\n");
    printf("2 - Listar contatos\n");
    printf("3 - Deletar contato\n");
    printf("0 - Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

if (opcao > 3 || opcao < 0) {
            printf("Opcao invalida\n");
        } else if (opcao > 0) {
            ERROS erro = fs[opcao - 1](contatos, &pos);
            if (erro != OK) {
                printf("Erro ao executar a opcao %d: %d\n", opcao, erro);
            }
        } else {
            printf("Saindo...\n");
        }
    } while (opcao != 0);
    ERROS ERRO_SALVAR = fs[3](contatos, &pos); // Call 'salvar' function before exiting
    if (ERRO_SALVAR != OK) {
        printf("Erro ao salvar os contatos: %d\n", ERRO_SALVAR);
    }
    return 0;
}