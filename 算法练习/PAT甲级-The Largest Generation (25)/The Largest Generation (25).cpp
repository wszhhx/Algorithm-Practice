//������
//���Ǿ�����һ��Ѫͳ��������һ����ͥ�����ף�����ͬһ���˵Ľ������������λ��ͬһ�㣬����Ҫ�ҳ�һ����������������һ����һ�㣩

//����������
//ÿ���������һ��������ÿ��������ͷ��������N (N<100) �������������������������Լ���Ѽ�����˽�����1��N�ı�ţ�
//�����һ��������M (M<N) ������������������ӵ�������
//��������M�У�ÿ�������¸�ʽ������һ����ͥ��Ա����Ϣ��
//ID K ID[1] ID[2] ... ID[K]
//ID����λ��������������һ����ͥ��Ա��K ��K>0�� �������ĺ�����������������K��ID��ÿ����������ÿ�����ӵı�ţ�
//Ϊ������˼�����׶������ǰѸ����Ϊ01
//PS��ÿ�������Կո������

//���������
//��һ���������������һ������������������������Ĵ�����Ψһ���Ҵӵ�һ����ʼ���㣩;

//����֪ʶ�㣺ɭ�ֵĺ���-�ֵ������̬����洢�ṹ֮�����Լ���̬̽�⡣
#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>

#define MAXSIZE 100
using namespace std;


typedef struct node{
	bool visited;
	int index;
	int child_num;
	int child_ID[MAXSIZE];
}Node,*FAMILY;

void Crt_Family( vector<FAMILY> &F, int N){
	for(int i=1; i<=N; i++){
		F[i] = (Node *)malloc(sizeof(Node));
		F[i]->child_num = 0;
		F[i]->visited = false;
		F[i]->index = i;
	}
	int M,id,temp,cn;
	cin>>M;
	for(int i=0; i<M; i++){
		cin>>id>>cn;
		F[id]->child_num = cn;
		for(int j=0; j<cn; j++){
			cin>>temp;
			F[id]->child_ID[j] = temp;
		}
	}
	return;
}

void Process( vector<FAMILY> &F){
	queue<int> Q;
	int Depth = 0;
	int p = 1;
	int b_num = 0;
	int next_num = 1;
	int generation_num[MAXSIZE];
	Q.push(p);
	while(!Q.empty()){
		Depth++;    //̽����ȼ�1 
		b_num = next_num;                      //���ϲ��ܺ�������Ϊ����Ľ���� 
		generation_num[Depth] = b_num;
		next_num = 0;                          //���㺢������0 
		for(int i=0; i<b_num; i++){      //��ʼ������ÿһ����� 
			p = Q.front();               //�ӵ�һ����㿪ʼ���� 
			Q.pop();                     //��ȡ��Ľ����˶� 
			next_num += F[p]->child_num;  //�ۼӱ��㺢���� 
			for(int j=0; j<F[p]->child_num; j++){  //������ĳ�������к������ 
				Q.push(F[p]->child_ID[j]);
			}
		}
	}
	int max = generation_num[1];
	int index = 1;
	for(int i=1; i<=Depth; i++)
		if(generation_num[i] > max){
			index = i;
			max = generation_num[i];
		}
	printf("%d %d\n",max,index);
}

int main(){
	int N;
	cin>>N;
	vector<FAMILY> F(N+1);
	Crt_Family(F,N);
	Process(F);
	
	return 0;
}
