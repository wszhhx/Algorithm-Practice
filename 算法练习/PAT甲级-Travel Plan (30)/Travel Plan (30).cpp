#include<iostream>
#include<vector>
#include<cstdlib>
#include<stack>
#define INFINITE 35535
#define MAXSIZE 500
using namespace std;
typedef struct{
	int V_num;
	int E_num;
	int D_Matrix[MAXSIZE][MAXSIZE];
	int C_Matrix[MAXSIZE][MAXSIZE];
}Graph,*GRAPH;

void Process(GRAPH G,int star,int end){
	vector<int> D(G->V_num);
	vector<int> P(G->V_num,star);
	vector<bool> F(G->V_num,false);
	for(int i=0; i<D.size(); ++i)
		D[i] = G->D_Matrix[star][i];
	int k,min;
	F[star] = true;
	int cost1 = 0;
	int cost2 = 0;
	int temp;
	while(F[end] == false){
		min = INFINITE;
		for(int i=0; i<D.size(); ++i){
			if(min > D[i] && F[i] == false){
				min = D[i];
				k = i;
			}
		}
		F[k] = true;
		for(int i=0; i<D.size(); ++i){
			if(F[i] == false && min + G->D_Matrix[k][i] < D[i]){
				D[i] = min + G->D_Matrix[k][i];
				P[i] = k;
			}
			if(F[i] == false && min + G->D_Matrix[k][i] == D[i]){
				for(int j=i; j!=star; j = P[j])
					cost1 += G->C_Matrix[ P[j] ][j];
				temp = P[i];
				P[i] = k;
				for(int j=i; j!=star; j = P[j])
					cost2 += G->C_Matrix[ P[j] ][j];
				if(cost1 < cost2)
					P[i] = temp;
				cost1 = cost2 = 0;
			}
		}
	}
	stack<int> S;
	for(int i = end; i!=star; i=P[i])
		S.push(i);
	S.push(star);
	while(!S.empty()){
		printf("%d ",S.top());
		S.pop();
	}
	printf("%d ",D[end]);
	for(int i=end; i!=star; i=P[i]){
		cost1 += G->C_Matrix[ P[i] ][i];
	}
	printf("%d\n",cost1);
}
Graph* Crt_G(int N,int M){
	GRAPH G = (Graph*)malloc(sizeof(Graph));
	G->V_num = N;
	G->E_num = M;
	int v1,v2,d,c;
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			if(i==j){
				G->D_Matrix[i][j] = G->D_Matrix[j][i] = 0;
				G->C_Matrix[i][j] = G->C_Matrix[j][i] = 0;
			}
			else{
				G->D_Matrix[i][j] = G->D_Matrix[j][i] = INFINITE;
				G->C_Matrix[i][j] = G->C_Matrix[j][i] = INFINITE;
			}
		}
	}
	for(int i=0; i<M; ++i){
		scanf("%d %d %d %d",&v1,&v2,&d,&c);
		G->D_Matrix[v1][v2] = G->D_Matrix[v2][v1] = d;
		G->C_Matrix[v1][v2] = G->C_Matrix[v2][v1] = c;
	}
	return G;
}
int main(){
	GRAPH G;
	int N,M,star,end;
	scanf("%d %d %d %d",&N,&M,&star,&end);
	G = Crt_G(N,M);
	Process(G,star,end);
	return 0;
}
