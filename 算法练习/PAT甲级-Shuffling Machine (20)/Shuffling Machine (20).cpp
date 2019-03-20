#include<iostream>
#include<map>
using namespace std;

void Crt_Map(map<int, string> &Dick){
	string str;
	int temp = 0;
	for(int i=0; i<4; i++){
		for(int j=0; j<13; j++){
			switch (i){
				case 0:
					str.append("S");
					break;
				case 1:
					str.append("H");
					break;
				case 2:
					str.append("C");
					break;
				case 3:
					str.append("D");
					break;
			}
			switch (j){
				case 0:
					str.append("1");
					break;
				case 1:
					str.append("2");
					break;
				case 2:
					str.append("3");
					break;
				case 3:
					str.append("4");
					break;
				case 4:
					str.append("5");
					break;
				case 5:
					str.append("6");
					break;
				case 6:
					str.append("7");
					break;
				case 7:
					str.append("8");
					break;
				case 8:
					str.append("9");
					break;
				case 9:
					str.append("10");
					break;
				case 10:
					str.append("11");
					break;
				case 11:
					str.append("12");
					break;
				case 12:
					str.append("13");
					break;
			}
			Dick[temp++] = str;
			str.clear();
		}
	}
	Dick[temp++] = "J1";
	Dick[temp] = "J2";
}

void Process(map<int, string> &Dick,int order[]){
	map<int ,string> temp(Dick);
	for(int i=0; i<54; i++){
		Dick[order[i]-1] = temp[i];
	}
}

int main(){
	int time;
	map<int, string> Dick;
	Crt_Map(Dick);
	int order[54];
	cin>>time;
	for(int i=0; i<54; i++)
		cin>>order[i];
	for(int i=0; i<time; i++)
		Process(Dick,order);
	for(int i=0; i<54; i++){
		if(i == 53)
			cout<<Dick[i]<<endl;
		else
			cout<<Dick[i]<<' ';
	}
	return 0;
}
