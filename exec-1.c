/*Utilizando o código de listas que está disponível junto com a aula no
arquivo “ProjListaDinEncad”, faça o que se pede:
a. Crie uma nova função que consulta a lista e retorna um aluno
pela sua matricula
b. Crie uma nova função que consulta a lista e retorna um aluno
pela sua posição na lista*/
#include <stdio.h>
#include<stdlib.h>

typedef struct {
    int matricula;
    char nome[100];
} Aluno;

typedef struct elemento {
    Aluno dados;
    struct elemento* prox;
} Elemento;

typedef struct {
    Elemento* inicio;
} Lista;

Aluno* buscaAlunoPorMatricula(Lista* li, int matricula) {
    if (li == NULL || li->inicio == NULL) {
        return NULL; 
    }
    
    Elemento* nodo = li->inicio;
    while (nodo != NULL) {
        if (nodo->dados.matricula == matricula) {
            return &(nodo->dados); 
        }
        nodo = nodo->prox;
    }
    
    return NULL; 
}

Aluno* buscaAlunoPorPosicao(Lista* li, int posicao) {
    if (li == NULL || li->inicio == NULL || posicao < 1) {
        return NULL; 
    }
    
    Elemento* no = li->inicio;
    int contador = 1;
    
    while (no != NULL && contador < posicao) {
        no = no -> prox;
        contador++;
    }
    
    if (no != NULL) {
        return &(no -> dados); 
    }
    
    return NULL; 
}