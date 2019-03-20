#include<iostream>
using namespace std;
int main(){
	char str[80];
	scanf("%s",str);
	int n = 0;
	while(str[++n]!='\0');
	int side;
	int bottom;
	side = (n+2)/3;
	bottom = n - 2*side + 2;
	int left = 0;
	int right = n-1;
	for(int i=0; i<side-1; i++, left++, right--){
		printf("%c",str[left]);
		for(int j=0; j<bottom-2; j++)
			printf(" ");
		printf("%c\n",str[right]);
	}	
	for(int i=left; i<=right; i++)
		printf("%c",str[i]);
	return 0;
}
