#include<iostream>
#define MAXSIZE 1000001
using namespace std;


int main(){
	int n;
	int result[MAXSIZE];
	result[0] = result[1] = 1;
	for(int i = 2; i<MAXSIZE; ++i){
		if(i%2 == 0){
			result[i] = (result[i-1] + result[i/2])%1000000000;
		}
		else{
			result[i] = result[i-1]%1000000000;
		}
	}
	while(scanf("%d",&n) != EOF)
		cout<<result[n]<<endl;
	return 0;
}
