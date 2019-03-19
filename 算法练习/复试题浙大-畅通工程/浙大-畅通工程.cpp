#include<iostream>
#include<vector>
#include<cstdlib>
#include<stack>
#define MAXSIZE 101
#define INFINITE 65535
using namespace std;
typedef struct{
	int V_num;
	int E_num;
	int Matrix[MAXSIZE][MAXSIZE];
}Graph,*GRAPH;

bool Is_Connected(GRAPH G){
	vector<bool> visited(G->V_num+1,false);
	stack<int> S;
	int p = 1;
	S.push(p);
	while(!S.empty()){
		p = S.top();
		S.pop();
		if(!visited[p]){
			visited[p] = true;
			for(int i=1; i<=G->V_num; ++i){
				if(G->Matrix[p][i] != INFINITE && !visited[i] && p!=i)
					S.push(i);
			}
		}
	}
	for(int i=1; i<=G->V_num; ++i)
		if(!visited[i])
			return false;
	return true;
}

int Process(GRAPH G){
	int lowest_cost = 0;
	vector<int> lowcost(G->V_num+1);
	vector<int> adjvertex(G->V_num+1,1);
	for(int i=1; i<=G->V_num; ++i){
		lowcost[i] = G->Matrix[1][i];
	}
	lowcost[1] = 0;
	int min = INFINITE;
	int k;
	for(int i=1; i<G->V_num; ++i){
		min = INFINITE;
		for(int j=1; j<lowcost.size(); ++j){
			if(lowcost[j] < min && lowcost[j]!=0){
				min = lowcost[j];
				k = j;
			}
		}
		lowest_cost += G->Matrix[ adjvertex[k] ][k];
		lowcost[k] = 0;
		for(int j=1; j<lowcost.size(); ++j){
			if(lowcost[j] > G->Matrix[k][j] && lowcost[j]!=0 ){
				lowcost[j] = G->Matrix[k][j];
				adjvertex[j] = k;
			}
		}
	}
	return lowest_cost;
}

void Crt_Graph(GRAPH G){
	int N = G->V_num;
	int E = G->E_num;
	int v1,v2,path;
	for(int i=1; i<=N; ++i){
		for(int j=i; j<=N; ++j){
			if(i==j)
				G->Matrix[i][j] = G->Matrix[j][i] = 0;
			else
				G->Matrix[i][j] = G->Matrix[j][i] = INFINITE;
		}
	}
	for(int i=1; i<=E; ++i){
		scanf("%d %d %d",&v1,&v2,&path);
		if(G->Matrix[v1][v2] > path)
			G->Matrix[v1][v2] = G->Matrix[v2][v1] = path;
	}
	for(int i=1; i<=N; ++i)
		G->Matrix[i][i] = 0;
	return;
}

int main(){
	GRAPH G = NULL;
	int M,N;
	int lowest_cost;
	while(scanf("%d %d",&M,&N) != EOF){
		if(N == 0 || M == 0)
			break;
		G = (Graph*)malloc(sizeof(Graph));
		G->V_num = N;
		G->E_num = M;
		Crt_Graph(G);
		if(!Is_Connected(G))
			printf("?\n");
		else
			printf("%d\n",Process(G));
		free(G);
		G = NULL;
	}
	return 0;
}
