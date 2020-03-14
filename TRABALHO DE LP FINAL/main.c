#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ia.h"
#include <time.h>
#include "IAmedia.h"
#include "IAbaixa.h"

int main(){
    int modo;
    printf("\n---------------JOGO DA ATRIBUICAO DE TAREFA-------------------\n");
    printf("\no jogo consiste em descobrir qual funcionario ira fazer determinada tarefa de modo quer o tempo necessario seja o menor\n REGRAS:\n 1 - UM FUNCIONARIO SO PODERA REALIZAR UMA UNICA TAREFA.\n 2 - UMA TAREFA NAO PODE SER REALIZADA POR DOIS FUNCIONARIOS AO MESMO TEMPO.\n");
    printf("\nESCOLHA MODO DE JOGO:\n 1 - PLAYER  2 - IA\n");
    scanf("%d", &modo);
    int bota;

    if(modo == 1){
        int dificuldade;
	FILE *ptr = NULL;
	char player[20];
	printf("\ninsira seu nome jogador: ");
	scanf("%s", player);
	printf("Informe a dificuldade : \n1 - Facil\n2 - Medio\n3 - Dificil\nDigite:\n");
	scanf("%i", &dificuldade);


	switch(dificuldade){
        case(1):
           ptr = fopen("atribuicao_10.txt", "r");
           //TABELA PRA MOSTRAR NA TELA
            FILE* matriz = NULL;
            matriz = fopen("matrizprintar10.txt","r");
            char str[1000];

            while(fgets(str,1000,matriz)!= NULL){
                printf("%s",str);
            }
            bota = 10;
            break;
        case(2):
            ptr = fopen("atribuicao_20.txt", "r");
             //TABELA PRA MOSTRAR NA TELA
            FILE* matriz2 = NULL;
            matriz2 = fopen("matrizprintar20.txt","r");
            char str2[1000];

            while(fgets(str2,1000,matriz2)!= NULL){
                printf("%s",str2);
            }
            bota = 20;
            break;
        case(3):
            ptr = fopen("atribuicao_30.txt", "r");
             //TABELA PRA MOSTRAR NA TELA
            FILE* matriz3 = NULL;
            matriz3 = fopen("matrizprintar30.txt","r");
            char str3[1000];

            while(fgets(str3,1000,matriz3)!= NULL){
                printf("%s",str3);
            }
            bota = 30;
            break;
        default:
            ptr = NULL;
            printf("Falha, dificuldade nao cadastrada!");
            return -1;
	}

        int tentativa= 0;
        int resultadoreal10[10]={2,4,7,5,6,8,0,9,1,3};
        int resultadoreal20[20] = {5,15,7,2,17,18,14,8,1,4,9,19,3,16,13,11,6,12,10,0};
        int resultadoreal30[30] = {22,13,25,8,5,21,18,29,16,15,24,14,6,20,0,9,7,1,23,27,2,4,28,10,11,19,26,3,12,17};
        int resultado[bota];

        int k,i;
        int fun[10];
        int tentativas = 0;

        FILE *score;
        score = fopen("score.txt", "a");

        for(k = 0; k < 1000; k++){
            for(i = 0; i < 10; i++){
                printf("%s atribua a tarefa para o funcionario %d: \n",player, i);
                scanf("%d", &fun[i]);
            }
            int cont = 0;
            for(i = 0; i < 10; i++){
                if(fun[i] == resultadoreal10[i]){
                    cont++;
                }else{
                    printf("\nSEQUENCIA ERRADA\n");
                    tentativas++;
                    break;
                }
            }
            if(cont == 10){
                tentativas++;
                break;
            }
        }

        fprintf(score, "%s: %d\n",player,tentativas);

        printf("PARABENS VOCE ACERTOU E PRECISOU DE %d TENTATIVAS\n", tentativas);

        FILE* ponto = NULL;
            ponto = fopen("score.txt","r");
            char strA[1000];

            while(fgets(strA,1000,ponto)!= NULL){
                printf("%s",strA);
            }

    }


    if(modo == 2){


    int dificuldade;
	FILE *ptr = NULL;
	printf("Informe a dificuldade : \n1 - Facil\n2 - Medio\n3 - Dificil\nDigite:\n");
	scanf("%i", &dificuldade);

	switch(dificuldade){
        case(1):
           ptr = fopen("atribuicao_10.txt", "r");
           //TABELA PRA MOSTRAR NA TELA
            FILE* matriz = NULL;
            matriz = fopen("matrizprintar10.txt","r");
            char str[1000];

            while(fgets(str,1000,matriz)!= NULL){
                printf("%s",str);
            }
            break;
        case(2):
            ptr = fopen("atribuicao_20.txt", "r");
             //TABELA PRA MOSTRAR NA TELA
            FILE* matriz2 = NULL;
            matriz2 = fopen("matrizprintar20.txt","r");
            char str2[1000];

            while(fgets(str2,1000,matriz2)!= NULL){
                printf("%s",str2);
            }
            break;
        case(3):
            ptr = fopen("atribuicao_30.txt", "r");
             //TABELA PRA MOSTRAR NA TELA
            FILE* matriz3 = NULL;
            matriz3 = fopen("matrizprintar30.txt","r");
            char str3[1000];

            while(fgets(str3,1000,matriz3)!= NULL){
                printf("%s",str3);
            }
            break;
        default:
            ptr = NULL;
            printf("Falha, dificuldade nao cadastrada!");
            return -1;
	}




//}

	int qtd = 0;
	int aux;
	int i = 0 ;
	int j = 0;
	int **mat;
	fscanf(ptr,"%d",&qtd);
	int func[10] = {0,1,2,3,4,5,6,7,8,9};



	mat = (int**)malloc(sizeof(int*)*qtd);
	for(i = 0 ; i < qtd; i++){
		mat[i] = (int*)malloc(sizeof(int)*qtd);

	}




printf("\n");

	for(i = 0 ; i < qtd; i++){
		for(j = 0 ; j < qtd; j++){
		 fscanf(ptr,"%d",&aux);
			mat[i][j] = aux;
		}
	}


printf("\n");

 // Seleção do nivel da IA
        int ia;
        printf("\nQUAL O NIVEL DE INTELIGENCIA DA IA?\n 1 - Inteligente 2 - Media 3 - Burra\n");
        scanf("%d", &ia);



        int sum = 0 ;
        int tentativas = 0;
        if(ia == 2){
            algoritmoMedio(mat,qtd);
            printf("\n");

            ia = 1 + rand()%3;
        } else if(ia == 3){
            algoritmoBaixo(qtd);
            printf("\n");
            }
            if(ia == 1){
            algortimo(mat,qtd);
            printf("\n");
            return 0;
            }
    }
}

