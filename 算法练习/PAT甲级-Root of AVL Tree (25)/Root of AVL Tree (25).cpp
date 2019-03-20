/*
��Ŀ�������룩��
  AVL����һ����ƽ���������������AVl���У�ÿ����������������Ȳ�ľ���ֵ������1�����ڽ���AVL�������з�����ƽ�⣬��ֱ���
RR��ת��LL��ת��LR��ת��RL��ת��ƽ����������ڸ���һ�����������У���Ҫ������ݸ�������������AVL���ĸ���㡣

����������
  ÿ���������һ��������ÿ�������ĵ�һ������һ��������N��N<=20��������Ҫ����Ĺؼ��ֵ���������������һ���Կո�����������
��ֵ��

���������
  ����������AVL���ĸ��ļ�ֵ��
  
�������룺5
  	      88 70 61 96 120
	�����70 
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
	AVLTNode *p,*fp,*A,*FA,*B,*C;   //A��ָ�����һ��ƽ�����Ӳ�Ϊ0�Ľ�㣬ABC������ת������. 
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
	while(p!=S){          //�޸�B��ʼ��S֮�����ƽ�����ӣ���ΪB��ʼ��Ľ��֮ǰ��ƽ�����Ӷ���0������ֱ����1��-1���ɣ� 
		if(key < p->key){
			p->bt = 1;
			p = p->Lchild;
		}
		else{
			p->bt = -1;
			p = p->Rchild;
		}
	}
	if(A->bt == 2 && B->bt == 1){  //LL��ת 
		A->Lchild = B->Rchild;
		B->Rchild = A;
		B->bt = 0;
		A->bt = 0;
		if(FA == NULL)			(*T) = B;
		else if(A == FA->Lchild) FA->Lchild = B;
		else					FA->Rchild = B;
	}
	if(A->bt == -2 && B->bt == -1){ //RR��ת 
		A->Rchild = B->Lchild;
		B->Lchild = A;
		B->bt = 0;
		A->bt = 0;
		if(FA == NULL)			(*T) = B;
		else if(A == FA->Lchild) FA->Lchild = B;
		else					FA->Rchild = B;
	}
	if(A->bt == 2 && B->bt == -1){  //LR��ת 
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
	if(A->bt == -2 && B->bt == 1){  //RL��ת 
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
