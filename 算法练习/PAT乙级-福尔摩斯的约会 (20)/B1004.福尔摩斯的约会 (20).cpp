/*大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。
大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大
写英文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里
的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出
现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，帮助福尔摩斯解码得到约会的时间。*/
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

