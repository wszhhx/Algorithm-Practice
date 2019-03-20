/*
题目描述：
  日语因其千变万化的结束音而“臭名昭著”，一个人的习惯结束语常常反映出这个人的个性，这样的习惯称为“Kuchigues”而这种习惯在日本动漫
和漫画中会进行艺术性夸张，举个例子：以"nyan~"音为结尾的句子常常代表说这个句子的人是个“猫控”
好疼，nyan~
我讨厌忍者，nyan~
现在给你几句某个癖好者说的句子，你能分析出它的尾音是啥吗？

输入描述：
  每次输入包含一个用例，对于每个用例，第一行给出一个正整数N   （2<=N<=100）
接下来的N行每行是一句字符数在0~256的句子，每句话代表某个性格的人所说的话，且大小写敏感。

输出描述：
  对于每个用例，输出这个特征的人的尾音，即：所有句子共有的，最长的那个尾缀，如果找不到，则输出“nai”
  
IP:3
   Itai nyan~
   Ninjin wa iyadanyan~
   uhhh nyan~
   
OP:nyan~ 
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool Is_Find(vector<string> &Strs, char aim, int R_index){
	int N = Strs.size();
	for(int i=0; i<N; i++){
		if(R_index > Strs[i].length() || *(Strs[i].end() - R_index - 1) != aim ){
		//	cout<<*(Strs[i].end() - R_index)<<endl;
			return false;
		}
	}
	return true;
}

void Process(vector<string> &Strs){
	int N = Strs.size();
	int R_index = 0;
	while(Is_Find( Strs, *(Strs[0].end() - R_index - 1), R_index)){  //将第一句从末尾字母开始与其他句末尾比较，看看是否所有句子 
		R_index++;												     //相对倒数位置是否都一致 
	}
	if(R_index == 0){
		cout<<"nai"<<endl;
		return;
	}
	for(int i=Strs[0].length() - R_index ; i < Strs[0].length(); i++)
		cout<<Strs[0][i];
	cout<<endl;
}

int main(){
	vector<string> Strs;
	int N;
	cin>>N;
	Strs.resize(N);
	getchar();
	for(int i=0; i<N; i++){
		getline(cin,Strs[i]);
	}
	//cout<<*(Strs[0].end()-i);  获取倒数第i个字符
	Process(Strs);
 
}
