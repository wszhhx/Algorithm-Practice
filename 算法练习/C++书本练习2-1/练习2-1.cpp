#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
double jiechen(int n)
{
	if(n==1)
	{
		return n;
	}
	else
	{
		return (double)n*jiechen(n-1);
	}
}
int main()
{
	double x;
	double sum=1;
	cin>>x;
	int j=1;
	/*for(int i=1;pow(x,i)/jiechen(i)>=0.00000001;i++)
	{
		sum+=pow(x,i)/jiechen(i);
	}*/
	while(pow(x,j)/jiechen(j)>=0.00000001)
	{
		if(j%2==1)
		{
			sum+=pow(x,j)/jiechen(j);	
		}
		else
		{
			sum-=pow(x,j)/jiechen(j);
		}
		j++;
	}
	cout<<fixed<<setprecision(8)<<sum;
}
