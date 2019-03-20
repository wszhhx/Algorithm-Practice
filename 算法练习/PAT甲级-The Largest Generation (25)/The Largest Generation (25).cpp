//简述：
//我们经常用一棵血统树来代表一个家庭的族谱，代表同一代人的结点在树种总是位于同一层，你需要找出一个家谱中人数最多的一代（一层）

//输入描述：
//每次输入包含一个用例，每个用例开头有正整数N (N<100) ，代表这个家族的总人数（可以假设把家族的人进行由1到N的编号）
//随后是一个正整数M (M<N) ，代表家族中有生孩子的人数。
//接下来的M行，每行以如下格式包含着一个家庭成员的信息：
//ID K ID[1] ID[2] ... ID[K]
//ID是两位数的正整数代表一个家庭成员，K （K>0） 代表他的孩子数量，接下来的K个ID，每个代表他的每个孩子的编号，
//为了让意思简明易懂，我们把根编号为01
//PS：每个数据以空格隔开。

//输出描述：
//在一行中输出人数最多的一代的人数与其代数（人数最多的代数是唯一的且从第一代开始计算）;

//考察知识点：森林的孩子-兄弟链表或静态链表存储结构之遍历以及动态探测。
#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>

#define MAXSIZE 100
using namespace std;


typedef struct node{
	bool visited;
	int index;
	int child_num;
	int child_ID[MAXSIZE];
}Node,*FAMILY;

void Crt_Family( vector<FAMILY> &F, int N){
	for(int i=1; i<=N; i++){
		F[i] = (Node *)malloc(sizeof(Node));
		F[i]->child_num = 0;
		F[i]->visited = false;
		F[i]->index = i;
	}
	int M,id,temp,cn;
	cin>>M;
	for(int i=0; i<M; i++){
		cin>>id>>cn;
		F[id]->child_num = cn;
		for(int j=0; j<cn; j++){
			cin>>temp;
			F[id]->child_ID[j] = temp;
		}
	}
	return;
}

void Process( vector<FAMILY> &F){
	queue<int> Q;
	int Depth = 0;
	int p = 1;
	int b_num = 0;
	int next_num = 1;
	int generation_num[MAXSIZE];
	Q.push(p);
	while(!Q.empty()){
		Depth++;    //探测深度加1 
		b_num = next_num;                      //将上层总孩子数作为本层的结点数 
		generation_num[Depth] = b_num;
		next_num = 0;                          //本层孩子数置0 
		for(int i=0; i<b_num; i++){      //开始处理本层每一个结点 
			p = Q.front();               //从第一个结点开始处理 
			Q.pop();                     //读取完的结点可退队 
			next_num += F[p]->child_num;  //累加本层孩子数 
			for(int j=0; j<F[p]->child_num; j++){  //将本层某结点的所有孩子入队 
				Q.push(F[p]->child_ID[j]);
			}
		}
	}
	int max = generation_num[1];
	int index = 1;
	for(int i=1; i<=Depth; i++)
		if(generation_num[i] > max){
			index = i;
			max = generation_num[i];
		}
	printf("%d %d\n",max,index);
}

int main(){
	int N;
	cin>>N;
	vector<FAMILY> F(N+1);
	Crt_Family(F,N);
	Process(F);
	
	return 0;
}
