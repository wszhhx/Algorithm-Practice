#include<iostream>
#include<sstream>
using namespace std;
int main(){
	int num1,num2,i,j;
	char str1_[6],str2_[6];
	while(cin>>num1){
		num2 = num1*num1;
		sprintf(str1_,"%d",num1);
		sprintf(str2_,"%d",num2);
		string str1(str1_);
		string str2(str2_);
		i = str2.length() - 1;
		j = str1.length() - 1;
		for( ;str2[i] == str1[j] && j >= 0;i--,j-- );
		if(j == -1)
			cout<<"Yes!"<<endl;
		else
			cout<<"No!"<<endl;
	}
	return 0;
}
