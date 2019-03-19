#include<iostream>  
#include<algorithm>  
using namespace std;  
int main()  
{  
        int N;  
        int A1[101], A2[101];  // 原始序列A1  中间序列A2  
        int i, j;  
        cin>>N;  
        for( i=0; i<N; i++ )    cin>>A1[i];  
        for( i=0; i<N; i++ )    cin>>A2[i];  
  
        for( i=0; A2[i]<=A2[i+1] && i<N-1; i++ ) ; // i作为有序序列最后一个元素下标退出循环  
        for( j=++i; A1[j]==A2[j] && j<N; j++  ) ;    // A1 A2从 第一个无序的元素开始 逐一比对  
  
        if( j==N ){// 前半部分有序而后半部分未改动可以确定是插入排序  
            cout<<"Insertion Sort"<<endl;  
            sort( A1, A1+i+1 );  
        }  
        else{  
            cout<<"Merge Sort"<<endl;  
            int k = 1;  
            int flag=1;         //用来标记是否归并到 “中间序列”  
            while( flag )  
            {  
                    flag = 0;  
                    for( i=0; i<N; i++ )  
                        if( A1[i]!=A2[i] )  
                            flag = 1;  
                    k*=2;  
                    for( i=0; i<N/k; i++ )  
                        sort( A1+i*k, A1+(i+1)*k );  
                    for( i=k*(N/k); i<N; i++ ) // 对 非偶数序列的“尾巴”进行排序  
                        sort( A1+k*(N/k), A1+N );  
            }  
        }  
        cout<<A1[0];  
        for( i=1; i<N; i++ )  
            cout<<" "<<A1[i];  
        cout<<endl;  
  
        return 0;  
}  
