#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	string str1,str2,str3,str4;
	int count = 1;
	cin>>str1>>str2>>str3>>str4;
	int n = str1.length() > str2.length() ? str1.length() : str2.length();
	for(int i=0; i<n; i++){
		if(count == 1 && str1[i] == str2[i] && str1[i] >='A' && str1[i] <= 'G'){
			switch(str1[i]){
				case 'A':
					printf("MON ");
					break;
				case 'B':
					printf("TUE ");
					break;
				case 'C':
					printf("WED ");
					break;
				case 'D':
					printf("THU ");
					break;
				case 'E':
					printf("FRI ");
					break;
				case 'F':
					printf("SAT ");
					break; 
				case 'G':
					printf("SUN ");
					break;
			}
			count++;
			continue;
		}
		if(count == 2 && str1[i] == str2[i] && (str1[i] >= '0' && str1[i] <='9' || str1[i] >= 'A' && str1[i] <= 'N')){
			if(str1[i] >= '0' && str1[i] <= '9'){
				printf("%02d:",(int)(str1[i] - '0'));
			}
			else{
				printf("%02d:",(int)(str1[i] - 'A' + 10));
			}
			break;
		}
	}
	n = str3.length() > str4.length() ? str3.length() : str4.length();
	count = 0;
	for(int i=0; i<n; i++){
		if(str3[i] == str4[i] && (str4[i] <= 'Z' && str4[i] >= 'A' || str4[i] >='a' && str4[i] <='z')){
			printf("%02d",i);
			break;
		}
	}
	return 0;
}
