#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<cmath>
#include<vector>
//===========================数学积分答案为16.36237457642 
using namespace std;
struct coor
{
	double x;
	double y;
	bool charge;
	coor(double X,double Y):x(X),y(Y),charge(false){}
	void Charge()
	{
		if((x*x/4+y*y/7)<=1)
		{
			charge=true;
		}
		else
		{
			charge=false;
		}
	}
};

int main()
{
	double x;
	double y;
	vector<coor> COOR;
	srand((unsigned int)time(NULL));
	for(int i=0;i<=1000000;i++)
	{
		x=-2+(double)(4.0*rand())/(RAND_MAX+1.0);
		y=-sqrt(7)+(double)(2*sqrt(7)*rand())/(RAND_MAX+1.0);
		COOR.push_back(coor(x,y));
		COOR[i].Charge();
	}
	int yes=0;
	int no=0;
	for(int i=0;i<COOR.size();i++)
	{
		if(COOR[i].charge)
		{
			yes++;
		}
		else
		{
			no++;
		}
	}
	cout<<4*2*sqrt(7)*(double)yes/(no+yes)<<endl;
	
	
	return 0;
}
