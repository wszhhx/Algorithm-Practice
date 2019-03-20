#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int Process(char left[],char right[]){
	int i_left;
	int i_right;
	sscanf(left,"%d",&i_left);
	sscanf(right,"%d",&i_right);
	return i_left - i_right;
}

bool deCompare(char a,char b){
	return a>b;
}

int main(){
	char str[5];
	char left[5];
	char right[5];
	scanf("%s",str);
	string str_s(str);
	while(str_s.length() < 4)
		str_s.push_back('0');
	strcpy(str,str_s.c_str());
	int pre_ans = 0;
	int now_ans = 0;
	sscanf(str,"%d",&now_ans);
	while(true){
		pre_ans = now_ans;
		sort(str,str+4,deCompare);
		strcpy(left,str);
		sort(str,str+4);
		strcpy(right,str);
		now_ans = Process(left,right);
		if(now_ans == pre_ans)
			break;
		sprintf(str,"%04d",now_ans);
		printf("%s - %s = %s\n",left,right,str);
		
	}
	return 0;
}
