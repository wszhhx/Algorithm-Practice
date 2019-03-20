#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int getDouble(char Result[],char Double[],int R_n){
	int P_in = 0;
	int D_n = 0;
	int temp;
	int index = R_n-1;
	int inbit = 0;
	if(Result[0] >= '5'){
		D_n = R_n + 1;
		for(int i=D_n-1; i>=1; --i){
			if(i==1){
				temp = (Result[index] - '0')*2 + inbit;
				Double[1] = temp%10 + '0';
				Double[0] = temp/10 + '0';
			}
			else{
				temp = (Result[index] - '0')*2 + inbit;
				inbit = temp/10;
				Double[i] = temp%10 + '0';
			}
			--index;
		}
	}
	else{
		D_n = R_n;
		for(int i=D_n-1; i>=0; --i){
			temp = (Result[index] - '0')*2 + inbit;
			inbit = temp/10;
			Double[i] = temp%10 + '0';
			--index;
		}
	}
	return D_n;
}

int main(){
	char Result[21];
	char Double[22];
	int R_n = 0;
	scanf("%s",Result);
	while(Result[R_n] != '\0')
		++R_n;
	int D_n = getDouble(Result,Double,R_n);
	if(D_n > R_n){
		printf("No\n%s",Double);
		return 0;
	}
	string str_D(Double);
	sort(Result,Result+R_n);
	sort(Double,Double+D_n);
	if(strcmp(Result,Double) == 0){
		printf("Yes\n");
		cout<<str_D;
	}
	else{
		printf("No\n");
		cout<<str_D;
	}
	return 0;
}
