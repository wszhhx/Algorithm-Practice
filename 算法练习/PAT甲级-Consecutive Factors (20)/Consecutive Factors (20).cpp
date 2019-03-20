/*

题目描述：
  在一个正整数N的所有因子中，必有一组连续的因子，比如：630    = 3*5*6*7那么630存在一组连续的因子5、6、7，现在给你任何一个正整数N
要求你求出其有几组连续因子，并求出最短的哪一组连续因子。

输入描述：
  每组输入包含一个用例，每个用例有一个正整数N。
  
输出描述：
　对于每次输入，你要在第一行输出一共有几组连续因子，在第二行以a1*a3*a3*...*an的格式升序输出最短的那一组因子

例：输入：630
    输出：5*6*7 

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
	


