#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncad.h"
int main(){
    struct aluno al, a[8] = {{2,"Andre",9.5,7.8,8.5},
                         {4,"Ricardo",7.5,8.7,6.8},
                         {1,"Bianca",9.7,6.7,8.4},
                         {3,"Ana",5.7,6.1,7.4},
                         {6, "Thomas",9.3, 5.2, 7.8},
                         {5, "Gabriel", 5.4, 3.8, 8.6},
                         {8, "Carla", 5.6, 7.2, 6.5},
                         {7, "Maria", 7.4, 8.8, 6.9}
                         };
    int escolha;
    printf("Escolha um exercicio para testar:\n5: Remover numero inteiro nao negativo\n6: Concatenar L1 e L2\n7: Remover elementos repetidos\n8: Fundir duas listas e manter ordenadas\n9: Procedimento Troca(TipoLista* pLista, TipoCelula* p)\n");
    scanf("%d", &escolha);
    switch(escolha){
        case 5:{
            /*
            Receba um número inteiro não negativo e faça uma função que percorra
            a lista e remova todos os nós que contiverem esse número inteiro
            armazenado neles. Faça todas as condições de controle necessárias
            para as remoções sejam corretas.
            */
            ListaInt* l1 = cria_lista_int();
            for(int i = 0; i < 5; i++){
                insere_lista_int(l1, i);
            }
            insere_lista_int(l1, 2);
            insere_lista_int(l1, 3);
            imprime_lista_int(l1);
            int valor = -1;
            while(valor<0){
                printf("\nDigite um inteiro nao negativo para ser removido:\n");
                scanf("%d", &valor);
                if(valor<0){
                    printf("\nValor invalido\n");
                }
            }
            remove_lista_int(l1, valor);
            imprime_lista_int(l1);
            libera_lista_int(l1);
            break;
            /*
            Lógica usada: Adaptei os métodos anteriores para que a lista recebe inteiros ao invés de alunos,
            a única diferente foi a de remoção, que ao invés de remover o primeiro elemento igual ao passado,
            usei um nó auxiliar para que fossem removidos todos elementos que fossem iguais ao passado,
            */
        }
        case 6:{
            /*
            Escrever uma função para concatenar duas listas encadeadas L1 e L2.
            */
            Lista* l1 = cria_lista();
            Lista* l2 = cria_lista();
            for(int i=0; i < 4; i++){
                insere_lista_ordenada(l1,a[i]);
                insere_lista_ordenada(l2,a[i+4]);
            }
            printf("\n\n\n----- Lista 1 ----\n\n\n");
            imprime_lista(l1);
            printf("\n\n\n----- Lista 2 ----\n\n\n");
            imprime_lista(l2);
            printf("\n\n\n----- Lista 1 concatenada com Lista 2 ----\n\n\n");
            concatena_Lista(l1, l2);
            imprime_lista(l1);
            libera_lista(l1);
            libera_lista(l2);
            /*
            Lógica usada: apenas inseri os dados da lista 2 no final da Lista 1
            */
            break;
        }
        case 7:{
            /*
            Escrever uma função para remover elementos repetidos de uma lista encadeada.
            */
            Lista* l1 = cria_lista();
            for(int i=0; i < 3; i++){
                insere_lista_ordenada(l1,a[0]);
                insere_lista_ordenada(l1, a[1]);
                insere_lista_ordenada(l1, a[3]);
            }
            printf("\n\n\n----- Lista ----\n\n\n");
            imprime_lista(l1);
            printf("\n\n\n----- Lista sem elementos repetidos ----\n\n\n");
            elementos_unicos(l1);
            imprime_lista(l1);
            libera_lista(l1);
            break;
            /*
            Lógicas usada: Foi usado um nó auxiliar que pra cada nó vai percorrer todos os outros nós, comparando cada elemento,
            por exemplo, o primeiro nó é o aluno 1, o auxiliar vai percorrer a lista inteira comparando nó por nó, toda vez que o
            nó é igual ao auxiliar, a variável cont recebe +1, e como o valor de aux inicia com o do nó, o esperado é que cont
            termine com 1, toda vez que cont passar desse valor, significa que há um valor repetido, então quando isso acontece,
            é chamada a função de remoção e o cont é zerado.
            */
        }
        case 8:{
            /*
            Escrever um procedimento para fazer a fusão de duas listas encadeadas
            ordenadas, mantendo-a ordenada. Não devem ser alocados (criados)
            nós extras. Os nós serão religados para compor a nova lista ordenada.
            */
            Lista* l1 = cria_lista();
            Lista* l2 = cria_lista();
            for(int i=0; i < 4; i++){
                insere_lista_ordenada(l1,a[i]);
                insere_lista_ordenada(l2,a[i]);
            }
            printf("\n\n\n----- Lista 1 ----\n\n\n");
            imprime_lista(l1);
            printf("\n\n\n----- Lista 2 ----\n\n\n");
            imprime_lista(l2);
            printf("\n\n\n----- Lista 1 fundida com Lista 2 de forma ordenada ----\n\n\n");
            fusao_listas_ordenadas(l1, l2);
            imprime_lista(l1);
            libera_lista(l1);
            libera_lista(l2);
            /*
            Lógica usada: apenas inseri os dados da lista 2 na lista 1 usando a função insere_lista_ordenada
            */
            break;
        }
        case 9:{
            /*
            Considere a implementação de listas encadeadas. Escreva um
            procedimento Troca(TipoLista* pLista, TipoCelula* p) que, dado um
            apontador para uma célula qualquer (p), troca de posição essa célula
            com a sua célula seguinte da lista, como mostrado na figura abaixo.
            (Obs. Não vale trocar apenas o campo item! Você deverá fazer a
            manipulação dos apontadores para trocar as duas células de posição).
            Não esqueça de tratar os casos especiais.
            */
            Lista* l1 = cria_lista();
            for(int i=0; i < 5; i++){
                insere_lista_ordenada(l1,a[i]);
            }
            printf("\n\n\n----- Lista ----\n\n\n");
            imprime_lista(l1);
            int mat;
            printf("\nDigite um valor de matricula para fazer a troca com o da frente:\n");
            scanf("%d",&mat);
            Troca(l1, mat);
            imprime_lista(l1);
            libera_lista(l1);
            /*
            Lógica usada:primeiro ela verifica o caso especial (ser logo a primeira),
            faz a troca normal usando um auxiliar, caso não seja logo a primeira,
            ela percorre a lista inteira em busca da matricula, caso não ache ou a
            matricula é a última, retorna zero, mas caso ache antes disso ela troca
            com a proxima, fazendo uso da auxiliar, ajustando os ponteiros do anterior,
             atual e proximo.
            */
            break;
        }

    }
    system("pause");
    return 0;
}

