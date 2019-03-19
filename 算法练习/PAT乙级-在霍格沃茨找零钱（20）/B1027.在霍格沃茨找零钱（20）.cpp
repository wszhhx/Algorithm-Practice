#include<iostream>
#include<vector>
using namespace std;

class money
{
public:
	money(double galleon=0,double sinkle=0,double kunt=0):Galleon(galleon),Sinkle(sinkle),Kunt(kunt)
	{
		Total=(Galleon*17*29)+(Sinkle*29)+Kunt;
	}
	~money(){};
	void Remain()
	{
		double total=Total;
		int galleon=0;
		int sinkle=0;
		int kunt=0;
		while(total>493)
		{
			total=total-493;
			galleon++;
		}
		total=Total-galleon*17*29;
		while(total>29)
		{
			total=total-29;
			sinkle++;
		}
		kunt=Total-galleon*17*29-sinkle*29;
		Galleon=galleon;
		Sinkle=sinkle;
		Kunt=kunt;
		return;
	}
public:
	int Galleon;
	int Sinkle;
	int Kunt;
	double Total;
};
int main()
{
	int galleon;
	int sinkle;
	int kunt;
	scanf("%d.%d.%d",&galleon,&sinkle,&kunt);
	money P(galleon,sinkle,kunt);
	scanf("%d.%d.%d",&galleon,&sinkle,&kunt);
	money A(galleon,sinkle,kunt);
	money R;
	R.Total=(A.Total-P.Total);
	if(R.Total<0)
	{
		R.Total=-R.Total;
		R.Remain();
		cout<<'-'<<R.Galleon<<'.'<<R.Sinkle<<'.'<<R.Kunt<<endl;
	}
	else
	{
		R.Remain();
		cout<<R.Galleon<<'.'<<R.Sinkle<<'.'<<R.Kunt<<endl;
	}
	

	return 0;
}
