#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1;
	string str2;
	int count=0;
	bool charge=true;
	cin>>str1>>str2;
	int len1=str1.length();
	int len2=str2.length();
	for(int i=0;i<len2;i++)
	{
		int temp=str1.find(str2[i],0);
		if(temp!=-1)
		{
			str1.erase(str1.begin()+temp);
		}
		else
		{
			count++;
			charge=false;
		}
	}
	if(charge)
	{
		cout<<"Yes"<<' '<<len1-len2;
	}
	else
	{
		cout<<"No"<<' '<<count;
	}
	return 0;
}
