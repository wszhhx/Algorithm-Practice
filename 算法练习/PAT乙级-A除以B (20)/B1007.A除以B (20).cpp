#include<iostream>
#include<sstream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	string A;
	char answer[1000];
	int B;
	int Long=0;
	cin>>A>>B;
	int n=A.length()/5+1;  //记录段数
	int m=0;                  //记录第几段
	int An[n];	
	for(int i=0;i<A.length();i+=5)   //将一串离奇长的整数分割成若干字符串再转为同数量整型串 
	{
		char *temp;
		temp=new char[5];
		int p=0;
		for(int j=i;j<i+5;j++)
		{
			temp[p]=A[j];
			p++;
		}
		stringstream os;
		os<<temp;
		os>>An[m];
		delete []temp;
		m++;
	}	
	int Yushu=0;
	for(int i=0;i<n;i++)
	{
		int Shan;                //记录商值的整型 
		string temp2;            //记录此次循环的分段的字符串 
		stringstream os;	
		os<<An[i];				 //将此次循环的分段整数 
		temp2=os.str();			 // 转化为字符串temp2 
		cout<<"现在处理第"<<i<<"段"<<An[i]<<endl; 
		if(temp2.length()<5)     //如果为最后一个分段 
		{
			int flag=0;
			int get=An[i]/pow(10,temp2.length()-1);
			cout<<"第"<<i<<"段的第一位数字是"<<get<<endl;
			if(Yushu*10+get<B && i!=0)
			{
				cout<<"呀！不够除了也，补0！"<<endl;
				flag=1;
			}
			Shan=(Yushu*pow(10,temp2.length())+An[i])/B;  //求出商值 
			Yushu=Yushu*pow(10,temp2.length())+An[i];
			Yushu=Yushu%B;   
			stringstream os2;
			os2<<Shan;
			string str;
			str=os2.str();  //将商值转化为字符串记录在str中 
		    cout<<"第"<<i<<"段的商是"<<Shan<<endl;
			cout<<"第"<<i<<"段的余数是"<<Yushu<<endl;
			if(flag)
			{
				str=str.insert(0,"0");
				flag=0;
				cout<<"补完0啦！~"<<endl;
			}
			for(int j=0;j<str.length();j++)
			{	
				answer[Long]=str[j];
				Long++;
			}
			
		}
		else
		{
			int flag=0;
			int get=An[i]/pow(10,4);
			cout<<"第"<<i<<"段的第一位数字是"<<get<<endl;
			if(Yushu*10+get<B && i!=0)
			{
				flag=1;
			}
			Shan=(Yushu*pow(10,5)+An[i])/B;
			Yushu=Yushu*pow(10,5)+An[i];
			Yushu=Yushu%B;
			stringstream os3;
			os3<<Shan;
			string str;
			str=os3.str();
			//cout<<"商："<<Shan<<endl;
			//cout<<"余："<<Yushu<<endl;
			cout<<"第"<<i<<"段的商是"<<Shan<<endl;
			cout<<"第"<<i<<"段的余数是"<<Yushu<<endl;
			if(flag)
			{
				str=str.insert(0,"0");
				flag=0;
				cout<<"补完0啦！~"<<endl;
			}
			for(int j=0;j<str.length();j++)
			{
				answer[Long]=str[j];
				Long++;
			}
			
		}
		cout<<endl;
		
	}
	string answer2=answer;
	for(int i=0;i<answer2.length();i++)
	{
		if(answer2[i]!='0' && answer2[i]!='1' && answer2[i]!='2' && answer2[i]!='3' && answer2[i]!='4' && answer2[i]!='5' && answer2[i]!='6' && answer2[i]!='7' && answer2[i]!='8' && answer2[i]!='9')
		{
			answer2=answer2.erase(i);
		}
	}
	cout<<answer2<<' '<<Yushu<<endl;
	return 0;
}
