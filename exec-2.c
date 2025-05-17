/*Faça duas funções recursivas. A primeira deve remover um nó da lista
encadeada a partir do seu valor armazenado (ex: int info). A segunda
deve receber duas listas encadeadas e verificar se elas são iguais*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int info;
    char nome[50]; 
} Aluno;

typedef struct elemento {
    Aluno dados;
    struct elemento* prox;
} Elemento;

typedef struct {
    Elemento* inicio;
    int qtd;
} Lista;

Lista* criaLista() {
    Lista* li = (Lista*)malloc(sizeof(Lista));
    if (li != NULL) {
        li->inicio = NULL;
        li->qtd = 0;
    }
    return li;
}

int insereFinal(Lista* li, Aluno a) {
    if (li == NULL) return 0;

    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    if (novo == NULL) return 0;

    novo -> dados = a;
    novo -> prox = NULL;

    if (li -> inicio == NULL) {
        li -> inicio = novo;
    } else {
        Elemento* aux = li -> inicio;
        while (aux -> prox != NULL)
            aux = aux -> prox;
        aux -> prox = novo;
    }

    li->qtd++;
    return 1;
}

void imprimeLista(Lista* li) {
    if (li == NULL) return;
    Elemento* no = li->inicio;
    while (no != NULL) {
        printf("Info: %d | Nome: %s\n", no->dados.info, no->dados.nome);
        no = no -> prox;
    }
}

Elemento* removeRecursivo(Elemento* nodo, int info, int* removido) {
    if (nodo == NULL) {
        *removido = 0;
        return NULL;
    }

    if (nodo->dados.info == info) {
        Elemento* temp = nodo->prox;
        free(nodo);
        *removido = 1;
        return temp;
    }

    nodo -> prox = removeRecursivo(nodo->prox, info, removido);
    return nodo;
}

int removePorValor(Lista* li, int info) {
    if (li == NULL) return 0;

    int removido = 0;
    li->inicio = removeRecursivo(li->inicio, info, &removido);
    if (removido) li->qtd--;

    return removido;
}


int listasSaoIguais(Elemento* a, Elemento* b) {
    if (a == NULL && b == NULL) return 1;
    if (a == NULL || b == NULL) return 0;
    if (a->dados.info != b->dados.info || strcmp(a->dados.nome, b->dados.nome) != 0)
        return 0;
    return listasSaoIguais(a->prox, b->prox);
}

int listasIguais(Lista* l1, Lista* l2) {
    if (l1 == NULL || l2 == NULL) return 0;
    return listasSaoIguais(l1->inicio, l2->inicio);
}

int main() {
    Lista* lista1 = criaLista();
    Lista* lista2 = criaLista();

    Aluno a1 = {10, "Ana"};
    Aluno a2 = {20, "Bruno"};
    Aluno a3 = {30, "Carlos"};

    insereFinal(lista1, a1);
    insereFinal(lista1, a2);
    insereFinal(lista1, a3);

    insereFinal(lista2, a1);
    insereFinal(lista2, a2);
    insereFinal(lista2, a3);

    printf("Lista 1:\n");
    imprimeLista(lista1);

    printf("\nLista 2:\n");
    imprimeLista(lista2);

    printf("\nListas são iguais? %s\n", listasIguais(lista1, lista2) ? "Sim" : "Não");

    printf("\nRemovendo valor 20 da Lista 1...\n");
    removePorValor(lista1, 20);

    printf("\nLista 1 após remoção:\n");
    imprimeLista(lista1);

    printf("\nListas são iguais agora? %s\n", listasIguais(lista1, lista2) ? "Sim" : "Não");

    return 0;
}


/*a primeira função percorre a lista até encontrar o valor, o nodo é removido quando encontrado e a lista reconectada, a segunda função verifica se dois nodos são iguais e chama recusirvamente para os próximos*/