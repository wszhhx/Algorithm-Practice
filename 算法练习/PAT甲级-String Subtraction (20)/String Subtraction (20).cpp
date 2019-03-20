#include<iostream>
#include<string>
using namespace std;

void Remove_word(char str[],char aim){
	int i=0;
	int j=0;
	while(str[j] != '\0'){
		if(str[j] != aim)
			str[i++] = str[j++];
		else
			j++;
	}
	str[i] = '\0';
	return;
}

int main(){
	char str1[10000];
	char str2[10000];
	string str3;
	char temp;
	gets(str1);
	gets(str2);
	int i=0;
	while(str2[i] != '\0')
		i++;
	for(int j=0; j<i; j++){
		if(str3.find(str2[j]) == 0)
			continue;
		else{
			Remove_word(str1,str2[j]);
			str3.push_back(str2[j]);
		}
		
	}
	cout<<str1<<endl;
	return 0;
}
