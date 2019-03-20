/*
问题描述：
  众所周知，微博是中国版的Twitter.我们的微博用户拥有众多粉丝，而这些粉丝也是我们微博的用户，因此，一个社交网络就是由
  众多的粉丝与被粉或互粉等关系构成的。当一个用户在微博中发布了一条信息，他/她的所有粉丝都能看到并转发，以此类推，粉丝
  的粉丝可以看到粉丝转发的并转发，以此类推。
  现在，给你一个社交网络结构，你要计算一个特点用户的最大潜在粉丝数，假设其间接粉丝关系为L层，（直接粉丝在第一层）
  
输入描述：
  每次输入包含一个用例，每组用例中：
    第一行包含两个正整数N和L  N<=1000  L<=6
	N为用户数，L为间接粉丝层数，所有用户用1~N来编号接下来的   N行的每行格式为：
	  M[i] user_list[i] 
    M[i]<=100 其为编号为i的用户的粉丝数
	user_list[i]为编号为i的所有粉丝的编号
	我们保证一个粉丝不能粉自己，每个数据用空格隔开
	最后一行输入一个正整数K，这是要求求潜在粉丝的用户的编号。
	
	
输出描述：
  对每个用例，你要在一行中输出所有可能看到目标用户发送的微博的潜在粉丝数，假设每个在L层之内的用户都能转发该微博 

*/

#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#define MAXSIZE 1000
using namespace std;
typedef struct{
	int V_num;
	int E_num;
	int matrix[MAXSIZE][MAXSIZE];
}web,*Web; 

void Crt(Web W,int N){
	W->V_num = N;
	W->E_num = 0;
	int num;
	int index;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			W->matrix[i][j] = 0;
	for(int i=1; i<=N; i++){
		cin>>num;
		W->E_num = W->E_num + 1;
		for(int j=0; j<num; j++){
			cin>>index;
			W->matrix[index][i]= 1;
		}
	}
}

int Cal(Web W,int aim,int L){
	int num = 0;
	int Layer = 1;
	int pre_num = 1;
	int b_num = 1;
	queue<int> Q;
	vector<bool> visited(W->V_num,false);
	int p = aim;
	Q.push(p);
	visited[p] = true;
	while( !Q.empty() && Layer <=L ){
		b_num = pre_num;    
		pre_num = 0;                                   //本层顶点等于上一层邻接顶点总和 
		for(int k=0; k<b_num; k++){                    //先把本层顶点都遍历统计完 
			p = Q.front();
			Q.pop();
			for(int i=1; i<=W->V_num; i++){
				if(W->matrix[p][i] && !visited[i]){
					num++;
					visited[i] = true;
					Q.push(i);
					pre_num++;
				}
			}
		}
		Layer++;
	}
	return num;
}

void Process(Web W,int L){
	int N,temp;
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>temp;
		cout<<Cal(W,temp,L)<<endl;
	}
}

int main(){
	Web W;
	W = (web *)malloc(sizeof(web));
	int N,L;
	cin>>N>>L;
	Crt(W,N);
	Process(W,L);
	return 0;
}










 
