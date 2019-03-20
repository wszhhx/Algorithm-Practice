//问题描述（译文）
//给你一个二叉树结构和与之对应的一串整数序列，要求你按这个二叉树结构遵循二叉排序树规律把这些整数放入各个结点，并按层序遍历输出其顺序。

//输入描述
//每次输入包含一个用例，在每个用例中，第一行给出一个正整数    N(N<=100)代表该数共有N个结点，接下来的N行的每行中
//以  "左孩子下标  右孩子下标"的形式输入，代表第i行的左右孩子的下标，下标为0的是根结点如果某个孩子不存在，则用-1代替
//最后一行输入整数序列 

//输出描述
//输出该树的层序遍历 
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
//	printf("%d 号结点有 %d 个左孩子\n",root,l_num);
	BT[root]->data = *(Seq + l_num);
//	printf("将数据 %d 装载进 %d 号容器\n",*(Seq+l_num),root);
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


