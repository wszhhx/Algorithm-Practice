//��������[-2��31�η�, 2��31�η�]�ڵ�3������A��B��C�����ж�A+B�Ƿ����C��
#include<iostream>
using namespace std;
int main()
{
	int n; //����
	cin>>n;
	long int array[n][3];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>array[i][j];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(array[i][0]+array[i][1]>array[i][2])
		{
			cout<<"Case #"<<i+1<<": true"<<endl;
		}
		else
		{
			cout<<"Case #"<<i+1<<": false"<<endl;
		}
	}
	 
	return 0;
}
