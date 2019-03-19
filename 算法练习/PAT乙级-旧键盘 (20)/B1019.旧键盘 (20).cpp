#include<iostream>
#include<vector>
using namespace std;
bool Find(char a,vector<char> &b)
{
	for(int i=0;i<b.size();i++)
	{
		if(b[i]==a)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string str1;
	string str2;
	vector<char> worst;
	cin>>str1>>str2;
	bool flag;
	for(int i=0;i<str1.length();i++)
	{
		if(str1[i]>='A' && str1[i]<='Z')
		{
			str1[i]=str1[i]+32;
		}
	}
	for(int i=0;i<str2.length();i++)
	{
		if(str2[i]>='A' && str2[i]<='Z')
		{
			str2[i]=str2[i]+32;
		}
	}
	for(int i=0;i<str1.length();i++)
	{
		for(int j=0;j<str2.length();j++)
		{
			if(str1[i]==str2[j])
			{
				flag=true;	
				break;
			}
			flag=false;
		}
		if(!flag)
		{
			if(Find(str1[i],worst))
			{
				worst.push_back(str1[i]);
			}
		}
	}
	for(int i=0;i<worst.size();i++)
	{
		if(worst[i]>='a' && worst[i]<='z')
		{
			worst[i]=worst[i]-32;
		}
	}
	for(int i=0;i<worst.size();i++)
	{
		cout<<worst[i];
	}
}
