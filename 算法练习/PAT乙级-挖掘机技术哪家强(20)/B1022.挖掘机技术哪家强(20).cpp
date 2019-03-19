#include<iostream>
#include<vector>
using namespace std;
struct member
{
	int school;
	int score;
	member(int School,int Score):school(School),score(Score){
	}	
};

int main()
{
	int N;
	cin>>N;
	vector<member> a;
	int school;
	int score;
	for(int i=0;i<N;i++)
	{
		cin>>school>>score;
		a.push_back(member(school,score));
	}
	vector<int> b(100001,0);
	for(int i=0;i<a.size();i++)
	{
		b[a[i].school]+=a[i].score;
	}
	int flag=0;
	for(int i=1;i<100001;i++)
	{
		if(b[i]>b[flag])
		{
			flag=i;
		}
	}
	cout<<flag<<' '<<b[flag]; 
	return 0;
}
