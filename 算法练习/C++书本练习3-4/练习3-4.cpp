#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
int main()
{
	int sum=0;
	string a;
	ifstream in("abc.txt");
	for(string s;getline(in,s);)
	{
		cout<<s<<endl;
		if(s.find('*')!=-1)
		{
			for(stringstream sin(s);sin>>a;)
			{
				if(a=="25")
				{
					sum+=2;
				}
			}
		}
		else
		{
			for(stringstream sin(s);sin>>a;)
			{
				if(a=="25")
				{
					sum++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
