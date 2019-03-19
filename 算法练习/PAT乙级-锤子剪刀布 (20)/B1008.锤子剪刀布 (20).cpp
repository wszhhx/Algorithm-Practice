#include<iostream>
using namespace std;
class Gamer
{
	public:
		Gamer():Loss(0)
		{
			Win[0][0]=67;
			Win[1][0]=74;
			Win[2][0]=66;
			Win[0][1]=0;
			Win[1][1]=0;
			Win[2][1]=0;
		}
		~Gamer(){}
		Gamer(const Gamer &gamer){}
	public:
		int Win[3][2];
		int Loss;	
};
int main()
{
	Gamer A;
	Gamer B;
	int cout=0;
	int p=0;
	char Aw,Bw;
	cin>>cout;
	char ZHX[cout][2]; 
	for(int i=0;i<cout;i++)
	{
		for(int j=0;j<2;j++)
		{
			cin>>ZHX[i][j];
		}
	}
	
	for(int i=0;i<cout;i++)
	{
		if(ZHX[i][0]=='C' && ZHX[i][1]=='J' || ZHX[i][0]=='J' && ZHX[i][1]=='B' || ZHX[i][0]=='B' && ZHX[i][1]=='C')
		{
			B.Loss+=1;
			if(ZHX[i][0]=='C')
				A.Win[0][1]+=1;
			else if(ZHX[i][0]=='J')
				A.Win[1][1]+=1;
			else
				A.Win[2][1]+=1;
		}
		else if(ZHX[i][0]==ZHX[i][1])
		{
			p++;
		}
		else
		{
			A.Loss+=1;
			if(ZHX[i][1]=='C')
				B.Win[0][1]+=1;
			else if(ZHX[i][1]=='J')
				B.Win[1][1]+=1;
			else
				B.Win[2][1]+=1; 
		}
	}
	int temp=0;
	if(A.Win[2][1]>=A.Win[0][1] && A.Win[2][1]>=A.Win[1][1])
	{
		Aw=(char)A.Win[2][0];
	}
	else if(A.Win[0][1]>A.Win[2][1] && A.Win[0][1]>=A.Win[1][1])
	{
		Aw=(char)A.Win[0][0];
	}
	else
		Aw=(char)A.Win[1][0];
		
	if(B.Win[2][1]>=B.Win[0][1] && B.Win[2][1]>=B.Win[1][1])
	{
		Bw=(char)B.Win[2][0];
	}
	else if(B.Win[0][1]>B.Win[2][1] && B.Win[0][1]>=B.Win[1][1])
	{
		Bw=(char)B.Win[0][0];
	}
	else
		Bw=(char)B.Win[1][0];
		
	int aw=A.Win[0][1]+A.Win[1][1]+A.Win[2][1];
	int bw=B.Win[0][1]+B.Win[1][1]+B.Win[2][1];
	int al=A.Loss;
	int bl=B.Loss;
	std::cout<<aw<<' '<<p<<' '<<al<<std::endl;
	std::cout<<bw<<' '<<p<<' '<<bl<<std::endl;
	std::cout<<Aw<<' '<<Bw<<std::endl;
	
	return 0;

	
}
