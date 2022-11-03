#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Estrutura Pilha est�tica
typedef struct TipoItem
{
	int num;
} TipoItem;

typedef struct TipoCelula2 *TipoApontador2;

typedef struct TipoCelula2
{
	TipoItem Item;
	TipoApontador2 Prox;
} TipoCelula2;

typedef struct
{
	TipoApontador2 Fundo, Topo;
	int Tamanho;
} TipoPilha;

// Fun��es de manipula��o da pilha din�mica

void FPVazia(TipoPilha *Pilha)
{
	Pilha->Topo = (TipoApontador2)malloc(sizeof(TipoCelula2));
	Pilha->Fundo = Pilha->Topo;
	Pilha->Topo->Prox = NULL;
	Pilha->Tamanho = 0;
}

int Vazia2(TipoPilha Pilha)
{
	return (Pilha.Topo == Pilha.Fundo);
}

void Empilha(TipoItem x, TipoPilha *Pilha)
{
	TipoApontador2 Aux;
	Aux = (TipoApontador2)malloc(sizeof(TipoCelula2));
	Pilha->Topo->Item = x;
	Aux->Prox = Pilha->Topo;
	Pilha->Topo = Aux;
	Pilha->Tamanho++;
}

void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{
	TipoApontador2 q;
	if (Vazia2(*Pilha))
	{
		printf("Erro : pilha vazia\n");
		return;
	}
	q = Pilha->Topo;
	Pilha->Topo = q->Prox;
	*Item = q->Prox->Item;
	free(q);
	Pilha->Tamanho--;
}

int Tamanho(TipoPilha Pilha)
{
	return (Pilha.Tamanho);
}

void exibePilha(TipoPilha pilha)
{
	TipoApontador2 aux = pilha.Topo->Prox;
	while (aux != NULL)
	{
		printf("\n%d", aux->Item.num);
		aux = aux->Prox;
	}
}
// fim das estruturas de pilha

void pausa()
{ // funçao de pausaro sistema
	int ch;
	while ((ch = fgetc(stdin)) != EOF && ch != '\n')
		; // ja limpa o buffer antes
	printf("\nPressione qualquer tecla para continuar...");
	scanf("%*c"); // não PRECISO LIMPAR O BUFFER porque O USUARIO não VAI DIGITAR NADA
}

void fflush_stdin()
{ // funçao que limpa o buff
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF)
		;
}

// fila
typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula
{
	TipoItem Item;
	TipoApontador Prox;
} TipoCelula;

typedef struct TipoFila
{
	TipoApontador Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila)
{
	Fila->Frente = (TipoApontador)malloc(sizeof(TipoCelula));
	Fila->Tras = Fila->Frente;
	Fila->Frente->Prox = NULL;
}

int Vazia(TipoFila Fila)
{
	return (Fila.Frente == Fila.Tras);
}

void Enfileira(TipoItem x, TipoFila *Fila)
{
	Fila->Tras->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
	Fila->Tras = Fila->Tras->Prox;
	Fila->Tras->Item = x;
	Fila->Tras->Prox = NULL;
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{
	TipoApontador q;
	if (Vazia(*Fila))
	{
		printf("Erro fila esta vazia\n");
		return;
	}
	q = Fila->Frente;
	Fila->Frente = Fila->Frente->Prox;
	*Item = Fila->Frente->Item;
	free(q);
}

void exibe(TipoFila fila)
{
	TipoApontador aux = fila.Frente->Prox;
	while (aux != NULL)
	{
		printf("%d ", aux->Item.num);
		aux = aux->Prox;
	}
}
// fim fila

void imprime(int **mat, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void BFS(int **mat, int N,int ordem){
	TipoItem i, item;
	TipoFila fila;
	FFVazia(&fila);
	int alcancado[N];
	for (int i = 0; i < N; i++)
		alcancado[i] = 0;

	for (int k = 0; k < N; k++) // procura um valor para i
		for (int j = 0; j < N; j++)
			if (mat[j][k] != 0){
				for (int l = 0; l < N; l++){
					alcancado[j] = 1;
				}
				i.num = j;
				Enfileira(i, &fila); // enfileire i e marque-o como alcançado (visitado);
				k = N;
				j = N;
			}
	exibe(fila);
	printf("\n"); // inicio BFS

	if(ordem==1){
		while (!Vazia(fila)){										 // enquanto (fila ≠ ∅)) faça
			i.num = fila.Frente->Prox->Item.num; // i ← vértice da frente da fila;
			Desenfileira(&fila, &i);			 // desenfileire i;
			for (int j = 0; j < N; j++)
			{ //∀ aresta (i,j), tal que j ainda não foi alcançado faça
				if (mat[i.num][j] != 0 && alcancado[j] != 1)
				{
					alcancado[j] = 1; // marque j como alcançado;
					item.num = j;
					Enfileira(item, &fila); // enfileire j;
				}
				exibe(fila);
				printf("\n");
			}
		} // fim BFS
	}else{
		while (!Vazia(fila)){										 // enquanto (fila ≠ ∅)) faça
			i.num = fila.Frente->Prox->Item.num; // i ← vértice da frente da fila;
			Desenfileira(&fila, &i);			 // desenfileire i;
			for (int j = N-1; j >= 0; j--)
			{ //∀ aresta (i,j), tal que j ainda não foi alcançado faça
				if (mat[i.num][j] != 0 && alcancado[j] != 1)
				{
					alcancado[j] = 1; // marque j como alcançado;
					item.num = j;
					Enfileira(item, &fila); // enfileire j;
				}
				exibe(fila);
				printf("\n");
			}
		} // fim BFS decrecente
	}
}

void DFS(int **mat, int N,int ordem)
{
	TipoItem i, item;
	TipoPilha pilha;
	FPVazia(&pilha);
	int alcancado[N];
	for (int i = 0; i < N; i++)
		alcancado[i] = 0;

	for (int k = 0; k < N; k++) // procura um valor para i
		for (int j = 0; j < N; j++)
			if (mat[j][k] != 0)
			{
				for (int l = 0; l < N; l++)
				{
					alcancado[j] = 1;
				}
				i.num = j;
				Empilha(i, &pilha); // enfileire i e marque-o como alcançado (visitado);
				k = N;
				j = N;
			}
	/*i.num=4;
	Empilha(i, &pilha);
	alcancado[i.num]=1;*/

	exibePilha(pilha);
	printf("\n"); // inicio BFS
	int j = 0, aux2 = 0;
	if(ordem==1){
		while (!Vazia2(pilha)){
			aux2 = 0;							// enquanto (fila ≠ ∅)) faça
			i.num = pilha.Topo->Prox->Item.num; // i ← vértice da frente da fila;
			for (int j = 0; j < N; j++)
			{ //∀ aresta (i,j), tal que j ainda não foi alcançado faça
				if (mat[i.num][j] != 0 && alcancado[j] != 1)
				{
					alcancado[j] = 1; // marque j como alcançado;
					item.num = j;
					Empilha(item, &pilha);
					j = N; // enfileire j;
					aux2 = 1;
				}
			}
			// exibePilha(pilha); printf("\n");
			if (aux2 == 0)
			{
				Desempilha(&pilha, &i);
			}
			exibePilha(pilha);
			printf("\n");
		} // fim DFS
	}else{
		while (!Vazia2(pilha)){
			aux2 = 0;							// enquanto (fila ≠ ∅)) faça
			i.num = pilha.Topo->Prox->Item.num; // i ← vértice da frente da fila;
			for (int j = N-1; j >= 0; j--)
			{ //∀ aresta (i,j), tal que j ainda não foi alcançado faça
				if (mat[i.num][j] != 0 && alcancado[j] != 1){
					alcancado[j] = 1; // marque j como alcançado;
					item.num = j;
					Empilha(item, &pilha);
					j = N; // enfileire j;
					aux2 = 1;
				}
			}
			// exibePilha(pilha); printf("\n");
			if (aux2 == 0)
			{
				Desempilha(&pilha, &i);
			}
			exibePilha(pilha);
			printf("\n");
		} // fim DFS
	}
}

void Dijkstra(int **mat, int N){
	int c[N], d[N], i, pos = 0, menor = 1001, v, l = 0, w, tam = 0;
	for (int i = 0; i < N; i++)
		c[i] = d[i] = 0;
	for (int k = 0; k < N; k++) // procura um valor para i
		for (int j = 0; j < N; j++)
			if (mat[k][j] != 0){
				i = k;
				k = N;
				j = N;
			}

	for (int j = 0; j < N; j++) // inicio dijkstra
		if (mat[i][j] != 0){ // C ← {V – {i}};
			c[pos] = j;
			pos++;
			tam++;
		}
	for (int j = 0; j < N; j++){						// para j de 1 até n faça
		if (mat[i][j] == 0) // D[ j ] ← Mat[i][j];
			d[j] = 2147483647;
		else
			d[j] = mat[i][j];
	}
	for (int k = 0; k < (N - 2); k++){ // repita n – 2 vezes
		menor = 1001;
		l = 0;
		for (int i = 0; i < N; i++){ // v ← elemento de C que minimiza D[v];
			if (d[i] < menor && c[l] != -1){
				menor = d[i];
				pos = i;
			}
			if (d[i] <= 1000)
				l++;
		} //
		v = pos;
		for (int i = 0; i < tam; i++)
			if (c[i] == v){ // C ← C – {v};
				c[i] = -1;
			}
		for (int i = 0; i < tam; i++){ // para cada elemento w ∈ C faça
			if (c[i] != -1){
				w = c[i];
				if (mat[v][w] == 0) // D[w] ← min(D[w], D[v] + Mat[v][w])
					mat[v][w] = 2000000000;
				if (d[w] > (d[v] + mat[v][w]))
					d[w] = d[v] + mat[v][w];
				// d[w]=min_element(d[w], d[v] + mat[v][w]);
			}
		}
	} // fim dijkstra

	printf("\nc: ");
	for (int i = 0; i < N; i++)
		printf("%d ", c[i]);
	printf("\nd: ");
	for (int i = 0; i < N; i++)
		printf("%d ", d[i]);
}

void BellmanFord(int **mat, int N){
	int d[N], i, v, cont = 0, vet[N];

	for (int i = 0; i < N; i++)
		d[i] = vet[i] = 0;
	for (int k = 0; k < N; k++) // procura um valor para i
		for (int j = 0; j < N; j++)
			if (mat[k][j] != 0){
				i = v = k;
				vet[v] = 1;
				k = N;
				j = N;
			}

	for (int j = 0; j < N; j++)
		d[j] = 2000000000;
	d[i] = 0;
	for (int j = 0; j < N - 1; j++){
		for (int w = 0; w < N; w++){
			if (mat[v][w] != 0){
				if (mat[v][w] == 0){ // D[w] ← min(D[w], D[v] + Mat[v][w])
					mat[v][w] = 2000000000;
					cont = 1;
				}
				if (d[w] > (d[v] + mat[v][w]))
					d[w] = d[v] + mat[v][w];
				if (cont == 1){
					mat[v][w] = 0;
					cont = 0;
				}
			}

			printf("\n");
			for (int i = 0; i < N; i++)
				printf("%d ", d[i]);
		}
		for (int i = 0; i < N; i++)
			if (vet[i] != 1)
				for (int j = 0; j < N; j++)
					if (mat[i][j] != 0){
						v = i;
						vet[v] = 1;
						i = N;
						j = N;
					}
	}
}

void FloydWarshall(int **mat, int N){
	int **d;
	d = static_cast<int **>(malloc(N * sizeof(int *))); // aloca a matriz dinamicamente
	for (int i = 0; i < N; i++)
		d[i] = static_cast<int *>(malloc(N * sizeof(int)));
	srand(time(NULL));

	for (int i = 0; i < N; i++) // D ← Mat;
		for (int j = 0; j < N; j++)
			d[i][j] = mat[i][j];

	for (int k = 0; k < N; k++){									// para k de 1 até n faça
		for (int i = 0; i < N; i++)		// para i de 1 até n faça
			for (int j = 0; j < N; j++) // para j de 1 até n faça
				if (d[i][j] > d[i][k] + d[k][j])
					d[i][j] = d[i][k] + d[k][j]; // D[i][j] ← min(D[i][j], D[i][k] + D[k][j]);
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%d\t", d[i][j]);
		}
		printf("\n");
	}
}

void Preenchimento(int **mat, int N, int porc, int direc, int k){
	FILE *arq;

	arq = fopen("graph.dat", "wb");

	if(arq == NULL){
		printf("Problemas na CRIACAO do arquivo\n");
		return;
	}

	fprintf(arq, "%d\t%d\n", N, porc);

	int l, c, tam = N, tam2 = N - 1;
	srand(time(NULL));
	if (direc == 1){
		for (int i = 0; i < porc; i++){
			l = rand() % tam;
			c = l;
			while (c == l){
				c = rand() % tam;
				if (mat[l][c] != 0 && l != c){
					l = rand() % tam2;
					c = l;
				}
			}
			mat[l][c] = rand() % 1000;
		}
	}
	if (direc == 2){
		for (int i = 0; i < porc; i++){
			l = rand() % tam2;
			c = l;
			while (c == l || c < l){
				c = rand() % tam;
				if (mat[l][c] != 0 && l != c){
					l = rand() % tam2;
					c = l;
				}
			}
			mat[l][c] = mat[c][l] = rand() % 1000;
		}
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (mat[i][j] != 0){
				fprintf(arq, "%d\t%d\t%d\n", i, j, mat[i][j]);
			}
		}
	}

	fclose(arq);
}

int main(){
	int **mat, N, k, porcentagem, direcionado, op = 1, i,j,peso,ordem=0;
	float d; clock_t t;

	while (op != 0){ // laço para gerir a hora de sair do menu

		printf("\nMENU\n0- Sair\n1-Gerar matriz de grafo \n2-Executar o algoritmo bfs e DFS\n3-Executar o algoritmo bellmanford\n4-Executar o algoritmo de Dijkstra\n5-Executar o algoritmo de FloydWarshall\n6-exibe a matriz\n7-ler uma matriz do arquivo .dat\n");
		scanf("%d", &op);
		system("clear||cls"); // limpar a tela

		switch (op){ // switch para seleçao de qual opçao seguir
		case 1:
			printf("Digite um valor para N: ");N=0;
			while(N<3||N>10000000){
				scanf("%d", &N); // de 3 a 10000000
				if(N<3||N>10000000){
					printf("Valor para N inaceitavel, Digite um valor entre 3 a 10000000\n");
				}
				
			}
			printf("Digite um valor para d: ");d=0;
			while(d<0.2||d>1){
				scanf("%f", &d); // 0.2 a 1
				if(d<0.2||d>1){
					printf("Valor para d inaceitavel, Digite um valor entre 0.2 a 1\n");
				}
				
			}
			printf("O grafo é direcionado ou nao?\n1-sim\t2-nao\t");direcionado=0;
			while(direcionado<1||direcionado>2){
				scanf("%d", &direcionado);
				if(direcionado<1||direcionado>2){
					printf("opçao invalida, Digite 1-sim ou 2-nao\n");
				}
				
			}

			t = clock();
			mat = static_cast<int **>(malloc(N * sizeof(int *))); // aloca a matriz dinamicamente
			for (int i = 0; i < N; i++)
				mat[i] = static_cast<int *>(malloc(N * sizeof(int)));
			srand(time(NULL));

			for (int i = 0; i < N; i++){ // zera toda a matriz
				for (int j = 0; j < N; j++)
				{
					mat[i][j] = 0;
				}
			}

			k = ((N * N) - N) / 2;
			porcentagem = k * d; // calcula a quantidade de arestas com base na porcentagem
			printf("\n%d %d\n", k, porcentagem);
			Preenchimento(mat, N, porcentagem, direcionado, k); // gera a matriz
			t = clock()-t;
			printf("\nTempo de geraçao do grafo em segundos : %.19f\n", ((double)t)/((CLOCKS_PER_SEC)));
			imprime(mat, N);
			pausa();
			break;

		case 2:
			printf("\n[1]ordem crescente ou [2]ordem decrescente\n");
				scanf("%d",&ordem);
			t = clock();
				BFS(mat, N, ordem);
			t = clock()-t;
			printf("\nTempo de execucao do BFS em segundos : %.19f\n", ((double)t)/((CLOCKS_PER_SEC)));
			printf("Tempo de execucao do BFS em milessegundos: %.19f\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			
			t = clock();
				DFS(mat, N, ordem);
			t = clock()-t;
			printf("\nTempo de execucao do DFS em segundos : %.19f\n", ((double)t)/((CLOCKS_PER_SEC)));
			printf("Tempo de execucao do DFS em milessegundos: %.19f\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			pausa();
			break;

		case 3:
			t = clock();
				BellmanFord(mat, N);
			t = clock()-t;
			printf("\nTempo de execucao do BellmanFord em segundos : %.19f\n", ((double)t)/((CLOCKS_PER_SEC)));
			printf("Tempo de execucao do BellmanFord em milessegundos: %.19f\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			pausa();
			break;

		case 4:
			t = clock();
				Dijkstra(mat, N);
			t = clock()-t;
			printf("\nTempo de execucao do Dijkstra em segundos : %.19f\n", ((double)t)/((CLOCKS_PER_SEC)));
			printf("Tempo de execucao do Dijkstra em milessegundos: %.19f\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			printf("\n\n");
			pausa();
			break;

		case 5:
			t = clock();
				FloydWarshall(mat, N);
			t = clock()-t;
			printf("\nTempo de execucao do FloydWarshall em segundos : %.19f\n", ((double)t)/((CLOCKS_PER_SEC)));
			printf("Tempo de execucao do FloydWarshall em milessegundos: %.19f\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
			pausa();
			break;

		case 6:
			imprime(mat, N);
			pausa();
			break;

		case 7:
			// opçao para ler um arquivo .dat
			t = clock();
			FILE *arq2;

			arq2 = fopen("graph.dat", "r");

			if(arq2 == NULL){
				printf("Problemas na abertura do arquivo\n");
			}

			fscanf(arq2, "%d", &N); // de 3 a 10000000
			fscanf(arq2, "%d", &porcentagem); // 0.2 a 1
			free(mat);

			mat = static_cast<int **>(malloc(N * sizeof(int *))); // aloca a matriz dinamicamente
			for(int i = 0; i < N; i++)
				mat[i] = static_cast<int *>(malloc(N * sizeof(int)));
			srand(time(NULL));

			for(int i = 0; i < N; i++){ // zera toda a matriz
				for (int j = 0; j < N; j++){
					mat[i][j] = 0;
				}
			}i=j=0;

			while(!feof(arq2)){	
				fscanf(arq2, "%d", &i);
				fscanf(arq2, "%d", &j);
				fscanf(arq2, "%d", &peso); 
				mat[i][j]=peso;
			}
			t = clock()-t;
			k = ((N * N) - N) / 2;
			d=porcentagem/k;//porcentagem = k * d; // calcula a quantidade de arestas com base na porcentagem
			printf("\nTempo de leitura do grafo.dat em segundos : %.19f", ((double)t)/((CLOCKS_PER_SEC)));
			printf("\narestas:%d quantidade da porcentagem:%d\n", k, porcentagem);
			imprime(mat, N);
			pausa();
			fclose(arq2);
			break;

		default:
			printf("\nsaindoo...\n");
			pausa();
			break;
		}
		system("clear||cls");
	}

	return 0;
}