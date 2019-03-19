#include<iostream>
#include<cmath>
using namespace std;

double Process(int P,int T,int G1,int G2,int G3,int GJ){
	if(abs(G1-G2) <= T)
		return (double)(G1+G2)/2;
	int gap1,gap2;
	gap1 = abs(G1-G3);
	gap2 = abs(G2-G3);
	if(gap1 > T && gap2 > T){
		return (double)GJ;
	}
	else if(gap1 > T && gap2 <= T){
		return (double)(G2+G3)/2;
	}
	else if(gap1 <= T && gap2 >T){
		return (double)(G1+G3)/2;
	}
	else/* if(gap1 <= T && gap2 <= T)*/{
		if(G1 >= G3 && G1 >= G2)
			return (double)G1;
		else if(G2 >= G3 && G2 >= G1)
			return (double)G2;
		else
			return (double)G3;
	}
}

int main(){
	int P,T,G1,G2,G3,GJ;
	while(scanf("%d %d %d %d %d %d",&P,&T,&G1,&G2,&G3,&GJ)!=EOF){
		printf("%.1f\n",Process(P,T,G1,G2,G3,GJ));
	}
	return 0;
}
