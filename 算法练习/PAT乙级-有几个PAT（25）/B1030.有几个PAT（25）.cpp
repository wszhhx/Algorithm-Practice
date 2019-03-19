/*#include<iostream>
using namespace std;
int main()
{
	string str;
	cin>>str;
	double count=0;
	int N=str.length();
	for(int i=0;i<N-2;i++)
	{
		if(str[i]!='P')
		{
			continue;
		}
		else
		{
			for(int j=i+1;j<N-1;j++)
			{
				if(str[j]!='A')
				{
					continue;
				}
				else
				{
					for(int n=j+1;n<N;n++)
					{
						if(str[n]=='T')
						{
							count+=1;
							if(count>1000000007)
							{
								cout<<"超出了"<<endl;
								count-=1000000007;
							}
						}
						else
						{
							continue;
						}
					}
				}
			}
		}
	}
	cout<<count<<endl;
	return 0;*/
///===================================以上太耗时间！需要改进成下面的内容！====================
#include<iostream>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int n=str.length();
	int T=0;
	int AT=0;
	int PAT=0;
	for(int i=n-1;i>=0;i--)
	{
		if(str[i]=='T')
		{
			T++;
		}
		else if(str[i]=='A')
		{
			AT=(AT+T)%1000000007;
		}
		else
		{
			PAT=(PAT+AT)%1000000007;
		}
	}
	cout<<PAT;
}
 
