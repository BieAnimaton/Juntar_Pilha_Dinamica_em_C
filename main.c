#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int dado;
    struct pilha *prox;
} Pilha;

int inicializar (Pilha **pilha) {
    *pilha = NULL;
    return 0;
}

int inserir_topo (Pilha **pilha, int info) {
    Pilha *elemento;

    elemento = (Pilha*)malloc(sizeof(Pilha));
    elemento->dado = info;

    if (*pilha == NULL) {
        elemento->prox = NULL; // Inserção em pilha vazia
        *pilha = elemento;
    } else {
        elemento->prox = *pilha; // Inserção no início
        *pilha = elemento;
    }
    return 0;
}

int remover_topo (Pilha **pilha) {
    Pilha *aux;
    if (*pilha == NULL) {
        return 1;
    } else {
        aux = *pilha;
        *pilha = (*pilha)->prox;
        free(aux);
        return 0;
    }
}

int obter_topo(Pilha *pilha, int *dado) {
    if (pilha != NULL)
    {
       *dado = pilha -> dado;
       return 0;
    }
    else
       return 1; // Pilha Vazia
}

int verifica_vazio (Pilha *pilha, int *resp) {
    if (pilha != NULL)
        *resp = 0;
    else
        *resp = 1;
    return 0;
}

int juntar_pilhas (Pilha **P1, Pilha **P2, Pilha **P3) {
    Pilha *aux;
    int resp, erro, dado;

    erro = inicializar(P3);
    erro = inicializar(&aux);

    *P3 = *P2;
    *P2 = NULL;

    verifica_vazio(*P1, &resp);
    while (resp == 0) { // Pilha não vazia
        obter_topo(*P1, &dado);
        remover_topo(P1);
        inserir_topo(&aux, dado);
        verifica_vazio(*P1, &resp);
    }

    verifica_vazio(aux, &resp);
    while (resp == 0) { // Pilha não vazia
        obter_topo(aux, &dado);
        remover_topo(&aux);
        inserir_topo(P3, dado);
        verifica_vazio(aux, &resp);
    }

    return 0;
}

int listar (Pilha *pilha)
{
    while (pilha != NULL)
    {
        printf ("%d - ", pilha->dado);
        pilha = pilha->prox;
    }
}

int main()
{
    Pilha *p1, *p2, *p3;

    inicializar(&p1);
    inicializar(&p2);

    inserir_topo(&p1, 10);
    inserir_topo(&p1, 54);
    inserir_topo(&p1, 87);
    inserir_topo(&p1, 4);

    inserir_topo(&p2, 200);
    inserir_topo(&p2, 677);
    inserir_topo(&p2, 1800);

    printf("Pilha P1: ");
    listar(p1);
    printf("\n\n");

    printf("Pilha P2: ");
    listar(p2);
    printf("\n\n\n");

    printf("Juntando P1 e P2 na P3.\nPilha P3: ");
    juntar_pilhas(&p1, &p2, &p3);
    listar(p3);
    printf("\n");

    return 0;
}
