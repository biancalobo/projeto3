#include <stdio.h>
#include "tarefas.h"
#include "tarefas.h"

ERROS adicionar(Contato contatos[], int *pos){
    if(*pos >= TOTAL)
        return maximo_contatos;

    printf("Digite o nome do contato: ");
    scanf(" %s", contatos[*pos].nome);

    clearBuffer();
    printf("Digite o telefone do contato: ");
    scanf(" %d", &contatos[*pos].telefone);

    (*pos)++;

    return OK;
}

ERROS carregar(Contato contatos[], int *pos){
    FILE *f = fopen("tarefas.bin", "rb");
    if(f == NULL)
        return ABRIR;

    int qtd = fread(contatos, TOTAL, sizeof(Contato), f);
    if(qtd == 0)
        return LER;

    qtd = fread(pos, 1, sizeof(int), f);
    if(qtd == 0)
        return LER;

    if(fclose(f))
        return FECHAR;

    return OK;

}

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


ERROS listar(Contato contatos[], int pos) {
    if (pos >= TOTAL)
        return ERRO_LISTAR;
    if (pos == 0) {
        printf("Nenhum contato cadastrado.\n");
    } else {
        for (int i = 0; i < pos; i++) {
            printf("Contato %d\n", i + 1);
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %d\n", contatos[i].telefone);
            printf("Informacao: %s\n", contatos[i].informacao);
            printf("\n");
        }
    }
    return OK;
}


ERROS deletar(Contato contatos[], int *pos){
    if(*pos == 0)
        return CONTATO_INEXISTENTE;

    int pos_deletar;
    printf("Entre com a posicao da tarefa a ser deletada: ");
    scanf(" %d", &pos_deletar);
    pos_deletar--;
    if(pos_deletar >= *pos || pos_deletar < 0)
        return CONTATO_INEXISTENTE;

    for (int i = pos_deletar; i < *pos - 1; i++){
        strcpy(contatos[i].nome, contatos[i + 1].nome);
        contatos[i].telefone = contatos[i + 1].telefone;
        strcpy(contatos[i].informacao, contatos[i+1].informacao);
    }
    (*pos)--;

    return OK;
}



ERROS salvar(Contato contatos[], int *pos){
    FILE *f = fopen("tarefas.bin", "wb");
    if(f == NULL)
        return ERRO_SALVAR;

    int qtd = fwrite(contatos, sizeof(Contato), *pos, f);
    if(qtd != *pos){
        fclose(f);
        return ERRO_ESCREVER;
    }
    qtd = fwrite(pos, sizeof(int), 1, f);
    if(qtd != 1){
        fclose(f);
        return ERRO_ESCREVER;
    }
    fclose(f);
    return OK;
}

