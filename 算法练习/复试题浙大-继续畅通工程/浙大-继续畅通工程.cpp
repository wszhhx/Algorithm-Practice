#include<iostream>
#include<cstdlib>
#include<vector>
#include<stack>
#define MAXSIZE 101
#define INFINITE 65535
using namespace std;
typedef struct{
	int V_num;
	int E_num;
	int Matrix[MAXSIZE][MAXSIZE];
	int Have_Path[MAXSIZE][MAXSIZE];
	int set[MAXSIZE];
}Graph,*GRAPH;

void DFS(GRAPH G,vector<bool> &visited,int v0,int set){
	stack<int> S;
	int p = v0;
	S.push(p);
	while(!S.empty()){
		p = S.top();
		S.pop();
		if(!visited[p]){
			G->set[p] = set;
			visited[p] = true;
			for(int i=1; i<=G->V_num; ++i){
				if(G->Have_Path[p][i] && p!=i && !visited[i]){
					S.push(i);
				}
			}
		}
	}
	return;
}

void Crt_Graph(GRAPH G){
	int v1,v2;
	int E = G->E_num;
	int cost,path;
	vector<bool> visited(G->V_num+1,false);
	for(int i=0; i<E; ++i){
		scanf("%d %d %d %d",&v1,&v2,&cost,&path);
		G->Matrix[v1][v2] = G->Matrix[v2][v1] = cost;
		G->Have_Path[v1][v2] = G->Have_Path[v2][v1] = path;
	}
	int set = 1;
	for(int i=1; i<=G->V_num; ++i){
		if(visited[i] == false)
			DFS(G,visited,i,set++);
	}

	return;
}

bool isConnect(GRAPH G){
	bool Connect = false;
	int flag = G->set[1];
	for(int i=2; i<=G->V_num; ++i){
		if(G->set[i] != G->set[1])
			return false;
	}
	return true;
}

int Process(GRAPH G){
	int lowest_cost = 0;
	int v1,v2;
	int cost = INFINITE;
	while(!isConnect(G)){
		cost = INFINITE;
		for(int i=1; i<=G->V_num; ++i){
			for(int j=i+1; j<=G->V_num; ++j){
				if(G->Matrix[i][j] < cost && G->set[i] != G->set[j]){
					v1 = i;
					v2 = j;
					cost = G->Matrix[v1][v2];
				}
			}
		}
		lowest_cost += cost;
		G->Have_Path[v1][v2] = G->Have_Path[v2][v1] = 1;
		for(int i=1; i<=G->V_num; ++i){
			if(G->set[i] == G->set[v2] && i!=v2){
				G->set[i] = G->set[v1];
			}
		}
		G->set[v2] = G->set[v1];
	}
	return lowest_cost;
}

int main(){
	int N;
	int E;
	int lowest_cost;
	GRAPH G;
	while(scanf("%d",&N) != EOF){
		if(N==0)
			break;
		E = (N-1)*N/2;
		G = (Graph *)malloc(sizeof(Graph));
		G->V_num = N;
		G->E_num = E;
		for(int i=1; i<=N; ++i){
			for(int j=i; j<=N; ++j){
				if(i != j)
					G->Matrix[i][j] = G->Matrix[j][i] = INFINITE;
				else
					G->Matrix[i][j] = G->Matrix[j][i] = 0;
				G->Have_Path[i][j] = G->Have_Path[j][i] = 0;
			}
		}
		
		Crt_Graph(G);
		lowest_cost = Process(G);
		printf("%d\n",lowest_cost);
		free(G);
		G = NULL;
	}
	return 0;
}


