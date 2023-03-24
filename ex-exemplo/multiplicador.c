#include <stdio.h>
#include <stdlib.h>

float **aloca (int linhas, int colunas){

  int i;
  float **mat;

  mat = malloc(linhas * sizeof(float*));

  for(i=0;i<linhas;i++){
    mat[i] = malloc (colunas * sizeof (float));
  }

  return mat;
}

void leitura (float **mat, int linhas, int colunas){
   int i,j;
   for (i=0; i < linhas; i++){
    for (j=0; j < colunas; j++){
      printf("mat[%d][%d]: ", i,j);
      scanf("%f", &mat[i][j]);
        }
      }
   return;
}

float **multiplica (float **matA, int linhaA, int colunaA, float **matB, int linhaB, int colunaB){
 int i,j,k,aux=0;

 float **matresult = aloca (linhaA, colunaB);

  for (i=0; i < linhaA; i++){
   for (j=0; j < colunaB; j++){
      matresult[i][j] = 0;
      for(k=0; k<colunaA; k++){
        aux += matA[i][k] * matB[k][j];
      }
       matresult[i][j] = aux;
       aux = 0;
      }
  }

   return matresult;
}



void imprime (float **matriz, int linhas, int colunas){
  int i, j;
  for(i=0; i<linhas; i++) {
    for(j=0;j<colunas; j++) {
        printf("%.1f ", matriz[i][j]);
		}
		printf("\n");
	}

	printf("\n\n");

   return;
}

void desaloca (float **matriz, int linhas){
  int i;
  for(i=0; i<linhas; i++){
    free(matriz[i]);
  }
  free(matriz);
  return;
}



int main(){

   float **m1 = aloca(2,3);
   leitura(m1,2,3);

   printf("\n\n");

   float **m2 = aloca(3,4);
   leitura(m2,3,4);

   float **m3 = multiplica(m1,2,3,m2,3,4);

   imprime(m1,2,3);
   imprime(m2,3,4);
   imprime(m3,2,4);

   desaloca(m1,2);
   desaloca(m2,3);
   desaloca(m3,2);

   return 0;
}