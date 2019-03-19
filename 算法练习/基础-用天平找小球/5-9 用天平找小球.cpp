//三个球A、B、C，大小形状相同且其中有一个球与其他球重量不同。要求找出这个不一样的球。

//输入格式：
//输入在一行中给出3个正整数，顺序对应球A、B、C的重量。

//输出格式：
//在一行中输出唯一的那个不一样的球。
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	char C[3]={'A','B','C'};
	int A[3];
	for(int i=0;i<3;i++)	cin>>A[i];
	int i=1;
	while(A[0]!=A[i] && i<3)
		i++;
	if(i==3)
		cout<<C[0];
	else if(i==1)
		cout<<C[2];
	else
		cout<<C[1];
	cout<<endl;
	system("pause");
	return 0;
}
