#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#define MAXSIZE 1001
using namespace std;
typedef struct{
	int V_num;
	int E_num;
	int Matrix[MAXSIZE][MAXSIZE];
}Graph,*GRAPH;

bool BFS(GRAPH G){
	queue<int> Q;
	int p = 1;
	Q.push(p);
	int Depth = 1;
	int pre_child = 1;
	int b_child = 0;
	vector<int> D(G->V_num+1,0);
	while(!Q.empty()){
		b_child = pre_child;
		pre_child = 0;
		for(int i=0; i<b_child; ++i){
			p = Q.front();
			Q.pop();
			D[p] = Depth;
			for(int i=1; i<=G->V_num; ++i){
				if(G->Matrix[p][i] == 1 && p!=i){
					if(D[i] != 0 && D[i] < D[p]-1)
						return true;
					if(D[i] == 0){
						Q.push(i);
						pre_child++;
					}
				}
			}
		}
		Depth++;
	}
	return false;
}

bool Process(GRAPH G){
	return BFS(G);
}

int main(){
	int N,M;
	GRAPH G;
	int v1,v2;
	while( scanf("%d %d",&N,&M) != EOF ){
		if(N==0)
			break;
		G = (Graph*)malloc(sizeof(Graph));
		G->V_num = N;
		G->E_num = M;
		for(int i=1; i<=N; ++i)
			for(int j=i; j<=N; ++j)
				G->Matrix[i][j] = G->Matrix[j][i] = 0;
		for(int i=0; i<M; ++i){
			scanf("%d %d",&v1,&v2);
			G->Matrix[v1][v2] = G->Matrix[v2][v1] = 1;
		}
		if( Process(G) )
			printf("1\n");
		else
			printf("0\n");
		free(G);
		G = NULL;
	}
}
