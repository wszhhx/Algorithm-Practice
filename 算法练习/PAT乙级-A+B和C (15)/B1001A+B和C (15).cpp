//给定区间[-2的31次方, 2的31次方]内的3个整数A、B和C，请判断A+B是否大于C。
#include<iostream>
using namespace std;
int main()
{
	int n; //组数
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
