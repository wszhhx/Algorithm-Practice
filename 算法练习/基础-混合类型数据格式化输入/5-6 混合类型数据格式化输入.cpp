//本题要求编写程序，顺序读入浮点数1、整数、字符、浮点数2，再按照字符、整数、浮点数1、浮点数2的顺序输出。

//输入格式：
//输入在一行中顺序给出浮点数1、整数、字符、浮点数2，其间以1个空格分隔。

//输出格式：
//在一行中按照字符、整数、浮点数1、浮点数2的顺序输出，其中浮点数保留小数点后2位。
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	double d1,d2;
	int i;
	char c;
	cin>>d1>>i>>c>>d2;
	cout<<setprecision(2)<<fixed<<c<<' '<<i<<' '<<d1<<' '<<d2;
	return 0;
}
