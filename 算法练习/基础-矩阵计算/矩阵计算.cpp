#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int temp;
	int n=pow(N,N);
	vector<int> a;
	vector<vector<int> > b;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cin>>temp;
			a.push_back(temp); 
		}
		b.push_back(a);
		a.clear();
	}
}
