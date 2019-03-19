#include<iostream>
#include<vector>
using namespace std;

class count
{
	public:
		count()
		{
			counter=0;
		}
		~count(){}
	public:
		char name;
		int counter;
};

int search(count b[],char c,int n)
{
	for(int i=0;i<n;i++)
	{
		if(b[i].name==c)
			return i;
	}
}

bool exist(count b[],char c,int n)
{
	for(int i=0;i<n;i++)
	{
		if(b[i].name==c)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	count b[10];
	int counter=0; 
	vector<char> a;
	char temp;
	while(temp!='\n')
	{
		temp=getchar();
		a.push_back(temp);
	}
	a.erase(a.end()-1);
	for(int i=0;i<a.size();i++)
	{
		if(exist(b,a[i],counter))
		{
			b[search(b,a[i],counter)].counter+=1;
		}
		else
		{
			b[counter].name=a[i];
			b[counter].counter=1;
			counter++;
		}
	}
	for(int i=0;i<counter-1;i++)
	{
		for(int j=0;j<counter-1-i;j++)
		{
			if(b[j].name>b[j+1].name)
			{
				count temp2;
				temp2=b[j];
				b[j]=b[j+1];
				b[j+1]=temp2;
			}
		}
	}
	for(int i=0;i<counter;i++)
	{
		cout<<b[i].name<<':'<<b[i].counter<<endl;
	}
	return 0;
}
