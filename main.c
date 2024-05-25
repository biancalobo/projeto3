#include <stdio.h>
#include "tarefas.h"

funcao fs[5] = {adicionar, listar, deletar, alterar, salvar};
Contato contatos_pessoais[CONTATOS_PESSOAIS];
Contato outros[OUTROS];
int pos_pessoais = 0;
int pos_outros = 0;
ERROS erro;

erro = fs[3](contatos_pessoais, &pos_pessoais);
if (erro != OK) {
    printf("Erro ao carregar os contatos pessoais: %d\n", erro);
}

erro = fs[3](outros, &pos_trabalho);
if (erro != OK) {
    printf("Erro ao carregar os contatos de trabalho: %d\n", erro);
}

 listas
=======
funcao_alterar
    erro = fs[1](contatos, &pos);
    if (erro != OK) {
        printf("Erro ao carregar os contatos: %d\n", erro);
    }
=======
          erro = fs[4](contatos, &pos);
          if (erro != OK) {
              printf("Erro ao carregar os contatos: %d\n", erro);
          }
main

    int opcao;
    do {
        printf("\nMenu Principal\n");
        printf("1 - Adicionar contato\n");
        printf("2 - Listar contatos\n");
        printf("3 - Deletar contato\n");
        printf("4 - Alterar contato\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            clearBuffer();
            printf("Entrada invalida\n");
            opcao = -1;
        }

        if (opcao > 4 || opcao < 0) {
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

funcao_alterar
    erro = fs[4](contatos, &pos); 
    if (erro != OK) {
        printf("Erro ao salvar os contatos: %d\n", erro);
    }
=======
          erro = fs[3](contatos, &pos);
          if (erro != OK) {
              printf("Erro ao salvar os contatos: %d\n", erro);
          }
 main

    return 0;
}
