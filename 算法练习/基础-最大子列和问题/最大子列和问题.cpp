#include<iostream>
#include<string>
#include<sstream>
#define MAXSIZE 10000
using namespace std;
int main(){
	int array[MAXSIZE];
	int n;
	int i;
	int thissum;
	int maxsum;
	int dig;
	string Res;
	string trans;
	while(getline(cin,Res)){
		n = 0;
		while(!Res.empty()){
			for(;!Res.empty() && Res[0] != ',';){
				trans.push_back(Res[0]);
				Res.erase(0,1);
			}
			stringstream ss(trans);
			ss>>array[n++];
			trans.clear();
			if(Res.empty()){
				break;
			}
			else{
				Res.erase(0,1);
			}
		}
		thissum=0;
		maxsum=0;
		for(int i=0;i<n;i++){
			thissum+=array[i];
			if(thissum>maxsum)
				maxsum=thissum;
			if(thissum<=0)
				thissum=0;
		}
		cout<<maxsum;
	}
	
}
