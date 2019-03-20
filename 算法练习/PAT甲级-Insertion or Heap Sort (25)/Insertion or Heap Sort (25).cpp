/*
��Ŀ˵�������ģ���
  ����һ��ԭ���к�����һ������У�Ҫ�����б����ǲ��������Ƕ����򣬲�����ź��������
  
����������
  ÿ���������һ��������ÿ��������һ�и���һ��������N��        N<=100
��������һ������N����������N��������Ϊ��ʼ���У����һ�а���N����������N��������ĳ�����򷽷�����һ������У�����
Ŀ��������Զ���������������ÿո����

���������
  ����ÿ����������һ�������Insertion Sort�����ǡ�Heap Sort����ָ���м����������ĸ����򷽷����ɵģ������м����еĻ�����
�ٵ���һ�����򣬲�����м�����

�������룺10
		  3 1 2 8 7 5 9 4 6 0
		  1 2 3 7 8 5 9 4 6 0
	�����Insertion Sort
		  1 2 3 5 7 8 9 4 6 0 
*/
#include<iostream>
using namespace std;
bool IsEqual(int array1[],int array2[],int length){
	for(int i=1; i<=length; i++)
		if(array1[i]!=array2[i])
			return false;
	return true;
}

bool Insert_Sort(int array[],int n,int half[]){
	int isequal = false;
	int i,j;
	for(i=2; i<=n ;i++){
		array[0] = array[i];
		for(j = i-1; array[0] < array[j];j--)
			array[j+1] = array[j];
		array[j+1] = array[0];
		if(IsEqual(array,half,n)){
			isequal = true;
			break;
		}
	}
	if(isequal){
		i++;
		array[0] = array[i];
		for(j = i-1; array[0] < array[j];j--)
			array[j+1] = array[j];
		array[j+1] = array[0];
		return true;
	}
	return false;
}

void sift(int array[],int root, int tail){
	int fp = root;
	int p = root * 2;
	array[0] = array[root];
	bool finished = false;
	while(p <= tail && !finished){
		if(p < tail && array[p+1] > array[p])
			p++;
		if(array[p] <= array[0])
			finished = true;
		else{
			array[fp] = array[p];
			fp = p;
			p*=2;
		}
	}
	array[fp] = array[0];
	return;
}

void crt_heap(int array[],int length){
	int n = length/2;
	for(int i=n; i>=1; i--)
		sift(array,i,length);
	return;
}

bool Heap_Sort(int array[],int length, int half[]){
	bool isequal = false;
	int i;
	crt_heap(array,length);
	for(i=length; i>1; i--){
		if(IsEqual(array,half,length)){
			isequal = true;
			break;
		}
		array[0] = array[i];
		array[i] = array[1];
		array[1] = array[0];
		sift(array,1,i-1);
	}
	if(isequal){
		array[0] = array[i];
		array[i] = array[1];
		array[1] = array[0];
		sift(array,1,i-1);
		return true;
	}
	return false;
}

int main(){
	int n;
	cin>>n;
	int array1[n+1];
	int array2[n+1];
	int half[n+1];
	for(int i=1; i<=n; i++){
		scanf("%d",&array1[i]);
		array2[i] = array1[i];
	}
	for(int i=1; i<=n; i++)
		scanf("%d",&half[i]);
	if(Insert_Sort(array1,n,half)){
		printf("Insertion Sort\n");
		for(int i=1; i<=n; i++){
			if(i == n)
				printf("%d\n",array1[i]);
			else
				printf("%d ",array1[i]);
		}
	}
	else if(Heap_Sort(array2,n,half)){
		printf("Heap Sort\n");
		for(int i=1; i<=n; i++){
			if(i == n)
				printf("%d\n",array2[i]);
			else
				printf("%d ",array2[i]);
		}
	}
	return 0;
}
