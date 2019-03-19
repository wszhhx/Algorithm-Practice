#include<iostream>
using namespace std;
bool find(char a,string str)
{
	for(int i=0;i<str.length();i++)
	{
		if(str[i]==a || str[i]>='a' && str[i]<='z' && str[i]-32==a || str[i]>='A' && str[i]<='Z' && str[i]+32==a)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	string wrong;
	string str;
	cin>>wrong>>str;
	if(find('+',wrong))
	{
		for(int i=0;i<str.length();i++)
		{
			if(str[i]>='A' && str[i]<='Z')
			{
				str.erase(i,1);
				i--;
			}
			else
			{
				continue;
			}
		}
	}
	char a;
	for(int i=0;i<str.length();i++)
	{
		if(find(str[i],wrong))
		{
			str.erase(i,1);
			i--;
		}
		else
		{
			continue;
		}
	}
	cout<<str;
	return 0;
}
