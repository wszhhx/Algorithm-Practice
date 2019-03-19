#include<iostream>
#include<iomanip>
using namespace std;
double F(double x,double ai[]){
	double p = ai[3];
	for(int i=3; i>0; i--){
		p = ai[i-1]+x*p;
	}
	return p;
}

int main(){
	double a,b;
	double ai[4];
	double answer;
	for(int i=3; i>=0; i--){
		cin>>ai[i];
	}
	cin>>a>>b;
	while(b - a >= 0.01){
		if(F(b,ai)*F(a,ai) < 0){
			if(F((a+b)/2,ai)*F(a,ai) < 0)
				b = (a+b)/2;
			else
				a = (a+b)/2;
			
		}
	}
	answer = (a+b)/2;
	cout<<setprecision(2)<<fixed<<answer;
	return 0;
}
