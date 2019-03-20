/*
1(1有1个)->11(1有2个)->12(1有1个2有1个)->1121(1有2个，2有1个,1有1个)
         ->122111->112213->12221131->1123123111
         
*/

#include<iostream>
#include<string>
#include<sstream>
#include<cstdlib>
using namespace std;

string LaS;


void Pass(){  //生成一次LOOKANDSEE序列 
	string new_LaS;
	int count = 0;
	char com_char;
	ostringstream os;
	for(int i=0; i<LaS.size();){
		com_char = LaS[i];     
		count = 0;      
		while(i < LaS.size() && LaS[i] == com_char){
			count++;
			i++;
		}
		
		new_LaS += com_char;
		new_LaS += (char)(count + 48);
	}
	LaS = new_LaS;
	return;
}

void GenerLas(int N){
	for(int i=1; i<N; ++i){
		Pass();
	}
	return;
}

int main(){
	int N;
	cin>>LaS>>N;
	GenerLas(N);	
	cout<<LaS<<endl;
	return 0;
}
