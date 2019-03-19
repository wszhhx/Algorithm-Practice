//给定两个整数AA和BB，输出从AA到BB的所有整数以及这些数的和。

//输入格式：
//输入在一行中给出2个整数AA和BB，其中-100≤A≤B≤100，其间以空格分隔。

//输出格式：
//首先顺序输出从AA到BB的所有整数，每5个数字占一行，每个数字占5个字符宽度，向右对齐。最后在一行中按Sum = X的格式输出全部数字的和X。
#include<iostream>
#include<iomanip>
using namespace std;
/*int main(){
	int A,B;
	int flag=0;
	int sum=0;
	cin>>A>>B;
	for(int i=A;i<=B;i++){
		cout<<setw(5)<<right<<i;
		flag++;
		if(flag%5==0)
			cout<<endl;
		sum+=i;
	}
	if(flag%5==0)
		cout<<"sum="<<sum;
	else
		cout<<endl<<"Sum = "<<sum;
	return 0;
}*/
int main()  
{  
    int a, b;  
    int sum = 0;  
    int i,j;  
    scanf("%d %d", &a, &b);  
    for (i = a; i <= b; )  
    {  
        for (j = 1; j <= 5&&i<=b; j++)  
        {  
            printf("%5d", i);  
            i++;  
        }  
        printf("\n");  
    }  
    for (i = a; i <= b; i++)  
        sum += i;  
    printf("Sum = %d\n", sum);  
  
    return 0;  
}  
