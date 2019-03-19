//为鼓励居民节约用水，自来水公司采取按用水量阶梯式计价的办法，居民应交水费yy（元）与月用水量xx（吨）相关：
//当xx不超过15吨时，y=4x/3；超过后，y=2.5x-17.5。请编写程序实现水费的计算。

//输入格式：
//输入在一行中给出非负实数xx。

//输出格式：
//在一行输出应交的水费，精确到小数点后2位。
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
