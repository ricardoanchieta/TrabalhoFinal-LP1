void algoritmoMedio(int** mat,int tam){

    int minX = 0;
    int minY = 0;
    int  resultado[tam];

   for(int k = 0; k < tam; k++){
        for(int i = 0; i <tam; i++){
            for(int j = 0; j<tam; j++){
                if(mat[i][j] <= mat [minX][minY]){
                    minX = i;
                    minY = j;
                }
            }

        }
  //   printf("%d ", mat[minX][minY]);
        //printf("%d ", minX);
        resultado[minY] = minX;
            for(int jj = 0;jj<tam;jj++){
                mat[minX][jj] = 10000000;
        }
        for(int jj = 0;jj<tam;jj++){
                mat[jj][minY] = 10000000;
        }


   }

   //for(int i = 0; i < 10;i++){
     //   for(int j = 0; j<10;j++){
       //     printf(" %d ", matriz[i][j]);
        //}
   //}

  for(int i = 0; i<tam;i++){
    printf("TAREFA %d FUNCIONARIO %d\n ",i, resultado[i]);
   }

}
