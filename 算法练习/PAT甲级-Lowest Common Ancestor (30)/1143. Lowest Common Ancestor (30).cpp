/*
因为是二叉搜索树，所以是否存在某一结点十分好办。
两个结点最深公共祖先是从顶点向下搜索第一个介于两个数字
之间的结点。
 
*/
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string.h>
using namespace std;

typedef struct node{
	int data;
	struct node *Lchild;
	struct node *Rchild;
}TreeNode,*TREE;

void Generate_BST(TREE* NODE,int pre[],int in[],int length){
	if(length <= 0){
		(*NODE) = NULL;
		return;
	}
	int LONG;
	(*NODE) = (TreeNode*)malloc(sizeof(TreeNode));
	(*NODE)->Lchild = (*NODE)->Rchild = NULL;
	(*NODE)->data = pre[0];
	for(LONG = 0;LONG < length && in[LONG] != pre[0]; ++LONG);
	Generate_BST(&((*NODE)->Lchild),pre + 1,in,LONG);
	Generate_BST(&((*NODE)->Rchild),pre + 1 + LONG,in + 1 + LONG,length - LONG - 1);
	return;
} 

bool is_find(TREE T,int n){
	TreeNode *p = T;
	while(p != NULL){
		if(p->data == n)
			return true;
		else if(p->data < n){
			p = p->Rchild;
		}	
		else
			p = p->Lchild;
	}
	return false;
}

void Process(TREE T,int u,int v){
	TreeNode *p = T;
	bool u_find = is_find(T,u);
	bool v_find = is_find(T,v);
	if(!u_find && !v_find){
		printf("ERROR: %d and %d are not found.\n",u,v);
		return;
	}
	else if(u_find && !v_find){
		printf("ERROR: %d is not found.\n",v);
		return;
	}
	else if(!u_find && v_find){
		printf("ERROR: %d is not found.\n",u);
		return;
	}
	else{
		int left = u < v? u:v;
		int right = u > v? u:v;
		while(p != NULL){
			if(p->data > left && p->data > right){
				p = p->Lchild;
			}
			else if(p->data < left && p->data < right){
				p = p->Rchild;
			}
			else if(p->data == left){
				printf("%d is an ancestor of %d.\n",left,right);
				return;
			}
			else if(p->data == right){
				printf("%d is an ancestor of %d.\n",right,left);
				return;
			}
			else{
				printf("LCA of %d and %d is %d.\n",u,v,p->data);
				return;
			}
		}
	}
}

int main(){
	int M,N;
	int U,V;
	int pre[10001];
	int in[10001];
	cin>>M>>N;
	for(int i=0; i<N; ++i)
		cin>>pre[i];
	memcpy(in,pre,N*sizeof(int));
	sort(in,in+N);
	TREE T = NULL;
	Generate_BST(&T,pre,in,N);
	while(M--){
		cin>>U>>V;
		Process(T,U,V);
	}
	return 0;
}
