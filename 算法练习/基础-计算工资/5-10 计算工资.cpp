//ĳ��˾Ա���Ĺ��ʼ��㷽�����£�һ���ڹ���ʱ�䲻����40Сʱ������������ʱ��Ƴꣻ����40Сʱ�Ĺ���ʱ�䲿�֣�
//����������ʱ�䱨���1.5���ƳꡣԱ��������˾ʱ���Ϊ��ְ������ְ��������˾������5���Ա��Ϊ��ְ����
//5�����µ�Ϊ��ְ������ְ������������Ϊ30Ԫ/Сʱ����ְ������������Ϊ50Ԫ/Сʱ���밴�üƳ귽ʽ����Ա��
//�Ĺ��ʡ�

//�����ʽ��
//������һ���и���2�����������ֱ�ΪĳԱ����ְ�������ܹ���ʱ�䣬����Կո�ָ���

//�����ʽ��
//��һ�������Ա������н����ȷ��С�����2λ��
#include<iostream>
#include<iomanip>
using namespace std;
double Reward(double time,double salary){
	double reward;
	if(time<=40){
		reward=time*salary;
	}
	else{
		reward=40*salary+(time-40)*salary*1.5;
	}
	return reward;
}
int main(){
	double reward,time,year;
	cin>>year>>time;
	if(year>=5)
		reward=Reward(time,50);
	else
		reward=Reward(time,30);
	cout<<setprecision(2)<<fixed<<reward;
	return 0;
}
