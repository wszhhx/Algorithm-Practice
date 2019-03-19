//根据下面关系式，求圆周率的值，直到最后一项的值小于给定阈值。

//输入格式：
//输入在一行中给出小于1的阈值。

//输出格式：
//在一行中输出满足阈值条件的近似圆周率，输出到小数点后6位。
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
