/*
��Ŀ�������룩
  �������׷���ĳ�������������֣��ڴ˾����У�ÿ������Ա��Ҫ��дһ���Լ��Ĵ�������һ�������ĵ�ͼ�п���������ж�
��ÿֻ�����Ŀ����Ϊ�˳�Ϊһֻ˶��������ܶ���׷���
  ��һ��������˳������Np������Ա�����������Щ����Ա�� Ng����Ϊһ��С�飬ÿ��С������ʵ�����ʤ����������һ�غ�
ÿ���غ������������������ͬ�ģ�������Ψһʤ��ʤ��ǰ��ÿNg��ʤ���������һ��С����б�����
  Ϊ�˼�Ҫ������ÿֻ����������ڶ�Ӧ����Ա�ύ�������һ�̾��Ѿ�������
  ���ڸ�����������������Լ���ʼ����˳������Ҫ�����Щ����Ա�����С�
  
����������
  ÿ���������һ����������ÿ�������У���һ�а���2��������Np��Ng��<=1000��,�ֱ��ǳ���Ա��������ÿ������������Ŀ��
  ��������б�����������Ng��������Щ��������ӡ�
  �ڶ��а���Np��ȷ���ķǸ���Wi��i=0,1,2,,,Np-1��Wi�ֱ��Ǳ��Ϊi�����������
  �����и�����ʼ˳�����˳����0~Np-1�����У�������ÿ������Ա��0~Np-1�ı�ţ���ÿ�������ÿո����
  
���������
  ����ÿ����������һ���д�ӡ������i�����ִ����i������Ա��������ÿ�������ÿո������ĩβ�����пո�
  
   ������ = ��������+1�� 
�磺���룺11 3
		  25 18 0 46 37 3 19 22 57 56 10
		  6  0  8 7  10 5 9  1  4  2  3
	�����5 5 5 2 5 5 5 3 1 3 5 

*/
#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct node{
	int _id;
	int _weight;
	int _order;
	bool _win;
	int _rank;
}Programmers;

bool Sort_id(Programmers p1,Programmers p2){
	return p1._id < p2._id;
}

bool Sort_order(Programmers p1,Programmers p2){
	return p1._order < p2._order;
}

void Test(vector<Programmers> &Ps){
	for(int i=0; i<Ps.size(); i++){
		cout<<Ps[i]._weight<<' ';
	}
	cout<<endl;
}

void Crt(vector<Programmers> &Ps,int Np){
	for(int i=0; i<Np; i++){
		cin>>Ps[i]._weight;
		Ps[i]._id = i;
		Ps[i]._win = false;
		Ps[i]._rank = -1;
	}
	for(int i=0; i<Np; i++)
		cin>>Ps[i]._order;
	return;
}

void Group_Rank( vector<Programmers> &Ps, int Begin, int End ){       //ֻ����ĳ��С���ڲ������� 
	
}   

int F_Rank( vector<Programmers> &Ps, int Ng, int Np ){               //
	
}

void Rank( vector<Programmers> &Ps, int Ng, int Person ){
	
}

void Main_Rank( vector<Programmers> &Ps , int Ng, int Person){           //������������������� 
	int F_win = F_Rank(Ps,Ng,Np);
	Rank(Ps,Ng,F_win);
}

int main(){
	vector<Programmers> Ps;
	int Np,Ng;
	cin>>Np>>Ng;
	Ps.resize(Np); 
	Crt(Ps,Np);
	sort(Ps.begin(),Ps.end(),Sort_order);
	Test(Ps);
	return 0;
}
