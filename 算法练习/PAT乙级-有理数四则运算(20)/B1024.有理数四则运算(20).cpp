#include<iostream>
#include<vector>
using namespace std;
class member
{
public:
	int gys(int son,int mother)
	{
		int gys;
		if(son==0)
		{
			return 1;	
		} 
		for(int i=1;i<=son;i++)
		{
			if(son%i==0 && mother%i==0)
			{
				gys=i;
			}
		}
		return gys;
	}
	member(int son,int mother):SON2(son),MOTHER2(mother)
	{
		if(mother==0)
		{

			wuli=true;
			INT=0;
			MOTHER=0;
			SON=0;
		}
		else
		{
			wuli=false;
			if(son<0 && mother>0 || son>0 && mother<0)
			{
				flag=false;
			}
			else
			{
				flag=true;
			}
			if(son<0)
			{
				son=-son;
			}
			if(mother<0)
			{
				mother=-mother;
			}
			if(son%mother==0)
			{
				INT=son/mother;
				SON=0;
				mother=1;
			}
			else
			{
				int GYS=gys(son,mother);
				mother=mother/GYS;
				son=son/GYS;
				INT=son/mother;
				SON=son%mother;	
				MOTHER=mother;
			}
		}
	}
	~member(){
	};
public:
	int SON2;
	int MOTHER2;
	int INT;
	int SON;
	int MOTHER;
	bool flag;    //true:正数        false:负数 
	bool wuli;
};

void output(member a)
{
	if(a.SON==0)
	{
		if(a.flag)
		{
			cout<<a.INT;
		}
		else
		{
			cout<<'('<<-a.INT<<')';
		}
	}
	else
	{
		if(a.flag)
		{
			if(a.INT==0)
			{
				cout<<a.SON<<'/'<<a.MOTHER;
			}
			else
			{
				cout<<a.INT<<' '<<a.SON<<'/'<<a.MOTHER;
			}
		}
		else
		{
			if(a.INT==0)
			{
				cout<<'('<<-a.SON<<'/'<<a.MOTHER<<')';
			}
			else
			{
				if(a.MOTHER==1)
				{
					cout<<"纯整数@"<<endl;
					cout<<'('<<-a.INT<<')';
				}
				else
				{
					cout<<'('<<-a.INT<<' '<<a.SON<<'/'<<a.MOTHER<<')';
				}
			}
			
		}
	}
}

int main()
{
	int son,mother;
	scanf("%d/%d",&son,&mother);
	member Left(son,mother);
	scanf("%d/%d",&son,&mother);
	member Right(son,mother);
	
	//====================================================================================================================
	member temp=member((Left.SON2*Right.MOTHER2)+(Right.SON2*Left.MOTHER2),Left.MOTHER2*Right.MOTHER2);
	output(Left);
	cout<<" + ";
	output(Right);
	cout<<" = ";
	output(temp);
	cout<<endl;
	
	//============================================================================================================
	temp=member((Left.SON2*Right.MOTHER2)-(Right.SON2*Left.MOTHER2),Left.MOTHER2*Right.MOTHER2);
	output(Left);
	cout<<" - ";
	output(Right);
	cout<<" = ";
	output(temp);
	cout<<endl;
	//====================================================================================================================
	temp=member(Left.SON2*Right.SON2,Left.MOTHER2*Right.MOTHER2);
	output(Left);
	cout<<" * ";
	output(Right);
	cout<<" = ";
	output(temp);
	cout<<endl;
	//==========================================================================================================
	temp=member(Left.SON2*Right.MOTHER2,Left.MOTHER2*Right.SON2);
	output(Left);
	cout<<" / ";
	output(Right);
	cout<<" = ";
	if(Right.SON2==0)
	{
		cout<<"Inf"<<endl;
	}
	else
	{
		output(temp);
		cout<<endl;	
	}
	
	return 0;
}
