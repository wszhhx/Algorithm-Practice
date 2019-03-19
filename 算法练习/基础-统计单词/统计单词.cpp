#include<iostream>
using namespace std;
int main(){
	char s[1000];
	int count;
	while(gets(s)){
		string str(s);
		count = 0;
		for(int i = 0; i<str.length()-1; i++){
			if(str[i] != ' ' && str[i] != '.')
				count++;
			else{
				cout<<count<<' ';
				count = 0;
			}
		}
		cout<<count<<endl;
	}
	
	return 0;
}
