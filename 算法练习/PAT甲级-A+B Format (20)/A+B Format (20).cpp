#include<iostream>
#include<stack>
using namespace std;
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int d = a + b;
	char ans[20];
	sprintf(ans,"%d",d);
	int n = 0;
	while(ans[n]!='\0') n++;
	int count = 0;
	stack<char> S;
	if(d<0){
		for(int i=n-1; i>0; --i){
			if(count%3==0 && count!=0)
				S.push(',');
			S.push(ans[i]);
			count++;
		}
		S.push('-');
	}
	else{
		for(int i=n-1; i>=0; --i){
			if(count%3==0 && count!=0)
				S.push(',');
			S.push(ans[i]);
			count++;
		}
	}
	while(!S.empty()){
		printf("%c",S.top());
		S.pop();
	}
}
