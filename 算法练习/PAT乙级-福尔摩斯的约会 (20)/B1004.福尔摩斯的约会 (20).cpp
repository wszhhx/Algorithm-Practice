/*����̽����Ħ˹�ӵ�һ����ֵ�������������Լ��ɣ� 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm����
����̽�ܿ�������ˣ���������ֵ�����ʵ���Ͼ���Լ���ʱ�䡰������ 14:04������Ϊǰ�����ַ����е�1����ͬ�Ĵ�
дӢ����ĸ����Сд�����֣��ǵ�4����ĸ'D'�����������ģ���2����ͬ���ַ���'E'�����ǵ�5��Ӣ����ĸ������һ����
�ĵ�14����ͷ������һ���0�㵽23��������0��9���Լ���д��ĸA��N��ʾ�����������ַ�����1����ͬ��Ӣ����ĸ's'��
���ڵ�4��λ�ã���0��ʼ�������ϣ������4���ӡ��ָ��������ַ�������������Ħ˹����õ�Լ���ʱ�䡣*/
#include<iostream>
#include<string>
using namespace std;
void Week(char c);
void Hour(char c);
void Minute(string str1,string str2);
void Search(string str1,string str2,char &a,char &b);
int main()
{
	string str1,str2,str3,str4;
	cin>>str1;
	cin>>str2;
	cin>>str3;
	cin>>str4;
	char a,b;
	char &c1=a;
	char &c2=b;
	Search(str1,str2,c1,c2);
	Week(a);
	cout<<' ';
	Hour(b);
	cout<<':';
	Minute(str3,str4);
	return 0;
}

void Week(char c)
{
	switch(c)
	{
		case 'A':
			cout<<"MON";
			break;
		case 'B':
			cout<<"TUE";
			break;
		case 'C':
			cout<<"WED";
			break;
		case 'D':
			cout<<"THU";
			break;
		case 'E':
			cout<<"FRI";
			break;
		case 'F':
			cout<<"SAT";
			break;
		case 'G':
			cout<<"SUN";
			break;
	}
	return;
}

void Hour(char c)
{
	int x=(int)c;
	if(48<=x && x<=57)
	{
		cout<<'0'<<c;
		return;
	}
	else if(65<=x && x<=78)
	{
		cout<<x-55;
		return;
	}
	else
		return;
}

void Minute(string str1,string str2)
{
	for(int i=0;i<str1.length();i++)
	{
		if((int)str1[i]>=97 && (int)str1[i]<=122 && str1[i]==str2[i])
		{
			if(i<10)
			{
				cout<<'0'<<i;
				return;
			}
			else
			{
				cout<<i;
				return;
			}
		}
	}
}

void Search(string str1,string str2,char &a,char &b)
{
	int flag=0;
	int temp;
	for(int i=0;i<str1.length() && flag!=1;i++)
	{
		if(65<=(int)str1[i] && (int)str1[i]<=71 && str1[i]==str2[i])
		{
			a=str1[i];
			temp=i+1;
			flag=1;
		}
	}
	
	for(int i=temp;i<str1.length() && flag!=2;i++)
	{
			if((int)str1[i]>=48 && (int)str1[i]<=73 && str1[i]==str2[i] || (int)str1[i]>=65 && (int)str1[i]<=78 && str1[i]==str2[i])
			{
				b=str1[i];
				flag=2;
			}
		
	}
	
	return;
	
}

