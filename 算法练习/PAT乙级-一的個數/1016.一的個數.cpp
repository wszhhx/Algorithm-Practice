#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n,r;
	while(scanf("%d %d",&n,&r)!=EOF)
	{
		vector<char> answer;
		int sum=0;
		while(n)
		{
			if(n%r>=10)
			{
				switch (n%r)
				{
					case 10:
						answer.push_back('A');
						break;
					case 11:
						answer.push_back('B');
						break;
					case 12:
						answer.push_back('C');
						break;
					case 13:
						answer.push_back('D');
						break;
					case 14:
						answer.push_back('E');
						break;
					case 15:
						answer.push_back('F');
						break;
					case 16:
						answer.push_back('G');
						break;
					case 17:
						answer.push_back('H');
						break;
					case 18:
						answer.push_back('I');
						break;
					case 19:
						answer.push_back('J');
						break;
					case 20:
						answer.push_back('K');
						break;
					case 21:
						answer.push_back('L');
						break;
					case 22:
						answer.push_back('M');
						break;
					case 23:
						answer.push_back('N');
						break;
					case 24:
						answer.push_back('O');
						break;
					case 25:
						answer.push_back('P');
						break;
					case 26:
						answer.push_back('Q');
						break;
					case 27:
						answer.push_back('R');
						break;
					case 28:
						answer.push_back('S');
						break;
					case 29:
						answer.push_back('T');
						break;
					case 30:
						answer.push_back('U');
						break;
					case 31:
						answer.push_back('V');
						break;
					case 32:
						answer.push_back('W');
						break;
					case 33:
						answer.push_back('X');
						break;
					case 34:
						answer.push_back('Y');
						break;
					case 35:
						answer.push_back('Z');
						break;
						
				}
				n=n/r;
			}
			else
			{
				answer.push_back(n%r+48);
				n=n/r;	
			}
			
		}
		reverse(answer.begin(),answer.end());
		for(int i=0;i<answer.size();i++)
		{
			if(answer[i]=='1')
				sum++;
		}
		cout<<sum<<endl; 
	}

	return 0;
}
