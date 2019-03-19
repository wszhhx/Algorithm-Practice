#include<iostream>
#include<vector>
using namespace std;
int count=0;
bool isnumber(vector<char> a)
{
	for(int i=0;i<17;i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

void charge(int Z,vector<char> a)
{
	char str[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	if(str[Z]!=a[17])
	{
		for(int i=0;i<18;i++)
		{
			if(i==17)
			{
				cout<<a[i]<<endl;
				break;
			}
			else
			{
				cout<<a[i];
			}
		}
		count++;
	}
	return;
}
int main()
{
	int N;
	cin>>N;
	vector<vector<char> > number(N);
	int qz[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	for(int i=0;i<N;i++)
	{
		char Temp;
		for(int j=0;j<18;j++)
		{
			cin>>Temp;
			number[i].push_back(Temp);
		}
	}
	for(int i=0;i<N;i++)
	{
		if(isnumber(number[i]))
		{
			int *temp=new int;
			*temp=0;
			for(int j=0;j<17;j++)
			{
				*temp+=(int(number[i][j])-48)*qz[j];
			}
			*temp=*temp%11;
			charge(*temp,number[i]);
			delete temp;
			temp=NULL;
		}
		else
		{
			count++;
			for(int j=0;j<18;j++)
			{
				if(j==17)
				{
					cout<<number[i][j]<<endl;
					break;
				}
				else
				{
					cout<<number[i][j];
				}
			}


		}
	}
	if(count==0)
	{
		cout<<"All passed";
	}
	return 0;
}

