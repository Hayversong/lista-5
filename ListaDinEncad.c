#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h" //inclui os Protótipos

//Definição do tipo lista
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elemento;

struct elemento2{
    int valor;
    struct elemento2* prox;
};
typedef struct elemento2 Elemento2;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL){
        Elemento* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere início
        *li = no;
    }else{
        Elemento *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento* no;
    no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return 0;
    Elemento *no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){//lista vazia: insere início
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elemento *ant, *atual = *li;
        while(atual != NULL && atual->dados.matricula < al.matricula){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere início
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elemento *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)//não encontrado
        return 0;

    if(no == *li)//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elemento *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li))//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elemento* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elemento* no = *li;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %f %f %f\n",no->dados.n1,
                                   no->dados.n2,
                                   no->dados.n3);
        printf("-------------------------------\n");

        no = no->prox;
    }
}

ListaInt* cria_lista_int(){
    ListaInt* l1 = (ListaInt*) malloc(sizeof(ListaInt));
    if(l1 != NULL){
        *l1 = NULL;
    }
    return l1;
}
int insere_lista_int(ListaInt* l1, int valor){
    if(l1 == NULL){
        return 0;
    }
    Elemento2 *no;
    no = (Elemento2*) malloc(sizeof(Elemento2));
    if(no == NULL){
        return 0;
    }
    no->valor = valor;
    no->prox = (*l1);
    *l1 = no;
    return 1;
}
int remove_lista_int(ListaInt* l1, int valor){
    if(l1 == NULL){
        return 0;
    }
    Elemento2 *aux = *l1;
    while(aux!= NULL){
        Elemento2 *ant, *no = *l1;
        while(no!=NULL && no->valor != valor){
            ant = no;
            no = no->prox;
        }
        if(no == NULL)
            return 0;
        if(no == *l1)
            *l1 = no->prox;
        else
            ant->prox = no->prox;
        aux = aux->prox;
    }
    return 1;
}
void imprime_lista_int(ListaInt* l1){
    if(l1 == NULL){
        return;
    }
    Elemento2 *no = *l1;
    printf("\n\n\n---- LISTA ----\n\n\n");
    while(no!=NULL){
        printf("       %d\n",no->valor);
        no = no->prox;
    }
    free(no);
    return;
}
void libera_lista_int(ListaInt* l1){
    if(l1 != NULL){
        Elemento2* no;
        while((*l1) != NULL){
            no = *l1;
            *l1 = (*l1)->prox;
            free(no);
        }
        free(l1);
    }
}
int concatena_Lista(Lista* l1, Lista* l2){
    if(l1 == NULL || l2 == NULL){
        return 0;
    }
    Elemento* no = *l2;
    while(no != NULL){
        insere_lista_final(l1, no->dados);
        no = no->prox;
    }
    return 1;
}
int elementos_unicos(Lista* l1){
    if(l1 == NULL){
        return 0;
    }
    int cont;
    Elemento *no = *l1;
    while(no!=NULL){
        Elemento *aux = no;
        cont = 0;
        while(aux!=NULL){
            if(no->dados.matricula == aux->dados.matricula
               && no->dados.n1 == aux->dados.n1
               && no->dados.n2== aux->dados.n2
               && no->dados.n3== aux->dados.n3
               && strcmp(no->dados.nome, aux->dados.nome) == 0){
                cont++;
                if(cont>1){
                    cont = 0;
                    remove_lista(l1,aux->dados.matricula);
                }
            }
            aux = aux->prox;
        }
        no = no->prox;
    }
    return 1;
}
int fusao_listas_ordenadas(Lista* l1, Lista* l2){
    if(l1 == NULL || l2 == NULL){
        return 0;
    }
    Elemento *no = *l2;
    while(no!=NULL){
        insere_lista_ordenada(l1, no->dados);
        no = no -> prox;
    }
    return 1;
}

int Troca(Lista* l1, int mat){
    if(l1 == NULL){
        return 0;
    }
    Elemento* no =*l1;
    Elemento* aux = *l1;
    if(no->dados.matricula == mat){
        aux = no->prox;
        no->prox = aux->prox;
        aux->prox = no;
        *l1 = aux;
        return 1;
    }
    Elemento* anterior =no;
    no = no -> prox;
    while(no!=NULL){
        if(no->prox == NULL){
            return 0;
        }
        if(no->dados.matricula == mat){
            aux = no->prox;
            no->prox = aux->prox;
            aux->prox = no;
            anterior->prox = aux;
            return 1;
        }
        anterior = no;
        no = no->prox;
    }
    return 0;
}
