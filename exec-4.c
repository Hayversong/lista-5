/*Recebendo como parâmetro um vetor de float, por exemplo v[n] = “5.5,
8, 9.1, 25”, crie uma função que construa lista encadeada com esses
valores, seguindo a mesma ordem em que os números estão no vetor
recebido.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int info;
    char nome[50];
} Aluno;

typedef struct nodo {
    Aluno dados;
    struct nodo* prox;
} Nodo;

typedef struct {
    Nodo* inicio;
    int qtd;
} Lista;

// --- Criação da lista ---
Lista* criaLista() {
    Lista* li = (Lista*)malloc(sizeof(Lista));
    if (li != NULL) {
        li->inicio = NULL;
        li->qtd = 0;
    }
    return li;
}

// --- Inserção no final ---
int insereFinal(Lista* li, Aluno a) {
    if (li == NULL) return 0;

    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) return 0;

    novo->dados = a;
    novo->prox = NULL;

    if (li->inicio == NULL) {
        li->inicio = novo;
    } else {
        Nodo* aux = li->inicio;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }

    li->qtd++;
    return 1;
}


void imprimeLista(Lista* li) {
    if (li == NULL) return;
    Nodo* no = li -> inicio;
    
    while (no != NULL) {
        printf("Info: %d | Nome: %s\n", no -> dados.info, no -> dados.nome);
        no = no -> prox;
    }
}

Nodo* removeRecursivo(Nodo* no, int info, int* removido) {
    if (no == NULL) {
        *removido = 0;
        return NULL;
    }

    if (no->dados.info == info) {
        Nodo* temp = no -> prox;
        free(no);
        *removido = 1;
        return temp;
    }

    no -> prox = removeRecursivo(no -> prox, info, removido);
    return no;
}

int removePorValor(Lista* li, int info) {
    if (li == NULL) return 0;

    int removido = 0;
    li -> inicio = removeRecursivo(li -> inicio, info, &removido);
    if (removido) li -> qtd--;

    return removido;
}

// --- Comparação recursiva ---
int listasSaoIguais(Nodo* a, Nodo* b) {
    if (a == NULL && b == NULL) return 1;
    if (a == NULL || b == NULL) return 0;
    if (a -> dados.info != b -> dados.info || strcmp(a -> dados.nome, b -> dados.nome) != 0)
        return 0;
    return listasSaoIguais(a->prox, b->prox);
}

int listasIguais(Lista* l1, Lista* l2) {
    if (l1 == NULL || l2 == NULL) return 0;
    return listasSaoIguais(l1 -> inicio, l2 -> inicio);
}

// --- Criação de lista a partir de vetor de float ---
typedef struct nodo_float {
    float valor;
    struct nodo_float* prox;
} NodoFloat;

NodoFloat* criarListaDeVetor(float v[], int n) {
    if (n <= 0) return NULL;

    NodoFloat* inicio = NULL;
    NodoFloat* atual = NULL;

    for (int i = 0; i < n; i++) {
        NodoFloat* novo = (NodoFloat*)malloc(sizeof(NodoFloat));
        if (novo == NULL) {
            NodoFloat* temp;
            while (inicio != NULL) {
                temp = inicio;
                inicio = inicio->prox;
                free(temp);
            }
            return NULL;
        }

        novo -> valor = v[i];
        novo -> prox = NULL;

        if (inicio == NULL) {
            inicio = novo;
        } else {
            atual -> prox = novo;
        }

        atual = novo;
    }

    return inicio;
}

void imprimirListaFloat(NodoFloat* inicio) {
    NodoFloat* atual = inicio;
    while (atual != NULL) {
        printf("%.2f -> ", atual -> valor);
        atual = atual->prox;
    }
    printf("NULL\n");
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

    float valores[] = {5.5, 8.0, 9.1, 25.0};
    int tam = sizeof(valores) / sizeof(valores[0]);

    NodoFloat* listaFloat = criarListaDeVetor(valores, tam);
    printf("\nLista encadeada de floats:\n");
    imprimirListaFloat(listaFloat);

    return 0;
}

/*a lógica é converter um vetor de floats em lista, mantendo a ordem e tentando deixar tudo original, tudo é feito de forma dinâmica com ponteiros e chamadas e recursivas, tive certa dificuldade em implementar a main então tive ajuda de IA*/