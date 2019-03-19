#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n;
	vector<int> M(4);
	M[0]=1;
	M[1]=2;
	M[2]=3;
	M[3]=4;
	for(int i=4;i<55;i++)
	{
		M.push_back(M[i-1]+M[i-3]);
	}
	while(cin>>n)
	{
		cout<<M[n-1]<<endl;
	}
	return 0;
}
