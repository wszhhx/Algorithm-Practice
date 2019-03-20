#include<iostream>
#include<stack>
#include<vector>
#include<cstdlib>
#define MAXSIZE 1001
using namespace std;
typedef struct g{
	int V_num;
	int E_num;
	int Matrix[MAXSIZE][MAXSIZE];
}Graph,*GRAPH;

void DFS(GRAPH G,vector<bool> &visited,int v0){  //遍历掉一个连通分量 
	stack<int> S;
	S.push(v0);
	int v = v0;
	while(!S.empty()){
		v = S.top();
		S.pop();
		if(!visited[v]){
			visited[v] = true;
			for(int i=1; i<=G->V_num; ++i){
				if( G->Matrix[v][i] && !visited[i])
					S.push(i);
			}
		}
	}
}

int Process(GRAPH G,int des_city){  //通过Visited计算连通分量个数从而返回需要修理的路数 
	vector<bool> visited(G->V_num+1,false);
	int back[G->V_num];
	int index = 0;
	int count = 0;
	for(int i = 1; i<=G->V_num; ++i){
		if(G->Matrix[des_city][i] == 1){
			back[index] = i;
			G->Matrix[des_city][i] = 0;
			G->Matrix[i][des_city] = 0;
			++index;
		}
	}
	for(int i = 1; i<=G->V_num; ++i){
		if(visited[i] == false && i != des_city){
			++count;
			DFS(G,visited,i);
		}
	}
	for(int i=0; i<index; ++i){
		G->Matrix[des_city][ back[i] ] = 1;
		G->Matrix[ back[i] ][des_city] = 1;
	}
	return count-1;
}

int main(){
	int N,M,K;
	int v1,v2;
	scanf("%d %d %d",&N,&M,&K);
	GRAPH G = (Graph *)malloc(sizeof(Graph));
	G->V_num = N;
	G->E_num = M;
	int des_city[K];
	for(int i=1; i<=N; ++i){
		for(int j=1; j<=N; ++j){
			G->Matrix[i][j] = 0;
		}
	}
	for(int i=0; i<M; ++i){
		scanf("%d %d",&v1,&v2);
		G->Matrix[v1][v2] = 1;
		G->Matrix[v2][v1] = 1;
	}
	for(int i=0; i<K; ++i)
		scanf("%d",&des_city[i]);
	for(int i=0; i<K; ++i)
		printf("%d\n",Process(G,des_city[i]));
	exit(0);
}
