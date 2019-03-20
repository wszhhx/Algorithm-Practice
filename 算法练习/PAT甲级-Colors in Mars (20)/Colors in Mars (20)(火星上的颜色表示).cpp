//题目描述
//People in Mars represent the colors in their computers in a similar way as the Earth people.  That is, a color is represented by a 
//6-digit number, where the first 2 digits are for Red, the middle 2 digits for Green, and the last 2 digits  for Blue.  The only difference 
//is that they use radix 13 (0-9 and A-C) instead of 16.  Now given a color in three decimal numbers (each between 0 and 168), you are 
//supposed to output their Mars RGB values.

//输入描述:
//Each input file contains one test case which occupies a line containing the three decimal color values.


//输出描述:
//For each test case you should output the Mars RGB value in the following format: first output "#", then followed by a 6-digit 
//number where all the English characters must be upper-cased.  If a single color is only 1-digit long, you must print a "0" to the left.
#include<iostream>
#include<vector>
using namespace std;
char Translate(int n){
	if(n<10)
		return n+48;
	else{
		switch (n){
			case 10:    return 'A';
			case 11:	return 'B';
			case 12: 	return 'C';
		}
		
	}
	return 0;
}
int main(){
	int m[3];
	vector<char> s;
	s.insert(s.end(),'#');
	for(int i=0;i<3;i++){
		cin>>m[i];
	}
	for(int i=0;i<3;i++){
		s.insert(s.end(),Translate(m[i]/13));
		s.insert(s.end(),Translate(m[i]%13));
	}
	for(int i=0;i<s.size();i++)
		cout<<s[i];
	return 0;

}

//分析：目的在于把三个数，每个数字整形，取值范围为0~168.把这三个数转化为13进制的符号显示出来。 
