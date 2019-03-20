//ÌâÄ¿ÃèÊö
//Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

//ÊäÈëÃèÊö:
//Each input file contains one test case. Each case occupies one line which contains an N (<= 10100).


//Êä³öÃèÊö:
//For each test case, output in one line the digits of the sum in English words. There must be one space between 
//two consecutive words, but no extra space at the end of a line.
#include<iostream>
#include<vector>
using namespace std;
void ToEnglish(int x,bool flag){
	switch (x){
		case 0: printf("zero");  break;
		case 1: printf("one");   break;
		case 2: printf("two");   break;
		case 3: printf("three"); break;
		case 4: printf("four");  break;
		case 5: printf("five");  break;
		case 6: printf("six");   break;
		case 7: printf("seven"); break;
		case 8: printf("eight"); break;
		case 9: printf("nine");  break;
	}
	if(flag)
		printf(" ");
	return;
	
}

int main(){
    vector<char> c;
	char x;
	cin.get(x);
	while(x!='\n'){
		c.push_back(x);
		cin.get(x);
	}
	int sum=0;
	int temp[3];
	for(int i=0;i<c.size();i++){
		sum+=(int)c[i]-48;
	}
	int j=2;
	while(sum/10){
		temp[j]=sum%10;
		sum/=10;
		j--;
	}
	temp[j]=sum;
	for(int i=j;i<2;i++){
		ToEnglish(temp[i],true);
	}
	ToEnglish(temp[2],false);
	printf("\n");
	return 0;
}
