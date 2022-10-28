#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <time.h>
#include <string.h>
#include <math.h>
using namespace std;

// Estrutura Pilha est�tica
typedef struct { 
    char chave; 
}TipoItem2; 

typedef struct TipoCelula2 *TipoApontador2; 

typedef struct TipoCelula2 { 
	TipoItem2 Item; 
	TipoApontador2 Prox; 
} TipoCelula2; 

typedef struct { 
	TipoApontador2  Fundo, Topo; 
	int Tamanho; 
} TipoPilha;

// Fun��es de manipula��o da pilha din�mica

void FPVazia(TipoPilha *Pilha) { 
	Pilha ->Topo=(TipoApontador2) malloc(sizeof(TipoCelula2)); 
	Pilha ->Fundo = Pilha ->Topo; 
	Pilha ->Topo->Prox = NULL; 
	Pilha ->Tamanho = 0; 
}

int Vazia(TipoPilha Pilha) {
	return ( Pilha .Topo == Pilha .Fundo) ; 
}

void Empilha(TipoItem2 x, TipoPilha *Pilha) { 
	TipoApontador2 Aux; 
	Aux = (TipoApontador2) malloc(sizeof(TipoCelula2)); 
	Pilha ->Topo->Item = x; 
	Aux->Prox = Pilha ->Topo; 
	Pilha ->Topo = Aux; 	
	Pilha ->Tamanho++; 
}

void Desempilha(TipoPilha *Pilha , TipoItem2 *Item) {
	TipoApontador2 q; 
	if (Vazia( *Pilha ) ) { 
		printf ( "Erro : lista vazia\n" ) ; 	return; 
	} 
	q = Pilha ->Topo; 
	Pilha ->Topo = q ->Prox; 
	*Item = q ->Prox->Item; 
	free(q) ;
	Pilha ->Tamanho--; 
}

int Tamanho(TipoPilha Pilha) { 
	return ( Pilha .Tamanho) ; 
}

void exibePilha(TipoPilha pilha){
	TipoApontador2 aux=pilha.Topo->Prox;
	while(aux!=NULL){
		printf("\n%c", aux->Item.chave);
		aux=aux->Prox;
	}
}
//fim das estruturas de pilha

void pausa(){//funçao de pausaro sistema
    int ch;
    while((ch = fgetc(stdin)) != EOF && ch != '\n');//ja limpa o buffer antes
    printf ("\nPressione qualquer tecla para continuar...");
    scanf("%*c");//não PRECISO LIMPAR O BUFFER porque O USUARIO não VAI DIGITAR NADA
}

void fflush_stdin(){//funçao que limpa o buff
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

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
    
    for(int k=0; k<N; k++)	//procura um valor para i
		for(int j=0; j<N; j++)
	        if(mat[j][k] != 0){
	        	for(int l=0; l<N; l++){	
					alcancado[j]=1;
				}
	        	i.num=j;
	        	Enfileira(i, &fila); 		//enfileire i e marque-o como alcançado (visitado);
	        	k=N; j=N;
			}
	exibe(fila); printf("\n");	//inicio BFS

    while(!Vazia(fila)){		//enquanto (fila ≠ ∅)) faça
    	i.num=fila.Frente->Prox->Item.num;		//i ← vértice da frente da fila;
    	Desenfileira(&fila, &i);		//desenfileire i;
    	for(int j=0; j<N; j++){		//∀ aresta (i,j), tal que j ainda não foi alcançado faça
			if(mat[i.num][j]!=0 && alcancado[j]!=1){
				alcancado[j]=1;		//marque j como alcançado;
		    	item.num=j;
				Enfileira(item, &fila);		//enfileire j;
			} 
			exibe(fila); printf("\n");
		}
	}	//fim BFS
}

void DFS(int **mat, int N){
	TipoItem2 i, item; TipoPilha pilha; FPVazia(&pilha);
    int alcancado[N];
	for(int i=0; i<N; i++)
		alcancado[i]=0;
    
   	//fim DFS
}

void Dijkstra(int **mat, int N){
	int c[N], d[N], i, pos=0, menor=1001, v, l=0, w, tam=0;
	for(int i=0; i<N; i++)
		c[i]=d[i]=0;
	for(int k=0; k<N; k++)		//procura um valor para i
		for(int j=0; j<N; j++)
	        if(mat[k][j] != 0){
	        	i=k;
	        	k=N; j=N;
			}

	for(int j=0; j<N; j++)		//inicio dijkstra
		if(mat[i][j]!=0){		//C ← {V – {i}};
			c[pos]=j;
			pos++; tam++;
		}
	for(int j=0; j<N; j++){		//para j de 1 até n faça
		if(mat[i][j]==0)		//D[ j ] ← Mat[i][j];
			d[j]=2147483647;
		else
			d[j]=mat[i][j];
	}
	for(int k=0; k<(N-2); k++){		//repita n – 2 vezes
		menor=1001; l=0;
		for(int i=0;i<N;i++){			//v ← elemento de C que minimiza D[v];
			if(d[i]<menor && c[l]!=-1){
				menor=d[i];
				pos=i;
			}
			if(d[i]<=1000)
				l++;
		}							//
		v=pos;
		for(int i=0; i<tam; i++)
			if(c[i]==v){			//C ← C – {v};
				c[i]=-1;
			}
		for(int i=0; i<tam; i++){		//para cada elemento w ∈ C faça
			if(c[i]!=-1){	
				w=c[i];
				if(mat[v][w]==0)			//D[w] ← min(D[w], D[v] + Mat[v][w])
					mat[v][w]=2000000000;
				if(d[w]>(d[v]+mat[v][w]))
					d[w]=d[v]+mat[v][w];
				//d[w]=min_element(d[w], d[v] + mat[v][w]);
			}
		}
	}		//fim dijkstra
		
	printf("\nc: ");
	for(int i=0;i<N;i++)
		printf("%d ", c[i]);
	printf("\nd: ");
	for(int i=0;i<N;i++)
		printf("%d ", d[i]);
}

void Preenchimento(int **mat, int N, int porc, int direc, int k){
	FILE *arq;

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
	
	int **mat, N, k, porcentagem, direcionado, op=1;
	float d;

	while(op!=0){//laço para gerir a hora de sair do menu 
        
        printf("\nMENU\n0- Sair\n1-Gerar matriz de grafo \n2-Executar o algoritmo bfs\n3-Executar o algoritmo DFS\n4-Executar o algoritmo deDijkstra\n5-exibe a matriz\n6-ler uma matriz do arquivo .dat\n");
        scanf("%d",&op);
        system("clear||cls");//limpar a tela

        switch (op){//switch para seleçao de qual opçao seguir
            case 1:
                printf("Digite um valor para N: "); scanf("%d", &N); //de 3 a 10000000
				printf("Digite um valor para d: "); scanf("%f", &d); //0.2 a 1
				printf("O grafo � direcionado ou  n�o?\n1-sim\t2-nao\t"); scanf("%d", &direcionado);
				
				mat = static_cast<int* *>(malloc(N * sizeof(int*)));//aloca a matriz dinamicamente
				for(int i = 0; i < N; i++)
					mat[i] = static_cast<int *> (malloc(N * sizeof(int)));
				srand(time(NULL));

				for(int i=0; i<N; i++){//zera toda a matriz
					for(int j=0; j<N; j++){	      
						mat[i][j] = 0;
					}	
				}
				
				k=((N*N)-N)/2; porcentagem=k*d;//calcula a quantidade de arestas com base na porcentagem
				printf("\n%d %d\n", k, porcentagem);
				
				Preenchimento(mat, N, porcentagem, direcionado, k);//gera a matriz
				imprime(mat, N);
    
                pausa();
            break;

            case 2:
				BFS(mat, N);
                pausa();
                
            break;

			case 3:
				DFS(mat, N);
                pausa();
                
            break;

			 case 4: 
				Dijkstra(mat, N);
				printf("\n\n");
                pausa();
                
            break;
			 case 5: 
				imprime(mat, N);
                pausa();
                
            break;
			 case 6: 
				/*opçao para ler um arquivo .dat*/
                
                pausa();
                
            break;

            default:
                printf("\nsaindoo...\n");
                pausa();
                
            break;
        }
        system("clear||cls");
    }
   
    /*int test[8][8]={0,1,1,0,1,0,0,0, 1,0,0,1,0,1,0,0, 1,0,0,1,0,0,1,0, 0,1,1,0,0,0,0,1,	1,0,0,0,0,1,1,0, 0,1,0,0,1,0,0,1, 0,0,1,0,1,0,0,1, 0,0,0,1,0,1,1,0};
    printf("\n"); //bfs
	int test[6][6]={0,1,1,0,0,0, 0,0,0,1,0,0, 0,0,0,0,0,1, 0,0,0,0,1,1, 1,1,0,1,0,0, 0,0,1,0,1,0};
	int test[5][5]={0,50,30,100,10, 0,0,0,0,0, 0,5,0,50,0, 0,20,0,0,0, 0,0,0,10,0};
    for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){	      
	        printf("%d\t", test[i][j]);
    	}
		printf("\n");	
    }*/

    printf("\nfim\n");
	
	return 0;
}
