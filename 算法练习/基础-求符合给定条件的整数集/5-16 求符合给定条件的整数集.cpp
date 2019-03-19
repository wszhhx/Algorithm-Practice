//给定不超过6的正整数A，考虑从A开始的连续4个数字。请输出所有由它们组成的无重复数字的3位数。

//输入格式：
//输入在一行中给出A。

//输出格式：
//输出满足条件的的3位数，要求从小到大，每行6个整数。整数间以空格分隔，但行末不能有多余空格。

#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int m=n+3;
	int flag=0;
	for(int i=n;i<=m;i++){
		for(int j=n;j<=m;j++){
			if(j==i)
				continue;
			for(int k=n;k<=m;k++){
				if(k==j || k==i)
					continue;
				flag++;
				if(flag%6==0)
					cout<<i*100+j*10+k<<endl;
				else{
					cout<<i*100+j*10+k<<' ';
				}
			}
		}
	}
	return 0;
}
