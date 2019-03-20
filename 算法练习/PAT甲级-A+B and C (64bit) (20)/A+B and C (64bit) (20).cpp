#include<iostream>
#include<vector>
using namespace std;
int main(){
	long long A,B,C;
	int T;
	vector<bool> charge;
	cin>>T;
	charge.resize(T,false);
	for(int i=0; i<T; i++){
		scanf("%lld %lld %lld",&A,&B,&C);
		long long D = A + B;
		if(A > 0 && B > 0 && D <= 0){
			charge[i] = true;
			continue;
		}
		if(A <0 && B < 0 && D >= 0){
			charge[i] = false;
			continue;
		}
		if(D <= C)
			continue;
		else
			charge[i] = true;
	}
	for(int i=0; i<T; i++){
		cout<<"Case #"<<i+1<<": ";
		if(charge[i])
			cout<<"true"<<endl;
		else
			cout<<"false"<<endl;
	}
	return 0;
}
