#include<iostream>
#define MAXSIZE 10000
#define INFINITY 1000000
using namespace std;
int main(){
	int array[MAXSIZE];
	int N;
	int max,min;
	while(cin>>N){
		max = -INFINITY;
		min = INFINITY;
		for(int i=0; i<N; ++i){
			scanf("%d",&array[i]);
		}
		for(int i=0; i<N; ++i){
			if(array[i] > max)
				max = array[i];
			if(array[i] < min)
				min = array[i];
		}
		cout<<max<<' '<<min<<endl;
	}
	return 0;
}
