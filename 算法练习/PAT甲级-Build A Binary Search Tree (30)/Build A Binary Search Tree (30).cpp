//�������������ģ�
//����һ���������ṹ����֮��Ӧ��һ���������У�Ҫ���㰴����������ṹ��ѭ�������������ɰ���Щ�������������㣬����������������˳��

//��������
//ÿ���������һ����������ÿ�������У���һ�и���һ��������    N(N<=100)�����������N����㣬��������N�е�ÿ����
//��  "�����±�  �Һ����±�"����ʽ���룬�����i�е����Һ��ӵ��±꣬�±�Ϊ0���Ǹ�������ĳ�����Ӳ����ڣ�����-1����
//���һ�������������� 

//�������
//��������Ĳ������ 
#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef struct node{
	int data;
	int Lchild;
	int Rchild;
}BiTNode,*BiTree;

void Crt_BiTree(vector<BiTree> &BT,int N){
	for(int i=0; i<N; i++){
		BT[i] = (BiTNode *)malloc(sizeof(BiTNode));
		BT[i]->data = 0;
		cin>>BT[i]->Lchild;
		cin>>BT[i]->Rchild;
	}
	return;
}

int Node_Num(vector<BiTree> &BT,int m_root){
	if(m_root == -1)
		return 0;
	int count = 1;
	queue<int> Q;
	int p = m_root;
	Q.push(p);
	while(!Q.empty()){
		p = Q.front();
		Q.pop();
		if(BT[p]->Lchild != -1){
			Q.push(BT[p]->Lchild);
			count++;
		}
		if(BT[p]->Rchild != -1){
			Q.push(BT[p]->Rchild);
			count++;
		}
	}
	return count;
}

void Log(vector<BiTree> &BT,int *Seq,int root){

	if(root == -1)
		return;
	int l_num = Node_Num(BT,BT[root]->Lchild);
//	printf("%d �Ž���� %d ������\n",root,l_num);
	BT[root]->data = *(Seq + l_num);
//	printf("������ %d װ�ؽ� %d ������\n",*(Seq+l_num),root);
	Log(BT,Seq,BT[root]->Lchild);
	Log(BT,Seq + l_num + 1,BT[root]->Rchild);
	return;
}

void Layer_Order(vector<BiTree> &BT){
	queue<int> Q;
	int p = 0;
	Q.push(p);
	while(!Q.empty()){
		p = Q.front();
		Q.pop();
		if(Q.empty() && BT[p]->Lchild == -1 && BT[p]->Rchild == -1)
			printf("%d\n",BT[p]->data);
		else
			printf("%d ",BT[p]->data);
		if(BT[p]->Lchild != -1)
			Q.push(BT[p]->Lchild);
		if(BT[p]->Rchild != -1)
			Q.push(BT[p]->Rchild);
	}
}

int main(){
	vector<BiTree> BT;
	int N;
	cin>>N;
	BT.resize(N);
	Crt_BiTree(BT,N);
	int Seq[100];
	for(int i=0; i<N; i++)
		cin>>Seq[i];
	sort(Seq,Seq+N);
	Log(BT,Seq,0);
	Layer_Order(BT);
	return 0;
}


