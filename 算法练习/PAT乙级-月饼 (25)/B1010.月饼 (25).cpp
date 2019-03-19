#include<iostream>
#include<iomanip>
using namespace std;
//===========================
class MoonCake
{
	public:
		MoonCake(double m_Ton=0,double m_Sum=0):Ton(m_Ton),Sum(m_Sum)
		{
			Cost=0;
			Remain=0;
			Sell=0;
		}
		void Star()
		{
			Cost=Sum/Ton;
			Remain=Ton;
		}
		~MoonCake(){}
	public:
		double Ton;
		double Sum;
		double Cost;
		double Remain;
		double Sell;
};
//===========================
void Paixu(MoonCake Cake[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(Cake[j].Cost<Cake[j+1].Cost)
			{
				MoonCake temp=MoonCake();
				temp=Cake[j];
				Cake[j]=Cake[j+1];
				Cake[j+1]=temp;

			}
		}
	}
	return;
}
//===========================
int main()
{
	int N;
	int D;
	cin>>N>>D;
	int Remain=D;
	MoonCake Cake[1000];
	//===========================
	for(int i=0;i<N;i++)
	{
		cin>>Cake[i].Ton;
	}
	for(int i=0;i<N;i++)
	{
		cin>>Cake[i].Sum;
	}
	for(int i=0;i<N;i++)
	{
		Cake[i].Star();
	}
	//============================
	Paixu(Cake,N);
	int count=0;
	while(Remain>0)
	{
		if(Remain-Cake[count].Ton>0 && count<N)
		{
			Cake[count].Remain=0;
			Cake[count].Sell=Cake[count].Ton;
			Remain-=Cake[count].Ton;
			count++;
			continue;
		}
		else
		{
			Cake[count].Sell=Remain;
			Cake[count].Remain=Cake[count].Ton-Remain;
			Remain=0;
			count++;
			continue;
		}
	}
	double Income=0;
	for(int i=0;i<count;i++)
	{
		Income+=Cake[i].Cost*Cake[i].Sell;
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<Income<<endl;

	
	return 0;
}
