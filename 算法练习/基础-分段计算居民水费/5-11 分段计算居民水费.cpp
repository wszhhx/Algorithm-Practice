//Ϊ���������Լ��ˮ������ˮ��˾��ȡ����ˮ������ʽ�Ƽ۵İ취������Ӧ��ˮ��yy��Ԫ��������ˮ��xx���֣���أ�
//��xx������15��ʱ��y=4x/3��������y=2.5x-17.5�����д����ʵ��ˮ�ѵļ��㡣

//�����ʽ��
//������һ���и����Ǹ�ʵ��xx��

//�����ʽ��
//��һ�����Ӧ����ˮ�ѣ���ȷ��С�����2λ��
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double ton;
	double fee;
	cin>>ton;
	if(ton<=15){
		fee=4*ton/3;
	}
	else{
		fee=2.5*ton-17.5;
	}
	cout<<setprecision(2)<<fixed<<fee;
	return 0;
	
}
