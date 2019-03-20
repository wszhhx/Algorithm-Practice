/*
����������
  ������֪��΢�����й����Twitter.���ǵ�΢���û�ӵ���ڶ��˿������Щ��˿Ҳ������΢�����û�����ˣ�һ���罻���������
  �ڶ�ķ�˿�뱻�ۻ򻥷۵ȹ�ϵ���ɵġ���һ���û���΢���з�����һ����Ϣ����/�������з�˿���ܿ�����ת�����Դ����ƣ���˿
  �ķ�˿���Կ�����˿ת���Ĳ�ת�����Դ����ơ�
  ���ڣ�����һ���罻����ṹ����Ҫ����һ���ص��û������Ǳ�ڷ�˿�����������ӷ�˿��ϵΪL�㣬��ֱ�ӷ�˿�ڵ�һ�㣩
  
����������
  ÿ���������һ��������ÿ�������У�
    ��һ�а�������������N��L  N<=1000  L<=6
	NΪ�û�����LΪ��ӷ�˿�����������û���1~N����Ž�������   N�е�ÿ�и�ʽΪ��
	  M[i] user_list[i] 
    M[i]<=100 ��Ϊ���Ϊi���û��ķ�˿��
	user_list[i]Ϊ���Ϊi�����з�˿�ı��
	���Ǳ�֤һ����˿���ܷ��Լ���ÿ�������ÿո����
	���һ������һ��������K������Ҫ����Ǳ�ڷ�˿���û��ı�š�
	
	
���������
  ��ÿ����������Ҫ��һ����������п��ܿ���Ŀ���û����͵�΢����Ǳ�ڷ�˿��������ÿ����L��֮�ڵ��û�����ת����΢�� 

*/

#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#define MAXSIZE 1000
using namespace std;
typedef struct{
	int V_num;
	int E_num;
	int matrix[MAXSIZE][MAXSIZE];
}web,*Web; 

void Crt(Web W,int N){
	W->V_num = N;
	W->E_num = 0;
	int num;
	int index;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=N; j++)
			W->matrix[i][j] = 0;
	for(int i=1; i<=N; i++){
		cin>>num;
		W->E_num = W->E_num + 1;
		for(int j=0; j<num; j++){
			cin>>index;
			W->matrix[index][i]= 1;
		}
	}
}

int Cal(Web W,int aim,int L){
	int num = 0;
	int Layer = 1;
	int pre_num = 1;
	int b_num = 1;
	queue<int> Q;
	vector<bool> visited(W->V_num,false);
	int p = aim;
	Q.push(p);
	visited[p] = true;
	while( !Q.empty() && Layer <=L ){
		b_num = pre_num;    
		pre_num = 0;                                   //���㶥�������һ���ڽӶ����ܺ� 
		for(int k=0; k<b_num; k++){                    //�Ȱѱ��㶥�㶼����ͳ���� 
			p = Q.front();
			Q.pop();
			for(int i=1; i<=W->V_num; i++){
				if(W->matrix[p][i] && !visited[i]){
					num++;
					visited[i] = true;
					Q.push(i);
					pre_num++;
				}
			}
		}
		Layer++;
	}
	return num;
}

void Process(Web W,int L){
	int N,temp;
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>temp;
		cout<<Cal(W,temp,L)<<endl;
	}
}

int main(){
	Web W;
	W = (web *)malloc(sizeof(web));
	int N,L;
	cin>>N>>L;
	Crt(W,N);
	Process(W,L);
	return 0;
}










 
