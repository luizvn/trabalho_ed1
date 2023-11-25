#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // BIBLIOTECA NECESSÁRIA PARA USAR OS CARACTERES DO PORTUGUÊS

// ======= DEFINES =======
#define TAM 50

// ======= ESTRUTURAS =======

// LISTA DE PAISES:
typedef struct nodo1{
    char nome[TAM];
    int qtde_turista01, qtde_turista02;
    struct nodo1 *baixo, *prox;
}Lista;

//ARVORE DE DECISÃO:
typedef struct nodo2{
    int id;
   // char mensagem[TAM]; // Mensagem/Pergunta
    struct nodo2 *sim, *nao;
}Arvore;

// ======= DECLARAÇÕES DAS FUNÇÕES =======

void creditos();
void sobre();
void montar_lista(Lista **);
void montar_arvore(Arvore *);

// ======= MAIN =======

int main(){
    setlocale(LC_ALL, "Portuguese");

    int op;
    Lista *inicio;
    Arvore *raiz;

    inicio = NULL;
    raiz = NULL;

    montar_lista(&inicio);
    //montar_arvore(raiz);

    // MENU INCIAL:
    do{
        system("cls");
        printf("\n |======== TRABALHO ED1 ========|");
        printf("\n 1 - CRÉDITOS                    ");
        printf("\n 2 - SOBRE                       ");
        printf("\n 3 - ACESSAR O SISTEMA           ");
        printf("\n |==============================|");
        printf("\n ESCOLHA A OPCÃO: ");
        scanf("%d", &op);

        switch(op){
        case 1:
            creditos();
            break;
        case 2:
            sobre();
            break;
        case 3:
            break;
        default:
            printf("\n\n Opcão invalida!\n");
            system("pause");
            break;
        }
    }while(op != 3);

    do{
        system("cls");
        printf("\n |====================| VIAGENS ED1 |====================|");
        printf("\n |1 - Estou decidido em qual local escolher              |");
        printf("\n |2 - ");
        printf("\n |3 - ");
        printf("\n |4 - ");
        printf("\n |5 - ");
        printf("\n |6 - ");
        printf("\n |7 - ");
        printf("\n |8 - ");
        printf("\n |9 - Sair do Sistema                                    |");
        printf("\n |=======================================================|");
        printf("\n ESCOLHA A OPÇÃO: ");
        scanf("%d", &op);

        switch(op){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            printf("\n Saindo do sistema...\n");
            system("pause");
            break;
        default:
            printf("\n Opção Inválida!\n");
            system("pause");
        }
    }while(op != 9);

    return 0;
}

// ======= FUNÇÕES =======

// CRÉDITOS:
void creditos(){
    system("cls");
    printf("\n|================CRÉDITOS================|");
    printf("\n UNIVERSIDADE DO ESTADO DA BAHIA(UNEB)    ");
    printf("\n COMPONENTES:                             ");
    printf("\n - Gabriel Cerqueira Santos Rodrigues     ");
    printf("\n - Luiz Vinícius Pereira de Oliveira Souza");
    printf("\n PROFESSORA: Maria Inês                   ");
    printf("\n DISCIPLINA: Estrtura de Dados I(ED1)     ");
    printf("\n SEMESTRE: 3º semestre                    ");
    printf("\n Um trabalho universitário do 3º semestre ");
    printf("\n|========================================|");

    printf("\n\n");

    printf("\n ´´´´´´´´´´´´´´#´´´´´´´´´#´´´´´´´´´#´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´´´´´´´´´´´####´´´´´´####´´´´´#####´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´´´´´´´´´´´´´####´´´´´####´´´´´´####´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´´´´´´´´´´#######´´´####@#´´´#######´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´´´´´´´´´´´#####´´´´´####´´´´´#####´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´´´´´´´´#############################´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´´´´´´´´#############################´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´´´´´´´´#############################´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´###´´´´´");
    printf("\n ´´´´´´´´´´´´######´´#############´#######´´´´´´´´´´´´´´´´´´´´##´´´´´´´´´##´´´´´##´´´´´´´´##´´´´´#########´´´´´##´´´´###´");
    printf("\n ´´´´´´´´´´´´####´##´##´##########´´######´´´´´´´´´´´´´´´´´´´´##´´´´´´´´´##´´´´#####´´´´´´##´´´´´#########´´´´´##´´´´´##´");
    printf("\n ´´´´´´´´´´´´#############################´´´´´´´´´´´´´´´´´´´´##´´´´´´´´´##´´´´##´###´´´´´##´´´´´###´´´´´´´´´´´##´´´´´##´");
    printf("\n ´´´´´´´´´´´´#####´#´############´´#´#####´´´´´´´´´´´´´´´´´´´´##´´´´´´´´´##´´´´##´´´###´´´##´´´´´#######´´´´´´´#######´´´");
    printf("\n ´´´´´´´´´´´´##´##########################´´´´´´´´´´´´´´´´´´´´##´´´´´´´´´##´´´´##´´´´###´´##´´´´´#######´´´´´´´##´´´´´##´");
    printf("\n ´´´´´´´´´´´´##´´######################´##´´´´´´´´´´´´´´´´´´´´##´´´´´´´´´##´´´´##´´´´´´#####´´´´´###´´´´´´´´´´´##´´´´´###");
    printf("\n ´´´´´´´´´´´´##´´#########################´´´´´´´´´´´´´´´´´´´´###´´´´´´´###´´´´##´´´´´´´####´´´´´##########´´´´##´´´´´###");
    printf("\n ´´´´´´´´´´´´##´´´´´´´´´´´´##´´´´´´´´´´###´´´´´´´´´´´´´´´´´´´´´###´´´´´###´´´´´##´´´´´´´´###´´´´´##########´´´´#########´");
    printf("\n ´´´´´´´´´´´´##´´´´´´´´´´´´##´´´´´´´´´´###´´´´´´´´´´´´´´´´´´´´´###´´´´´###´´´´´##´´´´´´´´###´´´´´##########´´´´#########´");
    printf("\n ´#´´´´#####´##´##########´############´##´#####´´´´#´´´´´´´´´´´´´####´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´########################################´########@@´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ###########´######´´#####´#######´#######´####@##@@@#´´´´´´´#############################´´´############################");
    printf("\n ´#####´´###´######´´##´##########´´##########´#####´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´´#####´#############################´####´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´#####´´#######´#############´#######´´#@@##´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´##´###´##############´#############´´###@@##´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´#########´#################################´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´´#############´´´´#######´´´´´############´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´´´´#####################################´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´´´´´´#################################´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´´´´´´´´´´##########################´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´´´´´´´´´´´´###´#############´´##´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´´´´´´´´´´´´´##´´´´´´´##´´´´´´´´#´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");
    printf("\n ´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´");

    printf("\n\n");

    system("pause");
}

// SOBRE:
void sobre(){
    system("cls");
    printf("\n |=======================SOBRE=======================|");
    printf("\n Trabalho passado com o objetivo de criar um sistema  ");
    printf("\n de viagens, capaz de escolher seu destino, tanto pe- ");
    printf("\n la decisão do cliente, quanto pela indecisão a partir");
    printf("\n de perguntas que nortearão o cliente a um destino    ");
    printf("\n específico. Posteriormente, gravando a quantidade de ");
    printf("\n vezes que o cliente foi para cada destino.           ");
    printf("\n |===================================================|");

    printf("\n\n");

    system("pause");
}

// ÁRVORE DE DECISÃO:
Arvore* arvore_decisao(Arvore* raiz){
    int n;

    // NÍVEL 0:
    n = 8;
    raiz = inserir_id(raiz, n);

    // NÍVEL 1:

    // NÍVEL 2:

    // NÍVEL 3:

    // NÍVEL 4:
}

Arvore* inserir_id(Arvore* raiz, int n){
    if(raiz == NULL){
        raiz = (Arvore*)malloc(sizeof(Arvore));
        if(raiz == NULL){
            printf("\n Sem memória");
            exit(1);
        }
        raiz->id = n;
        raiz->sim = NULL;
        raiz->nao = NULL;
        return (raiz);
    }else{
        if(n > raiz->id){
            raiz->nao = inserir_id(raiz->nao, n);
        } else if(n < raiz->id){
            raiz->sim = inserir_id(raiz->sim, n);
        } else{
            printf("\n [ERRO] valor repetido!");
            system("pause");
        }
        return (raiz);
    }

}

// CÓDIGO/ID DA ÁRVORE DE DECISÃO:
void codigo(int id){
    // PERGUNTAS:
    if(id == 1){
        printf("\n| Gosta de parque aquático? |");
    } else if(id == 2){
        printf("\n| Gosta de praia? |");
    } else if(id == 3){
        printf("\n| Tem interesse em política? |");
    } else if(id == 4){
        printf("\n| Deseja realizar uma viagem nacional? |");
    } else if(id == 5){
        printf("\n| Gosta de animais selvagens? |");
    } else if(id == 6){
        printf("\n| Gosta de ter experiências próximas a natureza? |");
    } else if(id == 7){
        printf("\n| Gosta de jogos de azar? |");
    } else if(id == 8){
        printf("\n| Gosta de calor? |");
    } else if(id == 9){
        printf("\n| Gosta de museus? | ");
    } else if(id == 10){
        printf("\n| Gosta de realizar atividades na neve? |");
    } else if(id == 11){
        printf("\n| Gostaria de ter contato com o berço do catolicismo? |");
    } else if(id == 12){
        printf("\n| Deseja realizar uma viagem para a Europa? |");
    } else if(id == 13){
        printf("\n| Interesse na cultura latina? |");
    } else if(id == 14){
        printf("\n| Gosta de altura/montanhas? |");
    } else if(id == 15){
        printf("\n| Deseja ter contato com uma culinária única? |");
    }

    // CIDADES TURÍSTICAS:
    if(id == 16){
        printf("\n Fortaleza");
    } else if(id == 17){
        printf("\n Salvador");
    } else if(id == 18){
        printf("\n Brasília");
    } else if(id == 19){
        printf("\n São Paulo");
    } else if(id == 20){
        printf("\n SAVANA(Decidir)");
    } else if(id == 21){
        printf("\n Cairo");
    } else if(id == 22){
        printf("\n Las Vegas");
    } else if(id == 23){
        printf("\n Orlando");
    } else if(id == 24){
        printf("\n São Petersburgo");
    } else if(id == 25){
        printf("\n Moscou");
    } else if(id == 26){
        printf("\n Roma");
    } else if(id == 27){
        printf("\n Nápoles");
    } else if(id == 28){
        printf("\n Santiago");
    } else if(id == 29){
        printf("\n Chengdu");
    } else if(id == 30){
        printf("\n Macau");
    } else if(id == 31){
        printf("\n Nova York");
    }
}

// MONTAR LISTA
void montar_lista(Lista **inicio){
	Lista *atual, *aux;

    atual = (Lista*)malloc(sizeof(Lista));

    aux = atual;

    strcpy(atual->nome, "Brasil");
    printf(" %s ", atual->nome);
    atual->prox = NULL;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Estados Unidos");
    printf(" %s ", atual->nome);
    atual->prox = NULL;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "China");
    printf(" %s ", atual->nome);
    atual->prox = NULL;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Russia");
    printf(" %s ", atual->nome);
    atual->prox = NULL;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Italia");
    printf(" %s ", atual->nome);
    atual->prox = NULL;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Egito");
    printf(" %s ", atual->nome);
    atual->prox = NULL;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Chile");
    printf(" %s ", atual->nome);
    atual->prox = NULL;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Quenia");
    printf(" %s ", atual->nome);

    atual->prox = NULL;
    atual = atual->prox;

    *inicio = aux;

    atual = *inicio;
    aux = atual;

    while(atual != NULL){
        if(strcmp(atual->nome,"Brasil") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Salvador");
            atual->baixo = NULL;

            atual = atual->baixo;
            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Fortaleza");
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Sao Paulo");
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Brasilia");
            atual->baixo = NULL;
        } else if(strcmp(atual->nome, "Estados Unidos") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Orlando");
            atual->baixo = NULL;

            atual = atual->baixo;
            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Las Vegas");
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Nova York");
            atual->baixo = NULL;
        } else if(strcmp(atual->nome, "China") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Chengdu");
            atual->baixo = NULL;

            atual = atual->baixo;
            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Macau");
            atual->baixo = NULL;
        } else if(strcmp(atual->nome, "Russia") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Sao Petersburgo");
            atual->baixo = NULL;

            atual = atual->baixo;
            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Moscou");
            atual->baixo = NULL;
        } else if(strcmp(atual->nome, "Italia") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Chengdu");
            atual->baixo = NULL;

            atual = atual->baixo;
            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Macau");
            atual->baixo = NULL;
        } else if(strcmp(atual->nome, "Egito") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Cairo");
            atual->baixo = NULL;
        } else if(strcmp(atual->nome, "Chile") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Santiago");
            atual->baixo = NULL;
        } else if(strcmp(atual->nome, "Quenia") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Nairobi");
            atual->baixo = NULL;
        }
        atual = aux;
        aux = aux->prox;
        atual = atual->prox;
    }

	printf("\n Lista inicializada! \n");
	system("pause");
}

