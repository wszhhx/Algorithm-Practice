//������������AA��BB�������AA��BB�����������Լ���Щ���ĺ͡�

//�����ʽ��
//������һ���и���2������AA��BB������-100��A��B��100������Կո�ָ���

//�����ʽ��
//����˳�������AA��BB������������ÿ5������ռһ�У�ÿ������ռ5���ַ���ȣ����Ҷ��롣�����һ���а�Sum = X�ĸ�ʽ���ȫ�����ֵĺ�X��
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
