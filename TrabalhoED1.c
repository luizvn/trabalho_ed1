#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // BIBLIOTECA NECESS�RIA PARA USAR OS CARACTERES DO PORTUGU�S

// ======= DEFINES =======
#define TAM 50
#define RESP 3

// ======= ESTRUTURAS =======

// LISTA DE PAISES:
typedef struct nodo1{
    char nome[TAM];
    int qtde_turista01, qtde_turista02;
    struct nodo1 *baixo, *prox;
}Lista;

//ARVORE DE DECIS�O:
typedef struct nodo2{
    int id;
   // char mensagem[TAM]; // Mensagem/Pergunta
    struct nodo2 *sim, *nao;
}Arvore;

// ======= DECLARA��ES DAS FUN��ES =======

void creditos();
void sobre();
void montar_lista(Lista **);
void montar_arvore(Arvore **);
Arvore* inserir_id(Arvore *, int);
void pre_ordem(Arvore *);

// ======= MAIN =======

int main(){
    setlocale(LC_ALL, "Portuguese");

    int op;
    Lista *inicio;
    Arvore *raiz;

    inicio = NULL;
    raiz = NULL;

    // MONTANDO LISTA E �RVORE DE DECIS�O:
    montar_lista(&inicio);
    montar_arvore(&raiz);

    system("pause");
    // MENU INCIAL:
    do{
        system("cls");
        printf("\n |======== TRABALHO ED1 ========|");
        printf("\n 1 - CR�DITOS                    ");
        printf("\n 2 - SOBRE                       ");
        printf("\n 3 - ACESSAR O SISTEMA           ");
        printf("\n |==============================|");
        printf("\n ESCOLHA A OPC�O: ");
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
            printf("\n\n Opc�o invalida!\n");
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
        printf("\n ESCOLHA A OP��O: ");
        scanf("%d", &op);

        switch(op){
        case 1:
            break;
        case 2:
            pre_ordem(raiz);
            system("pause");
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
            printf("\n Op��o Inv�lida!\n");
            system("pause");
        }
    }while(op != 9);

    return 0;
}

// ======= FUN��ES =======

// CR�DITOS:
void creditos(){
    system("cls");
    printf("\n|================CR�DITOS================|");
    printf("\n UNIVERSIDADE DO ESTADO DA BAHIA(UNEB)    ");
    printf("\n COMPONENTES:                             ");
    printf("\n - Gabriel Cerqueira Santos Rodrigues     ");
    printf("\n - Luiz Vin�cius Pereira de Oliveira Souza");
    printf("\n PROFESSORA: Maria In�s                   ");
    printf("\n DISCIPLINA: Estrtura de Dados I(ED1)     ");
    printf("\n SEMESTRE: 3� semestre                    ");
    printf("\n Um trabalho universit�rio do 3� semestre ");
    printf("\n|========================================|");

    printf("\n\n");

    printf("\n ��������������#���������#���������#�������������������������������������������������������������������������������������");
    printf("\n ���������������####������####�����#####���������������������������������������������������������������������������������");
    printf("\n �����������������####�����####������####��������������������������������������������������������������������������������");
    printf("\n ��������������#######���####@#���#######��������������������������������������������������������������������������������");
    printf("\n ���������������#####�����####�����#####���������������������������������������������������������������������������������");
    printf("\n ������������#############################�������������������������������������������������������������������������������");
    printf("\n ������������#############################�������������������������������������������������������������������������������");
    printf("\n ������������#############################�����������������������������������������������������������������������###�����");
    printf("\n ������������######��#############�#######��������������������##���������##�����##��������##�����#########�����##����###�");
    printf("\n ������������####�##�##�##########��######��������������������##���������##����#####������##�����#########�����##�����##�");
    printf("\n ������������#############################��������������������##���������##����##�###�����##�����###�����������##�����##�");
    printf("\n ������������#####�#�############��#�#####��������������������##���������##����##���###���##�����#######�������#######���");
    printf("\n ������������##�##########################��������������������##���������##����##����###��##�����#######�������##�����##�");
    printf("\n ������������##��######################�##��������������������##���������##����##������#####�����###�����������##�����###");
    printf("\n ������������##��#########################��������������������###�������###����##�������####�����##########����##�����###");
    printf("\n ������������##������������##����������###���������������������###�����###�����##��������###�����##########����#########�");
    printf("\n ������������##������������##����������###���������������������###�����###�����##��������###�����##########����#########�");
    printf("\n �#����#####�##�##########�############�##�#####����#�������������####���������������������������������������������������");
    printf("\n �########################################�########@@��������������������������������������������������������������������");
    printf("\n ###########�######��#####�#######�#######�####@##@@@#�������#############################���############################");
    printf("\n �#####��###�######��##�##########��##########�#####���������������������������������������������������������������������");
    printf("\n ������#####�#############################�####��������������������������������������������������������������������������");
    printf("\n �����#####��#######�#############�#######��#@@##������������������������������������������������������������������������");
    printf("\n �����##�###�##############�#############��###@@##�����������������������������������������������������������������������");
    printf("\n �����#########�#################################������������������������������������������������������������������������");
    printf("\n ������#############����#######�����############�������������������������������������������������������������������������");
    printf("\n ��������#####################################���������������������������������������������������������������������������");
    printf("\n ����������#################################�����������������������������������������������������������������������������");
    printf("\n ��������������##########################��������������������������������������������������������������������������������");
    printf("\n ����������������###�#############��##�����������������������������������������������������������������������������������");
    printf("\n �����������������##�������##��������#�����������������������������������������������������������������������������������");
    printf("\n ������������������������������������������������������������������������������������������������������������������������");

    printf("\n\n");

    system("pause");
}

// SOBRE:
void sobre(){
    system("cls");
    printf("\n |=======================SOBRE=======================|");
    printf("\n Trabalho passado com o objetivo de criar um sistema  ");
    printf("\n de viagens, capaz de escolher seu destino, tanto pe- ");
    printf("\n la decis�o do cliente, quanto pela indecis�o a partir");
    printf("\n de perguntas que nortear�o o cliente a um destino    ");
    printf("\n espec�fico. Posteriormente, gravando a quantidade de ");
    printf("\n vezes que o cliente foi para cada destino.           ");
    printf("\n |===================================================|");

    printf("\n\n");

    system("pause");
}

// �RVORE DE DECIS�O:
void montar_arvore(Arvore** raiz){
    int n;

    // N�VEL 0:
    n = 16;
    *raiz = inserir_id(*raiz, n);

    // N�VEL 1:
    n = 8;
    *raiz = inserir_id(*raiz, n);
    n = 24;
    *raiz = inserir_id(*raiz, n);

    // N�VEL 2:
    n = 4;
    *raiz = inserir_id(*raiz, n);
    n = 12;
    *raiz = inserir_id(*raiz, n);
    n = 20;
    *raiz = inserir_id(*raiz, n);
    n = 28;
    *raiz = inserir_id(*raiz, n);

    // N�VEL 3:
    n = 2;
    *raiz = inserir_id(*raiz, n);
    n = 6;
    *raiz = inserir_id(*raiz, n);
    n = 10;
    *raiz = inserir_id(*raiz, n);
    n = 14;
    *raiz = inserir_id(*raiz, n);
    n = 18;
    *raiz = inserir_id(*raiz, n);
    n = 22;
    *raiz = inserir_id(*raiz, n);
    n = 26;
    *raiz = inserir_id(*raiz, n);
    n = 30;
    *raiz = inserir_id(*raiz, n);

    // N�VEL 4:
    n = 1;
    *raiz = inserir_id(*raiz, n);
    n = 3;
    *raiz = inserir_id(*raiz, n);
    n = 5;
    *raiz = inserir_id(*raiz, n);
    n = 7;
    *raiz = inserir_id(*raiz, n);
    n = 9;
    *raiz = inserir_id(*raiz, n);
    n = 11;
    *raiz = inserir_id(*raiz, n);
    n = 13;
    *raiz = inserir_id(*raiz, n);
    n = 15;
    *raiz = inserir_id(*raiz, n);
    n = 17;
    *raiz = inserir_id(*raiz, n);
    n = 19;
    *raiz = inserir_id(*raiz, n);
    n = 21;
    *raiz = inserir_id(*raiz, n);
    n = 23;
    *raiz = inserir_id(*raiz, n);
    n = 25;
    *raiz = inserir_id(*raiz, n);
    n = 27;
    *raiz = inserir_id(*raiz, n);
    n = 29;
    *raiz = inserir_id(*raiz, n);
    n = 31;
    *raiz = inserir_id(*raiz, n);

    //pre_ordem(raiz);
}

// INSERINDO NA �RVORE DE DECIS�O:
Arvore* inserir_id(Arvore* raiz, int n){
    if(raiz == NULL){
        raiz = (Arvore*)malloc(sizeof(Arvore));
        if(raiz == NULL){
            printf("\n Sem mem�ria");
            exit(1);
        }
        raiz->id = n;
        //printf("\n %d ", raiz->id);
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

// IMPRIMINDO �RVORE EM PRE ORDEM:(TESTE)
void pre_ordem(Arvore* raiz){
    if(raiz == NULL){
        return;
    }
    printf("\n %d ", raiz->id);
    pre_ordem(raiz->sim);
    pre_ordem(raiz->nao);
}

// C�DIGO/ID DA �RVORE DE DECIS�O:
void codigo(int id){
    // PERGUNTAS:
    if(id == 2){
        printf("\n| Gosta de parque aqu�tico? |\n");
    } else if(id == 4){
        printf("\n| Gosta de praia? |\n");
    } else if(id == 6){
        printf("\n| Tem interesse em pol�tica? |\n");
    } else if(id == 8){
        printf("\n| Deseja realizar uma viagem nacional? |\n");
    } else if(id == 10){
        printf("\n| Gosta de animais selvagens? |\n");
    } else if(id == 12){
        printf("\n| Gosta de ter experi�ncias pr�ximas a natureza? |\n");
    } else if(id == 14){
        printf("\n| Gosta de jogos de azar? |\n");
    } else if(id == 16){
        printf("\n| Gosta de calor? |\n");
    } else if(id == 18){
        printf("\n| Gosta de museus? |\n");
    } else if(id == 20){
        printf("\n| Gosta de realizar atividades na neve? |\n");
    } else if(id == 22){
        printf("\n| Gostaria de ter contato com o ber�o do catolicismo? |\n");
    } else if(id == 24){
        printf("\n| Deseja realizar uma viagem para a Europa? |\n");
    } else if(id == 26){
        printf("\n| Interesse na cultura latina? |\n");
    } else if(id == 28){
        printf("\n| Gosta de altura/montanhas? |\n");
    } else if(id == 30){
        printf("\n| Deseja ter contato com uma culin�ria �nica? |\n");
    }

    // CIDADES TUR�STICAS:
    if(id == 1){
        printf("\n Fortaleza");
    } else if(id == 3){
        printf("\n Salvador");
    } else if(id == 5){
        printf("\n Bras�lia");
    } else if(id == 7){
        printf("\n S�o Paulo");
    } else if(id == 9){
        printf("\n SAVANA(Decidir)");
    } else if(id == 11){
        printf("\n Cairo");
    } else if(id == 13){
        printf("\n Las Vegas");
    } else if(id == 15){
        printf("\n Orlando");
    } else if(id == 17){
        printf("\n S�o Petersburgo");
    } else if(id == 19){
        printf("\n Moscou");
    } else if(id == 21){
        printf("\n Roma");
    } else if(id == 23){
        printf("\n N�poles");
    } else if(id == 25){
        printf("\n Santiago");
    } else if(id == 27){
        printf("\n Chengdu");
    } else if(id == 29){
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
    atual->qtde_turista01 = 0;
    atual->qtde_turista02 = 0;
    atual->prox = NULL;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Estados Unidos");
    printf(" %s ", atual->nome);
    atual->qtde_turista01 = 0;
    atual->qtde_turista02 = 0;
    atual->prox = NULL;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "China");
    printf(" %s ", atual->nome);
    atual->qtde_turista01 = 0;
    atual->qtde_turista02 = 0;
    atual->prox = NULL;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Russia");
    printf(" %s ", atual->nome);
    atual->qtde_turista01 = 0;
    atual->qtde_turista02 = 0;
    atual->prox = NULL;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Italia");
    printf(" %s ", atual->nome);
    atual->qtde_turista01 = 0;
    atual->qtde_turista02 = 0;
    atual->prox = NULL;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Egito");
    printf(" %s ", atual->nome);
    atual->qtde_turista01 = 0;
    atual->qtde_turista02 = 0;
    atual->prox = NULL;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Chile");
    printf(" %s ", atual->nome);
    atual->qtde_turista01 = 0;
    atual->qtde_turista02 = 0;
    atual->prox = NULL;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Quenia");
    printf(" %s ", atual->nome);
    atual->qtde_turista01 = 0;
    atual->qtde_turista02 = 0;

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
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;

            atual = atual->baixo;
            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Fortaleza");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Sao Paulo");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Brasilia");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
        } else if(strcmp(atual->nome, "Estados Unidos") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Orlando");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;

            atual = atual->baixo;
            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Las Vegas");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Nova York");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
        } else if(strcmp(atual->nome, "China") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Chengdu");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;

            atual = atual->baixo;
            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Macau");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
        } else if(strcmp(atual->nome, "Russia") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Sao Petersburgo");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;

            atual = atual->baixo;
            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Moscou");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
        } else if(strcmp(atual->nome, "Italia") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Chengdu");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;

            atual = atual->baixo;
            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Macau");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
        } else if(strcmp(atual->nome, "Egito") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Cairo");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
        } else if(strcmp(atual->nome, "Chile") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Santiago");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
        } else if(strcmp(atual->nome, "Quenia") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Nairobi");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
        }
        atual = aux;
        aux = aux->prox;
        atual = atual->prox;
    }

	printf("\n Lista inicializada! \n");
	system("pause");
}

// CLIENTE DECIDIDO:
void cliente01(Lista **inicio){
    imprimir_cidades(*inicio);

    printf("\n ESCOLHA QUAL CIDADE TUR�SRICA VOC� DESEJA VISITAR: ");

}

void imprimir_cidades(Lista *inicio){

}

// CLIENTE INDECISO:
void cliente02(Lista **inicio, Arvore *raiz){
    // DECLARA��O DE VARI�VEIS:
    char resposta[RESP];
    int manter = 0;
    Arvore *aux;
    Lista *atual;
    Lista *auy;

    aux = raiz;
    atual = *inicio;
    auy = *inicio;

    // RESPOSTAS DA �RVORE DE DECIS�O:
    while(manter == 0){
        raiz = aux;
        while((raiz->sim != NULL) && (raiz->nao != NULL)){
            system("cls||clear");

            printf(" RESPOSTAS (sim/nao) \n\n");
            codigo(raiz->id);
            fgets(resposta, RESP, stdin);
            resposta[strcspn(resposta, "\n")] = '\0';

            if(strcasecmp(resposta, "sim") == 0){
                raiz = raiz->sim;
            }else if(strcasecmp(resposta, "nao") == 0){
                raiz = raiz->nao;
            }else{
                printf("\n Op��o Inv�lida!\n");
                system("pause");
            }
        }
        while(1){
            printf("\n O destino recomendado foi: ");
            codigo(raiz->id);
            printf("\n Gostaria de manter esse destino para sua viagem? (sim/nao) \n");
            if(strcasecmp(resposta, "sim") == 0){
                manter = 1;
                break;
            }else if(strcasecmp(resposta, "nao") == 0){
                manter = 0;
                break;
            }else{
                printf("\n Op��o Inv�lida!\n");
                system("pause");
                system("cls||clear");
            }
        }
    }

    // INTERANDO NA LISTA: (BOTAR EM UMA FUN��O SEARADA);
    while(atual != NULL){
        if(strcasecmp(codigo(raiz->id), atual->nome) == 0){
            atual->qtde_turista02 ++;
            auy->qtde_turista02 ++;
        }
        if(atual->baixo == NULL){
            auy = auy->prox;
            atual = auy;
        }else{
            atual = atual->baixo;
        }
    }
}


