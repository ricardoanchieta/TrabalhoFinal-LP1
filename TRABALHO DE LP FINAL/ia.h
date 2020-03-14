#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int getValue(int qtd, int* vet,int** mat){
	int i = 0 ;
	int sum = 0;
	 for(i =0 ; i<qtd;i++){
	 	sum+=mat[vet[i]] [i];
	 }
	 return sum;

}

void printMat(int** mat , int qtd){
	int i,j;
	for(i = 0 ; i < qtd; i++){
		for(j = 0 ; j < qtd; j++){
		 printf("    %d",mat[i][j]);
		}
		printf("\n");

	}


}
int getMinValue(int* vet,int tam){
	int smaller = vet[0];
	for (int i = 1 ; i < tam; i++){
		if(smaller > vet[i]){
			smaller = vet[i];
		}
	}
	return smaller;
}


int getMinValueColum(int** vet, int tam, int j){
	int smaller = vet[0][j];
	for (int i = 1 ; i < tam; i++){
		if(smaller > vet[i][j]){
			smaller = vet[i][j];
		}
	}
	return smaller;
}


int getNumZeroline(int* vet,int tam){
	int i;
	int sum = 0;
	for(i = 0 ; i <tam ; i++ ){
		if(vet[i] == 0){
			sum += 1;
		}
	}
	return sum;
}

int getNumZeroColum(int** mat,int tam,int j){
	int i;
	int sum = 0;
	for(i = 0 ; i <tam ; i++ ){
		if(mat[i][j] == 0){
			sum += 1;
		}
	}

	return sum;
}

int getNum1line(int* vet,int tam){
	int i;
	int sum = 0;
	for(i = 0 ; i <tam ; i++ ){
		if(vet[i] == -1){
			sum += 1;
		}
	}
	return sum;
}

int getNum1Colum(int** mat,int tam,int j){
	int i;
	int sum = 0;
	for(i = 0 ; i <tam ; i++ ){
		if(mat[i][j] == -1){
			sum += 1;
		}
	}

	return sum;
}







void algortimo(int** mat, int tam){
	int i,j, k, minValue;
	int flagLine = 1,flagColum = 1;
	int** aux = mat;
	int zeroLine[tam], zeroColum[tam];
	int max;
	int index;
	int sumZero = 0;
	int **auxMat;
	int sumZeroLine = 0;
	int sumZeroColum = 0;
	int row[tam];
	int colum[tam];
	int lines = 0;
	int w = 0;
	int smaller2 = 50000;
		int flagSmall =0 ;
do{

		int lines = 0;
	for(i = 0 ; i < tam; i ++){
		row[i] = 0;
		colum[i] = 0;
		minValue =  getMinValue(mat[i],tam);
		for(j = 0 ; j < tam; j ++){
			mat[i][j] -= minValue;
		}
	}


	for(i = 0 ; i < tam; i ++){
		minValue =  getMinValueColum(mat,tam,i);
		for(j = 0 ; j < tam; j ++){
			mat[j][i] -= minValue;
		}
	}
	for(i = 0 ;  i < tam;i ++){
		zeroLine[i] = getNumZeroline(mat[i],tam);
		zeroColum[i] = getNumZeroColum(mat,tam,i);

		sumZero += zeroLine[i]+zeroColum[i];

	}
	int auxSum = 0;

	sumZero = sumZero/2;
	for(i = 0 ; i < tam; i ++){
		for(j = 0 ; j < tam; j ++){
			if(mat[j][i] == 0){

				auxSum +=1;

			}
		}
	}


	if(zeroLine[0] >zeroColum[0] )
	{
		flagLine = 0;
		max = zeroLine[0];
		index = 0;
	}else{
		flagColum = 0;
		max = zeroColum[0];
		index = 0;
	}

	for(i = 0 ;i < tam; i ++  ){
		for(j = 0 ;  j < tam;j ++ ){
			if(mat[i][j] == 0){
					lines = lines +1;

					sumZeroLine = getNumZeroline(mat[i],tam);
					sumZeroColum = getNumZeroColum(mat,tam,j);


					if(sumZeroLine >= sumZeroColum){
						for(w = 0 ; w < tam ;w ++){
							if(mat[i][w] == 0){
								mat[i][w] = -1;
								row[i] = 1;
							}

						}
					}else
					{
						for(w = 0 ; w < tam ;w ++){
							if(mat[w][j] == 0){
								mat[w][j] = -1;
								colum[j] = 1;
							}

						}

					}





		}
	}













		// if(zeroLine[i] > max )
		// {
		// 	flagLine = 0;
		// 	flagColum =1;
		// 	max = zeroLine[i];
		// 	index = i;
		// }else{
		// 	flagLine = 1 ;
		// 	flagColum  = 0;
		// 	max = zeroColum[i];
		// 	index = i;
		// }
	}


	if(lines != tam){

			for(i = 0 ; i < tam; i ++){
				for (k = 0 ; k < tam; k++){
					if(row[i] == 0 && colum[k] == 0){
						if(flagSmall == 0){
							smaller2 = mat[i][k];

							flagSmall = 1;
						}else{

							if(smaller2>mat[i][k]){
								smaller2 = mat[i][k];

							}

						}

					}

				}
			}

			for(i = 0 ; i < tam; i ++){
				for (k = 0 ; k < tam; k++){
					if(mat[i][k] == -1){
						mat[i][k] = 0;
					}
				}}



			for(i = 0 ; i < tam; i ++){
				for (k = 0 ; k < tam; k++){
					if(row[i] == 0){

						mat[i][k] = mat[i][k]-smaller2;

					}

				}
			}




				for(i = 0 ; i < tam; i ++){
				for (k = 0 ; k < tam; k++){
					if(colum[i] == 1){
						mat[k][i] = mat[k][i]+smaller2;

					}

				}
			}




	}
	int ks;
	//scanf("%d",&ks);
	if(lines == tam){

		break;


	}

}while(tam!=lines);




	int result[tam];
	int m,n;
	int flag = 0;
	printf("start\n");
		for (i = 0; i < tam; i ++){

		 result[i] =-1;
	}

	while(flag == 0){

flag = 1;

	for(i = 0 ; i < tam; i++){
		for(j = 0 ; j < tam; j++){


			if(mat[i][j] == -1){


				if(getNum1line(mat[i],tam) !=1 && getNum1Colum(mat,tam,j)!=1 ){


				}else{
				result[j] = i;

			for(m = 0 ; m<tam ; m ++){
				mat[m][j] = 0;
			}
			for(m = 0 ; m<tam ; m ++){
				mat[i][m] = 0;
			}


			}
		}

			}

	}

	for(i = 0 ; i <tam; i++){
		if(result[i] == -1){

			flag = 0;

		}

	}
}

	printf("resultado\n");
	for(i = 0 ; i < tam;i++){
		printf("tarefa %d funcionario %d \n", i,result[i]);



	}



	printf("\nlines%d\n",lines);




}

	/*
´para cada linha da matriz, encontre o menor elemento e subtraia-o de cada elemento em sua linha.
Faça o mesmo (como etapa 1) para todas as colunas.
Cubra todos os zeros na matriz usando o número mínimo de linhas horizontais e verticais.
Teste de otimização: se o número mínimo de linhas de cobertura for n, uma atribuição ideal é possível e estamos concluídos. Caso contrário, se as linhas forem menores que n, não encontramos a atribuição ideal e devemos prosseguir
	 para a etapa 5.
Determine a menor entrada não coberta por nenhuma linha. Subtraia essa entrada de cada linha descoberta e adicione-a a cada coluna coberta. Volte para a etapa 3.





	*/
