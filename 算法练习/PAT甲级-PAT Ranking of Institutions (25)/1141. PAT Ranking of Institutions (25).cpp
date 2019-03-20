/*
ID的第一个字母代表PAT等级，B/A/T。每个ID独一无二 
学校字母不会超过6个，大小写不敏感。
分数为0到100 
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

typedef pair<string, int> PAIR;
map<string, int> School;
map<string, int> Stu_count;

bool cmp_by_score(const PAIR &a,const PAIR &b){
	if(a.second == b.second){
		if(Stu_count[a.first] == Stu_count[b.first]){
			return a.first < b.first;
		}
		else
			return Stu_count[a.first] < Stu_count[b.first];
	}
	else
		return a.second > b.second;
}


int main(){
	string ID;
	string SH;
	int score;
	int N;
	int pre_score;
	int show_rank = 1;
	int real_rank = 1;
	cin>>N;
	for(int i=0; i<N; ++i){
		cin>>ID>>score>>SH;
		transform(SH.begin(),SH.end(),SH.begin(),::tolower);
		Stu_count[SH] += 1;
		switch(ID[0]){
			case 'B':
				School[SH] += (score*1.0/1.5);
				break;
			case 'A':
				School[SH] += (score*1.0);
				break;
			case 'T':
				School[SH] += (score*1.5);
				break;
		}
	}
	vector<PAIR> list(School.begin(),School.end());
	sort(list.begin(),list.end(),cmp_by_score);
	cout<<School.size()<<endl;
	pre_score = list[0].second;
	for(int i=0; i<list.size(); ++i){
		if(list[i].second != pre_score){
			show_rank = real_rank;
		}
		pre_score = list[i].second;
		cout<<show_rank<<' '<<list[i].first<<' '<< list[i].second <<' '<<Stu_count[list[i].first]<<endl;
		real_rank++;
	}
	return 0;
}
