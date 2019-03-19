#include<iostream>
#include<vector>
using namespace std;
struct answer
{
	int score;
	int sum;
	answer(int Score,int Sum=0):score(Score),sum(Sum){};	
};
int main()
{
	int N,K;
	vector<int> students;
	vector<answer> Answer;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int temp;
		cin>>temp;
		students.push_back(temp);
	}
	cin>>K;
	for(int i=0;i<K;i++)
	{
		int temp2;
		cin>>temp2;
		Answer.push_back(answer(temp2));
	}
	for(int i=0;i<Answer.size();i++)
	{
		for(int j=0;j<N;j++)
		{
			if(Answer[i].score==students[j])
			{
				Answer[i].sum+=1;
			}
		}
	}
	for(int i=0;i<Answer.size();i++)
	{
		if(i==(Answer.size()-1))
		{
			cout<<Answer[i].sum;
			break;
		}
		cout<<Answer[i].sum<<' ';
	}
	return 0;
}
