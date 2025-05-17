/*Crie uma função que insere um valor em uma posição qualquer da lista
encadeada*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dado;
    struct Nodo* prox;
} Nodo;

// Função para criar um novo nó
Nodo* criarNo(int valor) {
    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    novo -> dado = valor;
    novo -> prox = NULL;
    return novo;
}

void inserirNaPosicao(Nodo** cabeca, int valor, int posicao) {
    Nodo* novo = criarNo(valor);

    if (posicao == 0) {
        novo->prox = *cabeca;
        *cabeca = novo;
        return;
    }

    Nodo* atual = *cabeca;
    int i = 0;

    while (atual != NULL && i < posicao - 1) {
        atual = atual->prox;
        i++;
    }

  if (atual == NULL) {
        printf("Posição inválida!\n");
        free(novo);
        return;
    }

    novo->prox = atual->prox;
    atual->prox = novo;
}

void imprimirLista(Nodo* cabeca) {
    while (cabeca != NULL) {
        printf("%d -> ", cabeca->dado);
        cabeca = cabeca->prox;
    }
    printf("NULL\n");
}

// Exemplo de uso
int main() {
    Nodo* lista = NULL;

    inserirNaPosicao(&lista, 10, 0); 
    inserirNaPosicao(&lista, 20, 1); 
    inserirNaPosicao(&lista, 15, 1);

    imprimirLista(lista); // 10 -> 15 -> 20 -> NULL

    return 0;
}

/*a função vai receber um ponteiro cabeça da lista, então um valor vai ser inserido na posição desejada, a função tem casos para inserir no inicio, no meio e no final da lista */