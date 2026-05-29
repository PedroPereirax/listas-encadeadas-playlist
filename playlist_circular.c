#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char musica[100];
    struct No *prox;
    struct No *ant;
} No;

// Copia string manualmente
void copiarTexto(char destino[], char origem[]) {

    int i = 0;

    while (origem[i] != '\0') {
        destino[i] = origem[i];
        i++;
    }

    destino[i] = '\0';
}

// Adicionar música
void adicionarMusica(No **head, char *nome) {

    No *novo = (No *) malloc(sizeof(No));

    copiarTexto(novo->musica, nome);

    // Lista vazia
    if (*head == NULL) {

        novo->prox = novo;
        novo->ant = novo;

        *head = novo;

        return;
    }

    No *ultimo = (*head)->ant;

    ultimo->prox = novo;
    novo->ant = ultimo;

    novo->prox = *head;
    (*head)->ant = novo;
}

// Próxima música
void proximaMusica(No **atual) {

    if (*atual != NULL)
        *atual = (*atual)->prox;
}

// Música anterior
void musicaAnterior(No **atual) {

    if (*atual != NULL)
        *atual = (*atual)->ant;
}

// Exibir playlist
void exibirPlaylist(No *head) {

    if (head == NULL) {
        printf("Playlist vazia!\n");
        return;
    }

    No *temp = head;

    do {
        printf("[%s] <-> ", temp->musica);
        temp = temp->prox;

    } while (temp != head);

    printf("(volta ao inicio)\n");
}

// Total de músicas
int totalMusicas(No *head) {

    if (head == NULL)
        return 0;

    int total = 0;
    No *temp = head;

    do {
        total++;
        temp = temp->prox;

    } while (temp != head);

    return total;
}

int main() {

    No *playlist = NULL;
    No *atual = NULL;

    adicionarMusica(&playlist, "Rock");
    adicionarMusica(&playlist, "Jazz");
    adicionarMusica(&playlist, "Pop");

    atual = playlist;

    printf("Playlist:\n");
    exibirPlaylist(playlist);

    printf("\nMusica atual: %s\n", atual->musica);

    proximaMusica(&atual);
    printf("Proxima musica: %s\n", atual->musica);

    musicaAnterior(&atual);
    printf("Musica anterior: %s\n", atual->musica);

    printf("\nTotal de musicas: %d\n", totalMusicas(playlist));

    return 0;
}