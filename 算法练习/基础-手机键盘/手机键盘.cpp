#include<iostream>
using namespace std;
int Proccess(string &str){
	int N = str.length();
	int time = 0,i = 1;
	if(str[0] <= 'o')
		time = (str[0]-(97+(str[0]-97)/3*3)+1) ;
	else if( 'p' <= str[0] && str[0] <= 's' )
		time = (str[0] - 'p' + 1);
	else if( 't' <= str[0] && str[0] <= 'v' )
		time = (str[0] - 't' + 1);
	else
		time = (str[0] - 'w' + 1);
	while(i < N){
		if(str[i] <= 'o')
			time += (str[i]-(97+(str[i]-97)/3*3)+1);
		else if( 'p' <= str[i] && str[i] <= 's' )
			time += (str[i] - 'p' + 1);
		else if( 't' <= str[i] && str[i] <= 'v' )
			time += (str[i] - 't' + 1);
		else
			time += (str[i] - 'w' + 1);
		if( (str[i]-97)/3 == (str[i-1]-97)/3  && str[i] <= 'o' && str[i-1] <= 'o' || 'p' <= str[i] && str[i] <= 's' && 'p' <= str[i-1] && str[i-1] <= 's' || 't' <= str[i] && str[i] <= 'v' && 't' <= str[i-1] && str[i-1] <= 'v' || 'w' <= str[i] && str[i] <= 'z' && 'w' <= str[i-1] && str[i-1] <= 'z')
			time += 2;
		i++;
	}
	return time;	
}

int main(){
	string str;
	while(cin>>str)
		cout<<Proccess(str)<<endl;
	return 0;
}
