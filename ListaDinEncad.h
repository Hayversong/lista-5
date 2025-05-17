//Arquivo ListaDinEncad.h

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
void imprime_lista(Lista* li);

typedef struct elemento2* ListaInt;
ListaInt* cria_lista_int();
int insere_lista_int(ListaInt* l1, int valor);
int remove_lista_int(ListaInt* l1, int valor);
void imprime_lista_int(ListaInt* l1);
void libera_lista_int(ListaInt* l1);
int concatena_Lista(Lista* l1, Lista* l2);
int elementos_unicos(Lista* l1);
int fusao_listas_ordenadas(Lista* l1, Lista* l2);
int Troca(Lista* l1, int mat);
