#include<iostream>
#include<string>
using namespace std;

int main(){
	char Keyboard[] = {'q','w','e','r','t','y','u','i','o','p','a','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m',
					   'Q','W','E','R','T','Y','U','I','O','P','A','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M'};
	char Nature[52];
	for(int i=0; i<26; ++i)
		Nature[i] = (char)(i+97);
	for(int i=26; i<52; ++i)
		Nature[i] = (char)(i+39);
	string Aim;
	while(getline(cin,Aim)){
		for(int i=0; i<Aim.size(); ++i){
			if(Aim[i] >= 'a' && Aim[i] <='z'){
				cout<<Keyboard[Aim[i] - 97];
			}
			else if(Aim[i] >= 'A' && Aim[i] <='Z'){
				cout<<Keyboard[Aim[i] - 39];
			}
			else{
				cout<<Aim[i];
			}
		}
	} 
	return 0;
} 
