#include<iostream>
using namespace std;
#define MAXSIZE 20
long long D[20];
long long JieChen(int n){
	long long result = 1;
	for(int i=2; i<=n ;++i)
		result *= i;
	return result;
}

double CalIncidence(int n){
	long long N = JieChen(n);
	return (double)D[n]/N;
}

int main(){
	int n;
	D[2] = 1;
	D[3] = 2;
	for(int i=4; i<=20; ++i){
		D[i] = (i-1)*(D[i-1] + D[i-2]);
	}
	while(scanf("%d",&n) != EOF){
		printf("%.2f%\n",CalIncidence(n)*100);
	}
	return 0;
}

