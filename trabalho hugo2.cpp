#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprime(int **mat, int N){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){	      
	        printf("%d\t", mat[i][j]);
    	}
		printf("\n");
    }
}

void Preenchimento(int **mat, int N, int porc, int direc){
	int l, c, tam=N, tam2=N-1;
	srand(time(NULL));
	if(direc==1){
		for(int i=0; i<porc; i++){
			l=rand() % tam; 
			c=l;
			while(c==l){
				c=rand() % tam;
				if(mat[l][c]!=0 && l!=c){
					l=rand() % tam2;
					c=l;
				}
				
			}
			mat[l][c]=rand()%1000;
		}
	}
	if(direc==2){
		for(int i=0; i<porc; i++){
			l=rand() % tam2; 
			c=l;
			while(c==l || c<l){
				c=rand() % tam;
				if(mat[l][c]!=0 && l!=c){
					l=rand() % tam2;
					c=l;
				}
				
			}
			mat[l][c]=mat[c][l]=rand()%1000;
		}
	}
}


int main(){
	
	int **mat, N, k, porcentagem, direcionado;
	float d;
	printf("Digite um valor para N: "); scanf("%d", &N); //de 3 a 10000000
	printf("Digite um valor para d: "); scanf("%f", &d); //0.2 a 1
	printf("O grafo é direcionado ou  não?\n1-sim\t2-nao\t"); scanf("%d", &direcionado);
	 
    mat = static_cast<int* *>(malloc(N * sizeof(int*)));
    for(int i = 0; i < N; i++)
        mat[i] = static_cast<int *> (malloc(N * sizeof(int)));
    srand(time(NULL));

    for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){	      
	        mat[i][j] = 0;
    	}	
    }
    
    k=((N*N)-N)/2; porcentagem=k*d;
    printf("\n%d %d\n", k, porcentagem);
    
	Preenchimento(mat, N, porcentagem, direcionado);

    imprime(mat, N);

    printf("\nfim\n");
	
	return 0;
}
