#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	int coin[N];
	for(int i=0; i<N; i++){
		scanf("%d",&coin[i]);
	}
	sort(coin,coin+N);
	int left,right;
	left = 0;
	right = N-1;
	while(coin[left] + coin[right] != M && left < right){
		if(coin[left] + coin[right] < M)
			left++;
		else
			right--;
	}
	if(left >= right){
		printf("No Solution\n");
	}
	else{
		printf("%d %d",coin[left],coin[right]);
	}
	return 0;
}
