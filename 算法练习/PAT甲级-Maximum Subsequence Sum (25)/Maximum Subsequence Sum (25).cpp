#include<iostream>
int main(){
	int N;
	int max = 0;
	int thismax = 0;
	int left,right,tleft;
	left = right = 0;
	scanf("%d",&N);
	int Seq[N];
	for(int i=0; i<N; ++i)
		scanf("%d",&Seq[i]);
	for(int i=0; i<N; ++i){
		thismax += Seq[i];
		if(thismax <= 0 && i+1<N){
			tleft = i+1;
			thismax = 0;
		}
		else{
			if(thismax > max){
				max = thismax;
				left = tleft;
				right = i;
			}
		}
	}

	printf("%d %d %d",max,Seq[left],Seq[right]);

	return 0;
}
