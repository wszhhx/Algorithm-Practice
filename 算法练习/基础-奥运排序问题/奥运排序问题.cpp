#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
typedef struct country{
	int Goal;
	int Medal;
	int People_Num;
	int Num;
	double Goal_Proportion;
	double Medal_Proportion;
}Country;

typedef vector<vector<int> > Ranking;

bool Compare_Goal(Country C1, Country C2){
	return C1.Goal > C2.Goal;
}

bool Compare_Medal(Country C1, Country C2){
	return C1.Medal > C2.Medal;
}

bool Compare_Goal_Proportion(Country C1, Country C2){
	return C1.Goal_Proportion > C2.Goal_Proportion;
}

bool Compare_Medal_Proportion(Country C1, Country C2){
	return C1.Medal_Proportion > C2.Medal_Proportion;
}


void Process(vector<Country> &C, vector<int> &Pro_C){
	Ranking ranking;
	ranking.resize(4);
	for(int i=0; i<4; i++)
		ranking[i].resize(C.size(),0);
		
	sort(C.begin(),C.end(),Compare_Goal);
	for(int j=0,i=1 ; j < C.size(); j++,i++){
		if(j>0 && C[j].Goal == C[j-1].Goal)
			ranking[0][ C[j].Num ] = --i;
		else
			ranking[0][ C[j].Num ] = i;
	}
	
	sort(C.begin(),C.end(),Compare_Medal);
	for(int j = 0,i = 1; j < C.size(); j++,i++){
		if(j>0 && C[j].Medal == C[j-1].Medal)
			ranking[1][ C[j].Num ] = --i;
		else
			ranking[1][ C[j].Num ] = i;
	}
	
	sort(C.begin(),C.end(),Compare_Goal_Proportion);
	for(int j = 0,i = 1; j < C.size(); j++,i++){
		if(j>0 && fabs(C[j].Goal_Proportion - C[j-1].Goal_Proportion) < 10e-5 )
			ranking[2][ C[j].Num ] = --i;
		else
			ranking[2][ C[j].Num ] = i;
	}
	
	sort(C.begin(),C.end(),Compare_Medal_Proportion);
	for(int j = 0,i = 1; j < C.size(); j++,i++){
		if(j>0 && fabs(C[j].Medal_Proportion - C[j-1].Medal_Proportion) < 10e-5 )
			ranking[3][ C[j].Num ] = --i;
		else
			ranking[3][ C[j].Num ] = i;
	}
	//接下来要根据规则输出
	int k;
	for(int i=0; i<Pro_C.size(); i++){
		k = 0;
		for(int j=1; j<4; j++){
			if(ranking[j][ Pro_C[i] ] < ranking[k][ Pro_C[i] ])
				k = j;
		}
		cout<<ranking[k][ Pro_C[i] ]<<':'<<k+1<<endl;
	}
}

int main(){
	int N,M;
	vector<Country> C;
	vector<int> Pro_C;
	while(cin>>N>>M){
		C.clear();
		Pro_C.clear();
		C.resize(N);
		Pro_C.resize(M);
		for(int i=0; i<N; i++){
			cin>>C[i].Goal>>C[i].Medal>>C[i].People_Num;
			C[i].Goal_Proportion = (double)C[i].Goal / C[i].People_Num;
			C[i].Medal_Proportion = (double)C[i].Medal / C[i].People_Num;
			C[i].Num = i;
		}
		for(int i=0; i<M; i++)
			cin>>Pro_C[i];
		Process(C,Pro_C);	
	}
	return 0;
}


