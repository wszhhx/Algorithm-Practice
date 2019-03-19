#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
void Sift(int array[], int root, int tail){
	int i,j;
	bool finish = false;
	i = root;
	j = i*2;
	array[0] = array[root];
	while(j <= tail && !finish){
		if(j<tail && array[j+1] > array[j])
			j++;
		if(array[j] <= array[0])
			finish = true;
		else{
			array[i] = array[j];
			i = j;
			j = i*2;
		}
	}
	array[i] = array[0];
	return;
}

void Crt_Heap(int array[], int length){
	int n = length/2;
	for(int i=n; i>=1; i--)
		Sift(array,i,length);
	return;
}

void Heap_Sort(int array[], int length, int m){
	Crt_Heap(array,length);
	for(int i = length; i > length - m; i--){
		array[0] = array[i];
		array[i] = array[1];
		array[1] = array[0];
		Sift(array,1,i-1);
	}
}

int main(){
	int m,n;
	int array[1001];
	while(cin>>n>>m && (m!=0 || n!=0)){
		for(int i=1; i<=n; i++)
			cin>>array[i];
		if(m >= n){
			sort(array+1,array+n+1);
			for(int i=n; i>=1; i--)
				cout<<array[i]<<' ';
			cout<<endl;
		}	
		else{
			Heap_Sort(array,n,m);
			for(int i=1; i <= m; i++)
				cout<<array[n-i+1]<<' ';
			cout<<endl;
		}
	}
	return 0;
}*/


int main(){
	int n,m;
	vector<int> array;
	array.reserve(1000);
	while(cin>>n>>m && ( n!=0 || m!=0)){
		array.clear();
		array.resize(n);
		for(int i=0; i<n; i++)
			cin>>array[i];
		sort(array.begin(),array.end());
		if(n <= m){
			for(int i=n-1; i>=0; i--)
				cout<<array[i]<<' ';
			cout<<endl;
		}
		else{
			for(int i=0; i<m; i++)
				cout<<array[ n-i-1 ]<<' ';
			cout<<endl;
		}
	}
	return 0;
}
