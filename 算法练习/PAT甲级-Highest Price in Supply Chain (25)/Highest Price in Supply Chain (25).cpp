/*#include<iostream>  //ÓÐ´ýÓÅ»¯ 
#include<cstdlib>
#include<cmath>
using namespace std;
int Path(int *mem,int index){
	int count = 0;
	for(;mem[index]!=-1;count++,index = mem[index]);
	return count;
}

int* GetPath(int *mem,int N){
	int *path;
	path = (int *)malloc(sizeof(int)*N);
	for(int i = 0; i<N; i++){
		path[i] = Path(mem,i);
	}
	return path;
}

void GetPrice(int *path,double *price,double r,double P,int N){
	for(int i = 1; i<=N; i++){
		price[i] = P*pow(1+r/100,path[i-1]);
	}
	return;
}

void GetHighest(double *price,int N){
	printf("%.2lf ",price[N]);
	int n = 1;
	double high = price[N];
	for(int i = N-1;price[i] == high;n++,i--);
	cout<<n<<endl;
	
}
int QKPass(double price[],int low,int high){
	price[0] = price[low];
	double temp;
	while(low<high){
		while(low<high && price[high]>=price[0])
			high--;
		price[low] = price[high];
		while(low < high && price[low]<=price[0])
			low++;
		price[high] = price[low];
	}
	price[low] = price[0];
	return low;
}

void qksort(double price[],int low,int high){
	int pos;
	if(low < high){
		pos = QKPass(price,low,high);
		qksort(price,pos+1,high);
		qksort(price,low,pos-1);
	}
	return;
}

void QKSort(double price[],int N){
	qksort(price,1,N);
	
	return;
}

int main(){
	int N;
	double P,r;
	int *mem;
	int *path;
	double *price;
	cin>>N;
	mem = (int *)malloc(sizeof(int)*N);
	price = (double *)malloc(sizeof(double)*(N+1));
	cin>>P>>r;
	for(int i = 0; i<N; i++)
		cin>>mem[i];
	path = GetPath(mem,N);
	GetPrice(path,price,r,P,N);
	QKSort(price,N);
	GetHighest(price,N);
	return 0;
}*/

#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int main(){
	int N,count = 0,temp,max_num = 1;
	int *retailer;
	double MaxPrice = 0;
	double TempPrice,P,r;
	cin>>N>>P>>r;
	retailer = (int *)malloc(sizeof(int)*N);
	for(int i = 0; i<N; i++)
		cin>>retailer[i];
	for(int i = 0; i<N; i++){
		temp = i;
		for(count = 0;retailer[temp] != -1;temp = retailer[temp],count++);
		TempPrice = P*pow(1+r/100,count);
		if(TempPrice>MaxPrice){
			MaxPrice = TempPrice;
			max_num = 1;
		}
		else if(TempPrice == MaxPrice)
			max_num++;
		else
			continue;
	}
	printf("%.2lf %d",MaxPrice,max_num);
}

