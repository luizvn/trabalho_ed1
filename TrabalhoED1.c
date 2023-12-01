#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // BIBLIOTECA NECESSÁRIA PARA USAR OS CARACTERES DO PORTUGUÊS

// ======= DEFINES =======
#define TAM 50
#define RESP 4

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
void montar_arvore(Arvore **);
Arvore* inserir_id(Arvore *, int);
void pre_ordem(Arvore *);
void cliente01(Lista **);
void cliente02(Lista **, Arvore *);
void visitados(Lista *);
void imprimir_lista(Lista *);

// ======= MAIN =======

int main(){
    setlocale(LC_ALL, "Portuguese");

    int op;
    Lista *inicio;
    Arvore *raiz;

    inicio = NULL;
    raiz = NULL;

    // MONTANDO LISTA E ÁRVORE DE DECISÃO:
    montar_lista(&inicio);
    montar_arvore(&raiz);

    system("pause");
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
        printf("\n |2 - Sou Indeciso! Não sei que lugar escolher           |");
        printf("\n |3 - Lista de Paises/Cidades Visitados/Não Visitados    |");
        printf("\n |4 - Paises Visitados por clientes decididos            |");
        printf("\n |5 - Paises Visitados por clientes Indecisos            |");
        printf("\n |6 - Países que não foram Visitados ainda               |");
        printf("\n |7 - País mais visitado pelo cliente Decidido           |");
        printf("\n |8 - País mais visitado pelo cliente Ideciso            |");
        printf("\n |9 - Sair do Sistema                                    |");
        printf("\n |=======================================================|");
        printf("\n ESCOLHA A OPÇÃO: ");
        scanf("%d", &op);

        switch(op){
        case 1:
            cliente01(&inicio);
            system("pause");
            break;
        case 2:
            cliente02(&inicio, raiz);
            system("pause");
            break;
        case 3:
            visitados(inicio);
            system("pause");
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
void montar_arvore(Arvore** raiz){
    int n;

    // NÍVEL 0:
    n = 16;
    *raiz = inserir_id(*raiz, n);

    // NÍVEL 1:
    n = 8;
    *raiz = inserir_id(*raiz, n);
    n = 24;
    *raiz = inserir_id(*raiz, n);

    // NÍVEL 2:
    n = 4;
    *raiz = inserir_id(*raiz, n);
    n = 12;
    *raiz = inserir_id(*raiz, n);
    n = 20;
    *raiz = inserir_id(*raiz, n);
    n = 28;
    *raiz = inserir_id(*raiz, n);

    // NÍVEL 3:
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

    // NÍVEL 4:
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

// INSERINDO NA ÁRVORE DE DECISÃO:
Arvore* inserir_id(Arvore* raiz, int n){
    if(raiz == NULL){
        raiz = (Arvore*)malloc(sizeof(Arvore));
        if(raiz == NULL){
            printf("\n Sem memória");
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

// IMPRIMINDO ÁRVORE EM PRE ORDEM:(TESTE)
void pre_ordem(Arvore* raiz){
    if(raiz == NULL){
        return;
    }
    printf("\n %d ", raiz->id);
    pre_ordem(raiz->sim);
    pre_ordem(raiz->nao);
}

// CÓDIGO/ID DA ÁRVORE DE DECISÃO:
char* codigo(int id){
    // DECLARAÇÃO DE VARIÁVEIS:
    char* cidade;
    cidade = (char*)malloc(TAM*sizeof(char));
    // PERGUNTAS:
    if(id == 2){
        printf("\n| Gosta de parque aquático? |\n");
    } else if(id == 4){
        printf("\n| Gosta de praia? |\n");
    } else if(id == 6){
        printf("\n| Tem interesse em política? |\n");
    } else if(id == 8){
        printf("\n| Deseja realizar uma viagem nacional? |\n");
    } else if(id == 10){
        printf("\n| Gosta de animais selvagens? |\n");
    } else if(id == 12){
        printf("\n| Gosta de ter experiências próximas a natureza? |\n");
    } else if(id == 14){
        printf("\n| Gosta de jogos de azar? |\n");
    } else if(id == 16){
        printf("\n| Gosta de calor? |\n");
    } else if(id == 18){
        printf("\n| Gosta de museus? |\n");
    } else if(id == 20){
        printf("\n| Gosta de realizar atividades na neve? |\n");
    } else if(id == 22){
        printf("\n| Gostaria de ter contato com o berço do catolicismo? |\n");
    } else if(id == 24){
        printf("\n| Deseja realizar uma viagem para a Europa? |\n");
    } else if(id == 26){
        printf("\n| Interesse na cultura latina? |\n");
    } else if(id == 28){
        printf("\n| Gosta de altura/montanhas? |\n");
    } else if(id == 30){
        printf("\n| Deseja ter contato com uma culinária única? |\n");
    }

    // CIDADES TURÍSTICAS:
    if(id == 1){
        printf("\n Fortaleza");
        strcpy(cidade, "Fortaleza");
        return (cidade);
    } else if(id == 3){
        printf("\n Salvador");
        strcpy(cidade, "Salvador");
        return (cidade);
    } else if(id == 5){
        printf("\n Brasília");
        strcpy(cidade, "Brasilia");
        return (cidade);
    } else if(id == 7){
        printf("\n São Paulo");
        strcpy(cidade, "Sao Paulo");
        return (cidade);
    } else if(id == 9){
        printf("\n Nairóbi");
        strcpy(cidade, "Nairobi");
        return (cidade);
    } else if(id == 11){
        printf("\n Cairo");
        strcpy(cidade, "Cairo");
        return (cidade);
    } else if(id == 13){
        printf("\n Las Vegas");
        strcpy(cidade, "Las Vegas");
        return (cidade);
    } else if(id == 15){
        printf("\n Orlando");
        strcpy(cidade, "Orlando");
        return (cidade);
    } else if(id == 17){
        printf("\n São Petersburgo");
        strcpy(cidade, "Sao Petersburgo");
    } else if(id == 19){
        printf("\n Moscou");
        strcpy(cidade, "Moscou");
        return (cidade);
    } else if(id == 21){
        printf("\n Roma");
        strcpy(cidade, "Roma");
        return (cidade);
    } else if(id == 23){
        printf("\n Nápoles");
        strcpy(cidade, "Napoles");
        return (cidade);
    } else if(id == 25){
        printf("\n Santiago");
        strcpy(cidade, "Santiago");
        return (cidade);
    } else if(id == 27){
        printf("\n Chengdu");
        strcpy(cidade, "Chengdu");
        return (cidade);
    } else if(id == 29){
        printf("\n Macau");
        strcpy(cidade, "Macau");
        return (cidade);
    } else if(id == 31){
        printf("\n Nova York");
        strcpy(cidade, "Nova York");
        return (cidade);
    }
    return NULL;
}

// MONTAR LISTA
void montar_lista(Lista **inicio){
	Lista *atual, *aux, *ant;

    atual = (Lista*)malloc(sizeof(Lista));

    aux = atual;

    strcpy(atual->nome, "Brasil");
    printf(" %s ", atual->nome);
    atual->qtde_turista01 = 0;
    atual->qtde_turista02 = 0;
    atual->prox = NULL;
    ant = atual;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Estados Unidos");
    printf(" %s ", atual->nome);
    atual->qtde_turista01 = 0;
    atual->qtde_turista02 = 0;
    atual->prox = NULL;
    ant->prox = atual;
    ant = atual;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "China");
    printf(" %s ", atual->nome);
    atual->qtde_turista01 = 0;
    atual->qtde_turista02 = 0;
    atual->prox = NULL;
    ant->prox = atual;
    ant = atual;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Russia");
    printf(" %s ", atual->nome);
    atual->qtde_turista01 = 0;
    atual->qtde_turista02 = 0;
    atual->prox = NULL;
    ant->prox = atual;
    ant = atual;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Italia");
    printf(" %s ", atual->nome);
    atual->qtde_turista01 = 0;
    atual->qtde_turista02 = 0;
    atual->prox = NULL;
    ant->prox = atual;
    ant = atual;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Egito");
    printf(" %s ", atual->nome);
    atual->qtde_turista01 = 0;
    atual->qtde_turista02 = 0;
    atual->prox = NULL;
    ant->prox = atual;
    ant = atual;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Chile");
    printf(" %s ", atual->nome);
    atual->qtde_turista01 = 0;
    atual->qtde_turista02 = 0;
    atual->prox = NULL;
    ant->prox = atual;
    ant = atual;
    atual = atual->prox;

    atual = (Lista*)malloc(sizeof(Lista));

    //atual = *inicio;
    strcpy(atual->nome, "Quenia");
    printf(" %s \n", atual->nome);
    atual->qtde_turista01 = 0;
    atual->qtde_turista02 = 0;

    atual->prox = NULL;
    ant->prox = atual;
    ant = atual;
    atual = atual->prox;

    *inicio = aux;

    atual = *inicio;
    aux = atual;
    ant = atual;

    while(atual != NULL){
        if(strcmp(atual->nome,"Brasil") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Salvador");
            printf(" %s ", atual->nome);
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            ant->baixo = atual;
            ant = atual;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Fortaleza");
            printf(" %s ", atual->nome);
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            ant->baixo = atual;
            ant = atual;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Sao Paulo");
            printf(" %s ", atual->nome);
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            ant->baixo = atual;
            ant = atual;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Brasilia");
            printf(" %s ", atual->nome);
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            ant->baixo = atual;
            ant = atual;
        } else if(strcmp(atual->nome, "Estados Unidos") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Orlando");
            printf(" %s ", atual->nome);
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            ant->baixo = atual;
            ant = atual;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Las Vegas");
            printf(" %s ", atual->nome);
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            ant->baixo = atual;
            ant = atual;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Nova York");
            printf(" %s ", atual->nome);
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            ant->baixo = atual;
            ant = atual;
        } else if(strcmp(atual->nome, "China") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Chengdu");
            printf(" %s ", atual->nome);
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            ant->baixo = atual;
            ant = atual;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Macau");
            printf(" %s ", atual->nome);
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            ant->baixo = atual;
            ant = atual;
        } else if(strcmp(atual->nome, "Russia") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Sao Petersburgo");
            printf(" %s ", atual->nome);
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            ant->baixo = atual;
            ant = atual;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Moscou");
            printf(" %s ", atual->nome);
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            ant->baixo = atual;
            ant = atual;
        } else if(strcmp(atual->nome, "Italia") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Roma");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            ant->baixo = atual;
            ant = atual;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Napoles");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            ant->baixo = atual;
            ant = atual;
        } else if(strcmp(atual->nome, "Egito") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Cairo");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            ant->baixo = atual;
            ant = atual;
        } else if(strcmp(atual->nome, "Chile") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Santiago");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            ant->baixo = atual;
            ant = atual;
        } else if(strcmp(atual->nome, "Quenia") == 0){
            atual->baixo = NULL;
            atual = atual->baixo;

            atual = (Lista*)malloc(sizeof(Lista));
            strcpy(atual->nome, "Nairobi");
            atual->qtde_turista01 = 0;
            atual->qtde_turista02 = 0;
            atual->baixo = NULL;
            ant->baixo = atual;
            ant = atual;
        }
        atual = aux;
        aux = aux->prox;
        atual = atual->prox;
        ant = atual;
        printf("\n 2");
    }

	printf("\n Lista inicializada! \n");
	system("pause");
}

// CLIENTE DECIDIDO:
void cliente01(Lista **inicio){
    // DECLARAÇÃO DE VARIÁVEIS:
    char cidade[TAM];
    int manter = 0;
    Lista *atual, *aux;

    atual = *inicio;
    aux = atual;

    // ESCOLHA DE CIDADE TURÍSTICA:
    while(manter == 0){
        system("cls||clear");

        atual = *inicio;
        aux = atual;
        imprimir_lista(*inicio);

        printf("\n ESCOLHA QUAL CIDADE TURÍSRICA VOCÊ DESEJA VISITAR: ");
        fgets(cidade, TAM, stdin);
        cidade[strcspn(cidade, "\n")] = '\0';

        printf(" %s ", cidade);
        // ITERANDO:
        while(atual != NULL){
            if(strcasecmp(cidade, atual->nome) == 0){
                atual->qtde_turista01 ++;
                aux->qtde_turista01 ++;
                manter = 1;
                break;
            }
            if(atual->baixo == NULL){
                aux = aux->prox;
                atual = aux;
            }else{
                atual = atual->baixo;
            }
        }
        if(manter == 0){
            printf("\n Resposta inválida!\n");
            system("pause");
        }
    }

}

void imprimir_lista(Lista *inicio){
    Lista *atual, *aux;
    atual = inicio;

    while(atual != NULL){
        aux = atual;
        printf("\n %s :", atual->nome);
        if(atual->baixo != NULL){
            while(atual->baixo != NULL){
                atual = atual->baixo;
                printf(" %s ", atual->nome);
            }
            atual = aux;
        }
        atual = atual->prox;
    }
    printf("\n ");
}

// CLIENTE INDECISO:
void cliente02(Lista **inicio, Arvore *raiz){
    // DECLARAÇÃO DE VARIÁVEIS:
    char resposta[RESP];
    int manter = 0;
    Arvore *aux;
    Lista *atual;
    Lista *auy;

    aux = raiz;
    atual = *inicio;
    auy = *inicio;

    // RESPOSTAS DA ÁRVORE DE DECISÃO:
    while(manter == 0){
        raiz = aux;
        while((raiz->sim != NULL) && (raiz->nao != NULL)){
            system("cls||clear");

            printf(" RESPOSTAS (sim/nao) \n\n");
            codigo(raiz->id);
            fgets(resposta, RESP, stdin);
            resposta[strcspn(resposta, "\n")] = '\0';

            printf("\n %s \n", resposta);

            if(strcasecmp(resposta, "sim") == 0){
                raiz = raiz->sim;
            }else if(strcasecmp(resposta, "nao") == 0){
                raiz = raiz->nao;
            }else{
                printf("\n Opção Inválida!\n");
                system("pause");
            }
        }
        while(1){
            printf("\n O destino recomendado foi: %s ", codigo(raiz->id));
            //codigo(raiz->id);
            printf("\n Gostaria de manter esse destino para sua viagem? (sim/nao) \n");
            fgets(resposta, RESP, stdin);
            resposta[strcspn(resposta, "\n")] = '\0';

            if(strcasecmp(resposta, "sim") == 0){
                manter = 1;
                break;
            }else if(strcasecmp(resposta, "nao") == 0){
                manter = 0;
                break;
            }else{
                printf("\n Opção Inválida!\n");
                system("pause");
                system("cls||clear");
            }
        }
    }

    // ITERANDO NA LISTA: (BOTAR EM UMA FUNÇÃO SEARADA);
    while(atual != NULL){
        printf("\n 1");
        if(strcasecmp(codigo(raiz->id), atual->nome) == 0){
            printf("\n 2");
            atual->qtde_turista02 ++;
            auy->qtde_turista02 ++;
        }
        printf("\n 3");
        if(atual->baixo == NULL){
            printf("\n 4");
            auy = auy->prox;
            atual = auy;
        }else{
            printf("\n 5");
            atual = atual->baixo;
        }
        printf("\n 6");
    }
    system("pause");
}

void visitados(Lista *inicio){
    Lista *atual;
    Lista *aux;
    atual = inicio;
    aux = atual;

    if(atual == NULL){
        printf("\n Lista Vazia!\n");
        system("pause");
        return;
    }

    while(atual != NULL){
        printf("\n ====================");
        printf("\n Nome: %s       ", atual->nome);
        printf("\n Cliente 01: %d ", atual->qtde_turista01);
        printf("\n Cliente 02: %d ", atual->qtde_turista02);
        printf("\n --------------------");
        if(atual->baixo == NULL){
            aux = aux->prox;
            atual = aux;
        }else{
            atual = atual->baixo;
        }
    }
    printf("\n ====================\n");
    system("pause");
}


