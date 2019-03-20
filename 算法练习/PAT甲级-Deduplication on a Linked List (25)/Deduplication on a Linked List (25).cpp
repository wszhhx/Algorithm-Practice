//�������������ģ�
//����һ������������ɵĵ�����Ҫ�����Ƴ�ȷ����ĳֵ������Ľ�㡣����˵������ÿ����һ�γ��ֵļ�ֵK�����˵�һ�γ��ָü�ֵ���ڵĽ��
//�����ֵ�ľ���ֵ��ü�ֵ����ֵ��ͬ�Ľ����Ҫ�Ƴ��������Ƴ�����Щ��㻹��Ҫ�������һ����������21->15->7->21->15->2->2  ��ɣ�21->15->7->2   �Ƴ�����Ϊ��21->15->2 

//��������
//ÿ���������һ����������ÿ�������У�
//��һ�а����׽��ĵ�ַ��һ��������N��N������N�����        N<=100000 ����ַ��5λ�Ǹ�����ɵ�-1����NULL
//��������N�У�ÿ���ԣ�ĳ����ַ ��ֵ ��һ������ַ��ʽ��������������Ϣ	   ��ֵKey <10000 

//������� 
//����ÿ�����������������ʽ��������������Ȼ�������ժ�������ɵ�����
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
