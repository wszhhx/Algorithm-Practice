//ÎÊÌâÃèÊö
//Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way. 
// Output "Fu" first if it is negative.  For example, -123456789 is read as "Fu yi Yi er Qian san Bai si Shi 
//wu Wan liu Qian qi Bai ba Shi jiu".  Note: zero ("ling") must be handled correctly according to the Chinese tradition.  
//For example, 100800 is "yi Shi Wan ling ba Bai". 

//ÊäÈëÃèÊö
//Each input file contains one test case, which gives an integer with no more than 9 digits.

//Êä³öÃèÊö
//For each test case, print in a line the Chinese way of reading the number.  The characters are separated by a space and there 
//must be no extra space at the end of the line.
 

#include<iostream>
#include<vector>
using namespace std;
bool last_sentence = false;
bool already = false;
bool wan = false;
void My_Read_Word(char word){
	switch(word){
		case '1':
			cout<<"yi";
			break;
		case '2':
			cout<<"er";
			break;
		case '3':
			cout<<"san";
			break;
		case '4':
			cout<<"si";
			break;
		case '5':
			cout<<"wu";
			break;
		case '6':
			cout<<"liu";
			break;
		case '7':
			cout<<"qi";
			break;
		case '8':
			cout<<"ba";
			break;
		case '0':
			cout<<"ling";
			break;
		default:
			cout<<"jiu";
			
	}
	return;
}

void My_Read_Sentence(vector<char> &str_m){
	if(str_m.size() == 0)
		return;
	if(str_m[0] == '0'){
		str_m.erase( str_m.begin() );
		while(str_m[0] == '0' && str_m.size() > 0){
			str_m.erase( str_m.begin() );
		}
		if(str_m.size() > 0){
			if(!already)
				cout<<"ling ";
			My_Read_Sentence(str_m);
	
		}
		else
			return;
	
	}
	else{
		My_Read_Word(str_m[0]);
		switch(str_m.size()){
			case 4:
				cout<<" Qian";
				break;
			case 3:
				cout<<" Bai";
				break;
			case 2:
				cout<<" Shi";
				break;
		}
		str_m.erase( str_m.begin() );
		if(last_sentence){
			if(str_m.size() > 0){
				bool f = false;
				for(int i=0; i<str_m.size(); i++)
					if(str_m[i] != '0')
						f = true;
				if(f)
					cout<<' ';
				else
					return;
			}
		}
		else
			cout<<' ';
		My_Read_Sentence(str_m);
	}
	return;
}

void My_Read(vector<char> &str){
	if(str[0] == '-'){
		cout<<"Fu ";
		str.erase( str.begin() );
	}
	int n = str.size();
	if(n == 9){
		My_Read_Word(str[0]);
		cout<<" Yi";
		bool f1 = false;
		str.erase( str.begin() );
		for(int i=0; i<str.size(); i++)
			if(str[i] != '0')
				f1 = true;
		if(f1)
			cout<<' ';
		else
			return;
		n--;
	}
	if(n > 4 && n < 9){
		vector<char> str_m(str.begin(),str.begin() + ( str.size() - 4 ) );
		vector<char> str1(str.begin() + ( str.size() - 4 ),str.end());
		if(str_m.size() == 4 && str_m[0] == '0' && str_m[1] == '0' && str_m[2] == '0' && str_m[3] == '0'){
			wan = true;
			cout<<"ling";
			if(str1[0] == '0')
				already = true;
			if(str1[0] == '0' && str1[1] == '0' && str1[2] == '0' && str1[3] == '0')
				return;
		}
		My_Read_Sentence(str_m);
		if(!wan)
			cout<<"Wan";
		if(str1[0] == '0' && str1[1] == '0' && str1[2] == '0' && str1[3] == '0'){
			return;
		}
		else{
			cout<<' ';
			My_Read(str1);
		
		}
	}
	else{
		last_sentence = true;
		My_Read_Sentence(str);
		return;
	}
}

int main(){
	char c_str[10];
	int num;
	cin>>num;
	sprintf(c_str,"%d",num);
	string S(c_str);
	vector<char> str(S.begin(),S.end());
	if(str.size() == 1 && str[0] == '0')
		cout<<"ling";
	else
		My_Read(str);
	return 0;
}
