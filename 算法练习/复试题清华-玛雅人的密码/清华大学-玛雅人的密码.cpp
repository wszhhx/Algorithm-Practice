#include<iostream>
#include<queue>
#include<map>
#include<string>

using namespace std;
char Aim[] = "2012";
typedef struct str_cos{
	string str;                             //包含的字符串
	int deep;								//标示该串做了几次字符交换
	str_cos(string str,int deep) {
		this->deep = deep;
		this->str = str;
	}
}STR;

bool SubString(string S){  //判断某个字符串是否包含子串"2012"
	int p = 0;
	int q = 0;
	while(p < S.size()){
		if(S[p] == Aim[q]){
			q++;
		}
		else{
			q = 0;			
		}
		p++;
		if(q == 4)
			return true;
	}
	return false;
}

int MoveCounter(STR str){
	queue<STR> Q;
	map<string, int> MAP;          //用来区分该串是否之前已经生成过
	char T;
	int Length = str.str.size();
	string S_temp;
	Q.push(str);                   //原始串入队，为接下来的广度遍历做准备
	MAP[str.str] = 1;              //标示原始串已经访问过，1是看心情给的
	while (!Q.empty()) {
		STR F_temp = Q.front();    
		Q.pop();
		if (SubString(F_temp.str))                               //若该串满足题目要求，则输出深度（字符交换次数）
			return F_temp.deep;
		for (int i = 0; i < str.str.size() - 1; ++i) {           //该循环是用来把当前串的所有可能的相邻交换（一次）列出来
			S_temp = F_temp.str;
			T = S_temp[i];
			S_temp[i] = S_temp[i + 1];
			S_temp[i + 1] = T;
			if (MAP.find(S_temp) == MAP.end()) {                 //若该交换后的新串先前木有出现过，则标示已访问，并入队。
				MAP[S_temp] = 1;
				Q.push(str_cos(S_temp, F_temp.deep + 1));
			}
		}
	}
	return -1;
	
}

int main(){
	string S;
	int N;
	while(scanf("%d",&N) != EOF){   //这个N你可以看心情给！
		cin>>S;
		printf("%d\n",MoveCounter(str_cos(S,0)));
	}
	return 0;
}
