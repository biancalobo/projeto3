#include <stdio.h>
#include <string.h>
#include "tarefas.h"

ERROS adicionar(Contato contatos[], int *pos) {
    if (*pos >= TOTAL)
        return MAXIMO_CONTATOS;

    printf("Digite o nome do contato: ");
    int result = scanf(" %s", contatos[*pos].nome);
    if (result != 1) {
        clearBuffer();
        return ERRO_ADICIONAR;
    }

    clearBuffer();
    printf("Digite o telefone do contato: ");
    result = scanf("%d", &contatos[*pos].telefone);
    if (result != 1) {
        clearBuffer();
        return ERRO_ADICIONAR;
    }

    for (int i = 0; i < *pos; i++) {
        if (contatos[i].telefone == contatos[*pos].telefone) {
            printf("Telefone já existe na lista.\n");
            return ERRO_ADICIONAR;
        }
    }

    clearBuffer();
    printf("Digite o email do contato: ");
    result = scanf(" %[^\n]", contatos[*pos].informacao);
    if (result != 1) {
        clearBuffer();
        return ERRO_ADICIONAR;
    }

    (*pos)++;
    return OK;
}


ERROS listar(Contato contatos[], int *pos) {
    if (*pos > TOTAL)
        return ERRO_LISTAR;

    if (*pos == 0) {
        printf("Nenhum contato cadastrado.\n");
    } else {
        for (int i = 0; i < *pos; i++) {
            printf("Contato %d\n", i + 1);
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %d\n", contatos[i].telefone);
            printf("Informacao: %s\n", contatos[i].informacao);
            printf("\n");
        }
    }
    return OK;
}

ERROS deletar(Contato contatos[], int *pos) {
    if (*pos == 0)
        return CONTATO_INEXISTENTE;

    int pos_deletar;
    printf("Entre com a posicao do contato a ser deletado: ");
    if (scanf("%d", &pos_deletar) != 1) {
        clearBuffer();
        return ERRO_LER;
    }
    pos_deletar--;

    if (pos_deletar >= *pos || pos_deletar < 0)
        return CONTATO_INEXISTENTE;

    for (int i = pos_deletar; i < *pos - 1; i++) {
        strcpy(contatos[i].nome, contatos[i + 1].nome);
        contatos[i].telefone = contatos[i + 1].telefone;
        strcpy(contatos[i].informacao, contatos[i + 1].informacao);
    }
    (*pos)--;
    return OK;
}

//função para alterar os dados de um contato

ERROS alterar(Contato contatos[], int *pos) {
        if (*pos == 0) {
            printf("Nenhum contato cadastrado.\n");
            return OK;
        }

        printf("Digite o nome do contato que deseja alterar: \n");
        for (int i = 0; i < *pos; i++) {
            printf("%d - %s\n", i + 1, contatos[i].nome);
        }

        int escolha;
        printf("Digite o número do contato que deseja alterar: ");
        if (scanf("%d", &escolha) != 1) {
            clearBuffer();
            printf("Entrada inválida.\n");
            return OK;
        }
        escolha--;

        if (escolha < 0 || escolha >= *pos) {
            printf("Contato inválido.\n");
            return OK;
        }

        printf("Digite o novo nome: ");
        if (scanf("%s", contatos[escolha].nome) != 1) {
            clearBuffer();
            printf("Entrada invalida.\n");
            return OK;
        }

        printf("Digite o novo telefone: ");
        if (scanf("%d", &contatos[escolha].telefone) != 1) {
            clearBuffer();
            printf("Entrada invalida.\n");
            return OK;
        }

        printf("Digite o novo email: ");
        if (scanf("%s", contatos[escolha].informacao) != 1) {
            clearBuffer();
            printf("Entrada invalida.\n");
            return OK;
        }

        printf("Contato alterado com sucesso.\n");

        return OK;

}

ERROS salvar(Contato contatos[], int *pos) {
    FILE *f = fopen("tarefas.bin", "wb");
    if (f == NULL)
        return ERRO_SALVAR;

    int qtd = fwrite(contatos, sizeof(Contato), *pos, f);
    if (qtd != *pos) {
        fclose(f);
        return ERRO_ESCREVER;
    }

    qtd = fwrite(pos, sizeof(int), 1, f);
    if (qtd != 1) {
        fclose(f);
        return ERRO_ESCREVER;
    }

    if (fclose(f))
        return ERRO_FECHAR;

    return OK;
}


ERROS carregar(Contato contatos[], int *pos) {
    FILE *f = fopen("tarefas.bin", "rb");
    if (f == NULL)
        return ERRO_ABRIR;

    int qtd = fread(contatos, sizeof(Contato), TOTAL, f);
    if (qtd == 0 && ferror(f))
        return ERRO_LER;

    qtd = fread(pos, sizeof(int), 1, f);
    if (qtd == 0 && ferror(f))
        return ERRO_LER;

    if (fclose(f))
        return ERRO_FECHAR;

    return OK;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

ERROS adicionar(Contato contatos[], int *pos) {
    if (*pos >= TOTAL)
        return MAXIMO_CONTATOS;

    printf("Digite o nome do contato: ");
    int result = scanf(" %s", contatos[*pos].nome);
    if (result != 1) {
        clearBuffer();
        return ERRO_ADICIONAR;
    }

    printf("Digite o número de telefone do contato: ");
    result = scanf("%d", &contatos[*pos].telefone);
    if (result != 1) {
        clearBuffer();
        return ERRO_ADICIONAR;
    }

    for (int i = 0; i < *pos; i++) {
        if (contatos[i].telefone == contatos[*pos].telefone) {
            printf("Este telefone já está cadastrado\n");
            return ERRO_ADICIONAR;
        }
    }

    clearBuffer();
    printf("Digite o email do contato: ");
    result = scanf(" %[^\n]", contatos[*pos].informacao);
    if (result != 1) {
        clearBuffer();
        return ERRO_ADICIONAR;
    }

    (*pos)++;
    return OK;
}
