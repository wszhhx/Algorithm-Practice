#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int A,B,D;
	cin>>A>>B>>D;
	int SUM=A+B;
	vector<int> a;
	while(SUM>0)
	{
		a.insert(a.begin(),SUM%D);
		SUM=SUM/D;
	}
	for(int i=0;i<a.size();i++)
	{
		cout<<a[i];
	}
	return 0;
}
