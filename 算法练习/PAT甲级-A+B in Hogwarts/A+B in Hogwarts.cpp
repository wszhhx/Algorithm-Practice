//If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, 
//"Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough."  Your job is to write a program to compute
// A+B where A and B are given in the standard form of "Galleon.Sickle.Knut" (Galleon is an integer in [0, 107], Sickle is an integer in 
//[0, 17), and Knut is an integer in [0, 29)).
//������ǹ�������ϵ�еķ�˿�������֪���������ص�ħ������ӵ���Լ��Ļ�����ϵ ������³�����������������˵����������
// 17 Sickles    -> 1Galleon
// 29 Knuts      -> 1Sickle
//��Ҫ��һ������Ҫ�������Galleon.Sickle.KnutΪ��ʽ�ļӷ����㣨Galleon��0��10000000֮���������Sickle��0��17֮�䣬Knut��0��29֮�䣩 

//����������
//ÿ���������һ��������һ��������������Ҫ��ӵģ���ʽΪA.B.C�����ӹ��ɣ����������ɿո����,�磺123.12.4 100.13.23 

//���������
// Ҫ����ͬ���ĸ�ʽ���
#include<iostream> 
int main(){
	int a_g,a_s,a_k;
	int b_g,b_s,b_k;
	int c_g,c_s,c_k;
	scanf("%d.%d.%d %d.%d.%d",&a_g,&a_s,&a_k,&b_g,&b_s,&b_k);
	c_g = a_g + b_g + (a_s + b_s)/17;
	c_s = (a_s + b_s)%17 + (a_k + b_k)/29;
	c_k = (a_k + b_k)%29;
	printf("%d.%d.%d",c_g,c_s,c_k);
	exit(0);
}
