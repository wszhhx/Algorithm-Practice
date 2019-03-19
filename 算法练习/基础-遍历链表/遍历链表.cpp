#include<iostream>
#include<cstdlib>
using namespace std;
void sift(int array[], int root ,int tail){
	array[0] = array[root];
	int i = root;
	int j = i*2;
	bool finished = false;
	while(j <= tail && !finished){
		
		if(j < tail && array[j+1] > array[j])
			j+=1;
		if(array[j] <= array[0])
			finished = true;
		else{
			array[i] = array[j];
			i = j;
			j = i*2;
		}
	}
	array[i] = array[0];
	return;
}

void Crt_Heap(int array[], int N){
	int n = N/2;
	for(int i = n; i>=1; i--)
		sift(array,i,N);
	return;
}

void Heap_Sort(int array[], int N){
	Crt_Heap(array,N);
	for(int i = N; i>1; i--){
		array[0] = array[i];
		array[i] = array[1];
		array[1] = array[0];
		sift(array,1,i-1);
	}
	return;
}

int main(){
	int n;
	int *array;
	while(cin>>n){
		array = (int *)malloc(sizeof(int)*(n+1));
		for(int i = 1; i<=n; i++)
			cin>>array[i];
		Heap_Sort(array,n);
		for(int i = 1; i<=n; i++){
			if(i == n){
				cout<<array[i]<<endl;
			}
			else
				cout<<array[i]<<" ";
		}

		delete array;
		array = NULL;
	}
	return 0;
}
