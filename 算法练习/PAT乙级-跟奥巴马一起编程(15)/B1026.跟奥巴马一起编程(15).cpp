#include<iostream>
using namespace std;
int main()
{
	float N;
	char c;
	cin>>N>>c;
	int W=(int)N;
	int H=int(N/2+0.5);
	for(int i=0;i<H;i++)
	{
		if(i==0 || i==H-1)
		{
			for(int j=0;j<W;j++)
			{
				if(j==W-1)
				{
					cout<<c<<endl;
					continue;
				}
				cout<<c;
			}	
		}	
		else
		{
			for(int j=0;j<W;j++)
			{
				if(j==W-1)
				{
					cout<<c<<endl;
				}
				else if(j==0)
				{
					cout<<c;
				}
				else
				{
					cout<<' ';
				}
			}
		}
	}	
	return 0;
} 
