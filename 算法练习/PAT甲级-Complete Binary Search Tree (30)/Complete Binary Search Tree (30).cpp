/*
��Ŀ������
  ����һ���Ǹ��������У���֪����һ��������ȫ���������Ƕ����������Ķ��������Ը����������Ψһ���ɣ���������Ĳ��������
  
����������
  ÿ���������һ��������ÿ�������ĵ�һ����������N��N<=1000    ��һ�и���N��������������֮���ÿո����
  
���������
  Ҫ�������������������������ɵ���ȫ�����������Ĳ������
  
��
���룺10
	  1 2 3 4 5 6 7 8 9 0
�����6 3 8 1 5 7 9 0 2 4 
*/
#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int Find_Num(vector<int> &T,int root){  //ͳ����rootΪ���������Ľ���� 
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
	T[n] = Seq[left];                 //������������Ŀ��Ӧ�ź����Seq��ĳ�����ֵ��±� 
	Crt(T,Seq,n*2);
	Crt(T,Seq+left+1,n*2+1);          //�ݹ���������Ҫ�ƶ�����ָ�� 
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
