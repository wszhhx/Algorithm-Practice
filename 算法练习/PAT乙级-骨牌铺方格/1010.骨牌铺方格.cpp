#include<iostream>  
using namespace std;  
#define MAX 90
long long arr[MAX];
int main()  
{  
    int num;  
    arr[1]=1;arr[2]=2;  
    for(int i=3;i<=90;i++)  
    {
    	arr[i]=arr[i-1]+arr[i-2];
	}
	
    while(scanf("%d",&num)!=EOF)  
    {  
        cout<<arr[num]<<endl;
    }  
    return 0;  
}  
