#include<iostream>
using namespace std;

int main(){
	
	int FibArray[81];
	FibArray[0]=0;
	FibArray[1]=1;
	FibArray[2]=1;
	int temp;
	for(int i=3;i<=80;i++){
		FibArray[i]=FibArray[i-1]+FibArray[i-2];
	}
	int from,to;
	double sum=0;
	cin>>from>>to;
	for(int i=from;i<=to;i++){
		sum+=FibArray[i];
	}
	cout<<sum;
	return 0;
}
	

