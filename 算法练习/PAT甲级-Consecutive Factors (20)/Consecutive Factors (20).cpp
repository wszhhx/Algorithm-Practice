/*

��Ŀ������
  ��һ��������N�����������У�����һ�����������ӣ����磺630    = 3*5*6*7��ô630����һ������������5��6��7�����ڸ����κ�һ��������N
Ҫ����������м����������ӣ��������̵���һ���������ӡ�

����������
  ÿ���������һ��������ÿ��������һ��������N��
  
���������
������ÿ�����룬��Ҫ�ڵ�һ�����һ���м����������ӣ��ڵڶ�����a1*a3*a3*...*an�ĸ�ʽ���������̵���һ������

�������룺630
    �����5*6*7 

*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
	int min_star;
	int star;
	int N,count;
	int temp;
	int sqN;
	int max_count = 1;
	cin>>N;
	sqN = sqrt(N);
	min_star = N;
	for(int i=2; i<=sqN; i++){
		if(N%i == 0){
			count = 1;
			temp = N/i;
			star = i;
			while(temp%(++star) == 0){
				count++;
				temp/=star;
			}
			if(count > max_count){
				max_count = count;
				min_star = i;
			}
			if(count == max_count && i < min_star){
				min_star = i;
			}
		}
	}
	cout<<max_count<<endl;
	if(min_star == N)
		cout<<N;
	else{
		for(int i=0; i<max_count; i++){
			if(i == max_count-1)
				cout<<min_star;
			else
				cout<<min_star++<<'*';
		}
	}
	return 0;
}
	


