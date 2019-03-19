#include<iostream>
#include<cmath>
using namespace std;

bool Is_Prime(int a){
	int n = sqrt(a);
	if( a == 2 )
		return true;
	for(int i = 2; i<=n ;i++){
		if(a%i == 0)
			return false;
	}
	return true;
}

int Count(int num){
	int i;
	if(Is_Prime(num))	return 1;
	for(i = 2; i<=sqrt(num); i++)
		if(num%i == 0 && Is_Prime(i))
			break;
	return Count(num/i) + 1;
}

int main(){
	int num;
	int i = 1;
	while(cin>>num)
		cout<<Count(num)<<endl;
	return 0;
}
