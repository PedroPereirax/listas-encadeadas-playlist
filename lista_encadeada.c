#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

// Exibe a lista
void exibirLista(No *head) {

    while (head != NULL) {
        printf("%d -> ", head->valor);
        head = head->prox;
    }

    printf("NULL\n");
}

// Inserir em posição específica
void inserirPosicao(No **head, int valor, int posicao) {

    No *novo = (No *) malloc(sizeof(No));

    novo->valor = valor;
    novo->prox = NULL;

    // Inserção no início
    if (posicao == 0) {
        novo->prox = *head;
        *head = novo;
        return;
    }

    No *temp = *head;
    int i = 0;

    while (temp != NULL && i < posicao - 1) {
        temp = temp->prox;
        i++;
    }

    // Posição inválida
    if (temp == NULL) {
        printf("Posicao invalida!\n");
        free(novo);
        return;
    }

    novo->prox = temp->prox;
    temp->prox = novo;
}

// Buscar valor
int buscarValor(No *head, int valor) {

    int posicao = 0;

    while (head != NULL) {

        if (head->valor == valor)
            return posicao;

        head = head->prox;
        posicao++;
    }

    return -1;
}

// Inverter lista
void inverterLista(No **head) {

    No *anterior = NULL;
    No *atual = *head;
    No *proximo = NULL;

    while (atual != NULL) {

        proximo = atual->prox;
        atual->prox = anterior;

        anterior = atual;
        atual = proximo;
    }

    *head = anterior;
}

// Dividir lista
void dividirLista(No *head, No **lista1, No **lista2) {

    if (head == NULL) {
        *lista1 = NULL;
        *lista2 = NULL;
        return;
    }

    No *lento = head;
    No *rapido = head->prox;

    while (rapido != NULL && rapido->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }

    *lista1 = head;
    *lista2 = lento->prox;

    lento->prox = NULL;
}

int main() {

    No *lista = NULL;
    No *lista1 = NULL;
    No *lista2 = NULL;

    inserirPosicao(&lista, 10, 0);
    inserirPosicao(&lista, 20, 1);
    inserirPosicao(&lista, 30, 2);
    inserirPosicao(&lista, 99, 1);

    printf("Lista:\n");
    exibirLista(lista);

    int pos = buscarValor(lista, 20);

    printf("\nValor 20 encontrado na posicao: %d\n", pos);

    inverterLista(&lista);

    printf("\nLista invertida:\n");
    exibirLista(lista);

    dividirLista(lista, &lista1, &lista2);

    printf("\nPrimeira lista:\n");
    exibirLista(lista1);

    printf("\nSegunda lista:\n");
    exibirLista(lista2);

    return 0;
}