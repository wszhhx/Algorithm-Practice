//���������ϵʽ����Բ���ʵ�ֵ��ֱ�����һ���ֵС�ڸ�����ֵ��

//�����ʽ��
//������һ���и���С��1����ֵ��

//�����ʽ��
//��һ�������������ֵ�����Ľ���Բ���ʣ������С�����6λ��
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double valve;
	cin>>valve;
	double item,sum=0;
	double son,mother;
	son=1;
	int count=2;
	mother=3;
	sum=1;
	item=1;
	while(item>=valve){
		item=son/mother;
		sum+=item;
		son*=count++;
		mother*=(2*count-1);
	}
	cout<<setprecision(6)<<fixed<<sum*2;
	return 0;
}
