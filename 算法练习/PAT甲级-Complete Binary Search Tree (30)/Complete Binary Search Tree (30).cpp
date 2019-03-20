/*
题目描述：
  给定一个非负整数序列，已知存在一个即是完全二叉树且是二叉排序树的二叉树可以根据这个序列唯一生成，求这个树的层序遍历。
  
输入描述：
  每次输入包含一个用例，每个用例的第一行输入整数N，N<=1000    下一行给出N个正整数，整数之间用空格隔开
  
输出描述：
  要求输出由输入的整数序列所生成的完全二叉排序树的层序遍历
  
例
输入：10
	  1 2 3 4 5 6 7 8 9 0
输出：6 3 8 1 5 7 9 0 2 4 
*/
#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int Find_Num(vector<int> &T,int root){  //统计以root为根结点的树的结点数 
	if(root >= T.size())
		return 0;
	int sum = 1;
	queue<int> Q;
	vector<bool> visited(T.size(),false);
	visited[root] = true;
	int p = root;
	Q.push(p);
	while(!Q.empty()){
		p = Q.front();
		Q.pop();
		if(p*2 <T.size() && !visited[p*2]){
			sum++;
			Q.push(p*2);
			visited[p*2] = true;
		}
		if(p*2 +1 < T.size() && !visited[p*2 + 1]){
			sum++;
			Q.push(p*2+1);
			visited[p*2+1] = true;
		}
	}
	return sum;
}

void Crt(vector<int> &T, int *Seq,int n){
	if(n >= T.size())
		return;
	int left = Find_Num(T,n*2);
	T[n] = Seq[left];                 //左子树结点的数目对应排好序的Seq的某个数字的下标 
	Crt(T,Seq,n*2);
	Crt(T,Seq+left+1,n*2+1);          //递归右子树需要移动数组指针 
}

void Layer_Order(vector<int> &T){
	queue<int> Q;
	vector<bool> visited(T.size(),false);
	int p = 1;
	Q.push(p);
	cout<<T[p]<<' ';
	while(!Q.empty()){
		p = Q.front();
		Q.pop();
		if(p*2 < T.size() && !visited[p*2]){
			Q.push(p*2);
			visited[p*2] = true;
			if(p*2 == T.size()-1)
				cout<<T[p*2]<<endl;
			else
				cout<<T[p*2]<<' ';
		}
		if(p*2 + 1 < T.size() && !visited[p*2 + 1]){
			Q.push(p*2+1);
			visited[p*2 + 1] = true;
			if(p*2+1 == T.size()-1)
				cout<<T[p*2+1]<<endl;
			else
				cout<<T[p*2+1]<<' ';
		}
	}
}

int main(){
	int *Seq;
	int N;
	cin>>N;
	vector<int> T(N+1,-1);
	Seq = (int *)malloc(sizeof(int) * N);
	for(int i = 0; i<N; i++)
		cin>>Seq[i];
	sort(Seq,Seq + N);
	Crt(T,Seq,1);
	Layer_Order(T);
	return 0;
}
