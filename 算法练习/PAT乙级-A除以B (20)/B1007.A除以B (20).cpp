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
	int n=A.length()/5+1;  //��¼����
	int m=0;                  //��¼�ڼ���
	int An[n];	
	for(int i=0;i<A.length();i+=5)   //��һ�����泤�������ָ�������ַ�����תΪͬ�������ʹ� 
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
		int Shan;                //��¼��ֵ������ 
		string temp2;            //��¼�˴�ѭ���ķֶε��ַ��� 
		stringstream os;	
		os<<An[i];				 //���˴�ѭ���ķֶ����� 
		temp2=os.str();			 // ת��Ϊ�ַ���temp2 
		cout<<"���ڴ����"<<i<<"��"<<An[i]<<endl; 
		if(temp2.length()<5)     //���Ϊ���һ���ֶ� 
		{
			int flag=0;
			int get=An[i]/pow(10,temp2.length()-1);
			cout<<"��"<<i<<"�εĵ�һλ������"<<get<<endl;
			if(Yushu*10+get<B && i!=0)
			{
				cout<<"ѽ����������Ҳ����0��"<<endl;
				flag=1;
			}
			Shan=(Yushu*pow(10,temp2.length())+An[i])/B;  //�����ֵ 
			Yushu=Yushu*pow(10,temp2.length())+An[i];
			Yushu=Yushu%B;   
			stringstream os2;
			os2<<Shan;
			string str;
			str=os2.str();  //����ֵת��Ϊ�ַ�����¼��str�� 
		    cout<<"��"<<i<<"�ε�����"<<Shan<<endl;
			cout<<"��"<<i<<"�ε�������"<<Yushu<<endl;
			if(flag)
			{
				str=str.insert(0,"0");
				flag=0;
				cout<<"����0����~"<<endl;
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
			cout<<"��"<<i<<"�εĵ�һλ������"<<get<<endl;
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
			//cout<<"�̣�"<<Shan<<endl;
			//cout<<"�ࣺ"<<Yushu<<endl;
			cout<<"��"<<i<<"�ε�����"<<Shan<<endl;
			cout<<"��"<<i<<"�ε�������"<<Yushu<<endl;
			if(flag)
			{
				str=str.insert(0,"0");
				flag=0;
				cout<<"����0����~"<<endl;
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
