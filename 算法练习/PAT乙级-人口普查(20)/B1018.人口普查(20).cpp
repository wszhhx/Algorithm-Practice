#include<iostream>
#include<vector>
using namespace std;
bool Bigger(string a,string b)
{
	for(int i=0;i<10;i++)
	{
		if(a[i]>b[i])
		{
			return true;
		}
		else if(a[i]<b[i])
		{
			return false;
		}
		else
		{
			continue;
		}
	}
}

int main()
{
	int count=0;
	int n;
	cin>>n;
	string name,oldname,youngname;
	string birthday;
	string big="1814/09/05";
	string small="2014/09/07";
	for(int i=0;i<n;i++)
	{
		cin>>name>>birthday;
		if(Bigger(birthday,"1814/09/05") && Bigger("2014/09/07",birthday))
		{
			count++;
			if(Bigger(birthday,big))
			{
				big=birthday;
				youngname=name;
			}
			if(Bigger(small,birthday))
			{
				small=birthday;
				oldname=name;
			}
		}
	}
	if(count>0)
	{
		cout<<count<<' '<<oldname<<' '<<youngname;
	}
	else
	{
		system("pause");
	}
	return 0;
}
