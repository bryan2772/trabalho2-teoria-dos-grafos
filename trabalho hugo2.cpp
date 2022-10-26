#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//fila
typedef struct TipoCelula *TipoApontador; 

typedef struct TipoItem { 
	int num;
} TipoItem;

typedef struct TipoCelula {
	TipoItem Item;
	TipoApontador Prox;
} TipoCelula; 

typedef struct TipoFila {
	TipoApontador Frente, Tras;
}TipoFila;

void FFVazia(TipoFila *Fila ) { 
	Fila ->Frente = (TipoApontador) malloc(sizeof(TipoCelula )); 
	Fila ->Tras = Fila ->Frente; 
	Fila ->Frente ->Prox = NULL; 
}

int Vazia(TipoFila Fila ) { 
	return ( Fila.Frente == Fila.Tras) ;
}

void Enfileira (TipoItem x, TipoFila *Fila ) { 
	Fila ->Tras ->Prox = (TipoApontador) malloc(sizeof(TipoCelula )); 
	Fila ->Tras = Fila ->Tras ->Prox;
	Fila ->Tras ->Item = x; 
	Fila ->Tras ->Prox = NULL; 
}

void Desenfileira(TipoFila *Fila , TipoItem *Item) { 
	TipoApontador q; 
	if (Vazia( *Fila ) ) { 
		printf ( "Erro fila esta vazia\n" ) ; return;
	} 
	q = Fila ->Frente; 
	Fila ->Frente = Fila ->Frente ->Prox; 
	*Item = Fila ->Frente ->Item; 
	free(q); 
}

void exibe (TipoFila fila){
	TipoApontador aux=fila.Frente->Prox;
	while(aux!=NULL){
		printf("%d ", aux->Item.num);
		aux=aux->Prox;
	}
}
//fim fila

void imprime(int **mat, int N){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){	      
	        printf("%d\t", mat[i][j]);
    	}
		printf("\n");
    }
	printf("\n");
}

void BFS(int **mat, int N){
	TipoItem i, item; TipoFila fila; FFVazia(&fila);
    int alcancado[N];
	for(int i=0; i<N; i++)
		alcancado[i]=0;
    
    for(int k=0; k<N; k++)
		for(int j=0; j<N; j++)
	        if(mat[j][k] != 0){
	        	for(int l=0; l<N; l++){	
					alcancado[j]=1;
				}
	        	i.num=j;
	        	Enfileira(i, &fila); 
	        	k=N; j=N;
			}
	exibe(fila); printf("\n");

    while(!Vazia(fila)){
    	i.num=fila.Frente->Prox->Item.num;
    	Desenfileira(&fila, &i);
    	for(int j=0; j<N; j++){
			if(mat[i.num][j]!=0 && alcancado[j]!=1){
				alcancado[j]=1;
		    	item.num=j;
				Enfileira(item, &fila);
			} 
			exibe(fila); printf("\n");
		}
	}
	
}

void Preenchimento(int **mat, int N, int porc, int direc, int k){
	FILE *arq;
	int resultado;
	char Str[50];

	arq = fopen("graph.dat", "w");

	if (arq == NULL){
		printf("Problemas na CRIACAO do arquivo\n");
		return;
	}

	fprintf(arq,"%d\t%d\n",k, porc);

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

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){	      
	        if(mat[i][j]!=0){
				fprintf(arq,"%d\t%d\t%d\n",i,j, mat[i][j]);
			}
    	}
    }
	
	fclose(arq);
}


int main(){
	
	int **mat, N, k, porcentagem, direcionado;
	float d;
	printf("Digite um valor para N: "); scanf("%d", &N); //de 3 a 10000000
	printf("Digite um valor para d: "); scanf("%f", &d); //0.2 a 1
	printf("O grafo � direcionado ou  n�o?\n1-sim\t2-nao\t"); scanf("%d", &direcionado);
	 
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
    
	Preenchimento(mat, N, porcentagem, direcionado, k);

    imprime(mat, N);
    
    /*int test[8][8]={0,1,1,0,1,0,0,0, 1,0,0,1,0,1,0,0, 1,0,0,1,0,0,1,0, 0,1,1,0,0,0,0,1,	1,0,0,0,0,1,1,0, 0,1,0,0,1,0,0,1, 0,0,1,0,1,0,0,1, 0,0,0,1,0,1,1,0};
    printf("\n");
	int test[6][6]={0,1,1,0,0,0, 0,0,0,1,0,0, 0,0,0,0,0,1, 0,0,0,0,1,1, 1,1,0,1,0,0, 0,0,1,0,1,0};
    for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){	      
	        printf("%d\t", test[i][j]);
    	}
		printf("\n");	
    }*/
    
    BFS(mat, N);

    printf("\nfim\n");
	
	return 0;
}
