#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int star,end;
	int S_n;
	int n,temp;
	int Left,Right;
	scanf("%d",&S_n);
	int Station[S_n + 1];
	Station[1] = 0;
	for(int i=1; i<S_n; i++){
		scanf("%d",&temp);
		Station[i+1] = Station[i] + temp;
	}
	scanf("%d",&temp);
	Station[1] = Station[S_n] + temp;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d %d",&star,&end);
		if(star > end)
			swap(star,end);
		if(star == 1)
			Right = Station[end];
		else
			Right = Station[end] - Station[star];
		Left = Station[1] - Right;
		printf("%d\n",(Right < Left ? Right : Left));
	}
	return 0;
}
