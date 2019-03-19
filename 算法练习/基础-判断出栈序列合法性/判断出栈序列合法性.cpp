#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(int argc,char **argv){
	vector<int> Sequence;
	stack<int> S;
	int N,count = 0;
	cin>>N;
	Sequence.resize(N);
	for(int i = 0; i<N; i++)
		cin>>Sequence[i];
	for(int last = 0, coach; count < N; S.pop()){
		coach = Sequence[count];
		for(int p = last + 1;p<=coach;p++)	S.push(p);
		if(last < coach)	last = coach;
		if(S.top() != coach) break;
		count++;
	}
	cout<<(count == N? "Yes" : "No")<<endl;
}
