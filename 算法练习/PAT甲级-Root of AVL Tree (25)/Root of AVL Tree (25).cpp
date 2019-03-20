/*
题目描述（译）：
  AVL树是一种自平衡二叉搜索树，在AVl树中，每个结点的左右子树深度差的绝对值不超过1，若在建立AVL树过程中发生不平衡，则分别用
RR旋转、LL旋转、LR旋转、RL旋转来平衡该树。现在给你一个正整数序列，你要输出根据该序列所建立的AVL树的根结点。

输入描述：
  每次输入包含一个用例，每个用例的第一行输入一个正整数N（N<=20）代表需要插入的关键字的总数，接下来的一行以空格隔开输入各个
键值。

输出描述：
  输出建立后的AVL树的根的键值。
  
例：输入：5
  	      88 70 61 96 120
	输出：70 
*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node{
	int bt;
	int key;
	struct node* Lchild;
	struct node* Rchild;
}AVLTNode,*AVLTree;

void Ins_AVLTree(AVLTree *T,int key){
	AVLTNode *S = (AVLTNode *)malloc(sizeof(AVLTNode));
	S->key = key;
	S->bt = 0;
	S->Lchild = NULL;
	S->Rchild = NULL;
	if((*T) == NULL){
		*T = S;
		return;
	}
	AVLTNode *p,*fp,*A,*FA,*B,*C;   //A是指向最后一个平衡因子不为0的结点，ABC构成旋转三剑客. 
	p = (*T);	fp = NULL;
	A = (*T);	FA = NULL;
	B = NULL;	C  = NULL;
	while(p!=NULL){
		if(p->bt != 0){
			A = p;
			FA = fp;
		}
		fp = p;
		if(S->key < p->key){
			p = p->Lchild;
		}
		else if(S->key > p->key){
			p = p->Rchild;
		}
		else 
			return;
	}

	if(S->key < fp->key){
		fp->Lchild = S;
	}
	else{
		fp->Rchild = S;
	}
	if(S->key < A->key){
		B = A->Lchild;
		A->bt = A->bt + 1;
	}
	else{
		B = A->Rchild;
		A->bt = A->bt - 1;
	}
	p = B;
	while(p!=S){          //修改B开始到S之间结点的平衡因子（因为B开始后的结点之前的平衡因子都是0，所以直接置1或-1即可） 
		if(key < p->key){
			p->bt = 1;
			p = p->Lchild;
		}
		else{
			p->bt = -1;
			p = p->Rchild;
		}
	}
	if(A->bt == 2 && B->bt == 1){  //LL旋转 
		A->Lchild = B->Rchild;
		B->Rchild = A;
		B->bt = 0;
		A->bt = 0;
		if(FA == NULL)			(*T) = B;
		else if(A == FA->Lchild) FA->Lchild = B;
		else					FA->Rchild = B;
	}
	if(A->bt == -2 && B->bt == -1){ //RR旋转 
		A->Rchild = B->Lchild;
		B->Lchild = A;
		B->bt = 0;
		A->bt = 0;
		if(FA == NULL)			(*T) = B;
		else if(A == FA->Lchild) FA->Lchild = B;
		else					FA->Rchild = B;
	}
	if(A->bt == 2 && B->bt == -1){  //LR旋转 
		C = B->Rchild;
		B->Rchild = C->Lchild;
		A->Lchild = C->Rchild;
		C->Lchild = B;
		C->Rchild = A;
		if(key < C->key){
			A->bt = -1;
			B->bt = 0;
			C->bt = 0;
		}
		else if(key > C->key){
			B->bt = 1;
			A->bt = 0;
			C->bt = 0;
		}
		else{
			A->bt = 0;
			B->bt = 0;
		}
		if(FA == NULL)			(*T) = C;
		else if(A == FA->Lchild) FA->Lchild = C;
		else					FA->Rchild = C;
	}
	if(A->bt == -2 && B->bt == 1){  //RL旋转 
		C = B->Lchild;
		A->Rchild = C->Lchild;
		B->Lchild = C->Rchild;
		C->Lchild = A;
		C->Rchild = B;
		if(key < C->key){
			A->bt = 0;
			B->bt = -1;
			C->bt = 0;
		} 
		else if(key > C->key){
			A->bt = 1;
			B->bt = 0;
			C->bt = 0;
		}
		else{
			A->bt = 0;
			B->bt = 0;
			C->bt = 0;
		}
		if(FA == NULL)			(*T) = C;
		else if(A == FA->Lchild) FA->Lchild = C;
		else					FA->Rchild = C;
	}
	return;
}

void Crt_AVLTree(AVLTree *T,int N){
	int key;
	for(int i=0; i<N; i++){
		cin>>key;
		Ins_AVLTree(T,key);
	}
	return;
}

int main(){
	int N;
	AVLTree T = NULL;
	cin>>N;
	Crt_AVLTree(&T,N);
	cout<<T->key<<endl;
	return 0;
}
