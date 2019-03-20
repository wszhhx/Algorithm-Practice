//问题描述（译文）
//给出一连串由整型组成的单链表，要求你移除确定的某值所代表的结点。这样说：对于每个第一次出现的键值K，除了第一次出现该键值所在的结点
//其余键值的绝对值与该键值绝对值相同的结点需要移除，但是移除的这些结点还需要单独组成一个单链表。如21->15->7->21->15->2->2  变成：21->15->7->2   移除的链为：21->15->2 

//输入描述
//每组输入包含一个用例，在每个例子中：
//第一行包含首结点的地址和一个正整数N，N代表共有N个结点        N<=100000 结点地址是5位非负数组成的-1代表NULL
//接下来的N行，每行以：某结点地址 键值 下一个结点地址形式给出各个结点的信息	   键值Key <10000 

//输出描述 
//对于每个用例，以输入的形式输出处理过的链表，然后输出被摘掉结点组成的链表。
#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

typedef struct{
	int key;
	int N_addr;
	bool pass;
}Node,*List;

void Crt_L( vector<List> &L ,int N){
	int p;
	for(int i=0; i<N; i++){
		cin>>p;
		L[p] = (Node *)malloc(sizeof(Node));
		cin>>L[p]->key;
		cin>>L[p]->N_addr;
		L[p]->pass = false;
	}
	
}

void Process( vector<List> &L,int F_addr, int N ){
	vector<int> right;
	vector<int> pass;
	vector<bool> Ex(100001,false);
	int p = F_addr;
	while(p != -1){
		if(!Ex[ abs(L[p]->key) ]){
			Ex[ abs(L[p]->key) ] = true;
			right.push_back(p);
		}
		else
			pass.push_back(p);
		p = L[p]->N_addr;
	}
	int next;
	int right_num = right.size();
	int pass_num = pass.size();
	for(int i=0; i<right_num; i++){
		if(i == right_num-1)
			next = -1;
		else{
			next = right[i+1];
		}
		cout<<setw(5)<<setfill('0')<<right[i]<<' '<<L[ right[i] ]->key<<' ';
		if(next != -1)
			cout<<setw(5)<<setfill('0')<<next<<endl;
		else
			cout<<-1<<endl;
	}
	for(int i=0; i<pass_num; i++){
		if(i == pass_num-1)
			next = -1;
		else{
			next = pass[i+1];
		}
		cout<<setw(5)<<setfill('0')<<pass[i]<<' '<<L[ pass[i] ]->key<<' ';
		if(next != -1)
			cout<<setw(5)<<setfill('0')<<next<<endl;
		else
			cout<<-1<<endl;
	}
	
}

int main(){
	vector<List> L(1000000);
	int N;
	int F_addr;
	cin>>F_addr>>N;
	Crt_L(L,N);
	Process(L,F_addr,N);
	return 0;
}
