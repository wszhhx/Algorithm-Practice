#include<iostream>

using namespace std;
/*
typedef struct bitnode{
	int data;
	struct bitnode *LChild;
	struct bitnode *RChild;
}BiTNode,*BiTree;

int Step_Count(int N){                      //该算法超时 
	int path = 0;
	int n = 0;
	stack<BiTNode*> S;
	BiTree T;
	BiTNode *p;
	BiTNode *temp;
	T = (BiTNode*)malloc(sizeof(BiTNode));
	T->data = 0;
	T->LChild = NULL;
	T->RChild = NULL;
	S.push(T);
	while(!S.empty() || temp != NULL){
		temp = S.top();
		if(path + 1 <= N && temp->LChild == NULL){
			p = (BiTNode*)malloc(sizeof(BiTNode));
			p->data = 1;
			p->LChild = NULL;
			p->RChild = NULL;
			path++;
			temp->LChild = p;
			S.push(p);
			//cout<<"建立权值为1的结点,此时的路径长度为："<<path<<endl; 
		}
		else if(path + 2 <=N && temp->RChild == NULL){
			p = (BiTNode*)malloc(sizeof(BiTNode));
			p->data = 2;
			p->LChild = NULL;
			p->RChild = NULL;
			path+=2;
			temp->RChild = p;
			S.push(p);
			//cout<<"建立权值为2的结点,此时的路径长度为："<<path<<endl; 
		}
		else{
			if(path == N)
				n++;
			S.pop();
			path = path - temp->data;
			free(temp);
			temp = NULL;
		}
	}
	return n;
	

}

int main(){
	int N;
	while(cin>>N)
		cout<<Step_Count(N)<<endl;
	return 0;
}
*/
int Step_Count2(int N){
	if(N == 1)
		return 1;
	else{
		long long f1,f2;
		f1 = 1;
		f2 = 2;
		for(int i = 3; i<=N; i++){
			f2 = f1 + f2;
			f1 = f2 - f1;
		}
		return f2;
	}
}

int main(){
 	int N;
 	while(cin>>N)
 		cout<<Step_Count2(N)<<endl;
 	return 0;
 		
}
