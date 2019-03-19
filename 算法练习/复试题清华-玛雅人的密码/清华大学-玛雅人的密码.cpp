#include<iostream>
#include<queue>
#include<map>
#include<string>

using namespace std;
char Aim[] = "2012";
typedef struct str_cos{
	string str;                             //�������ַ���
	int deep;								//��ʾ�ô����˼����ַ�����
	str_cos(string str,int deep) {
		this->deep = deep;
		this->str = str;
	}
}STR;

bool SubString(string S){  //�ж�ĳ���ַ����Ƿ�����Ӵ�"2012"
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
	map<string, int> MAP;          //�������ָô��Ƿ�֮ǰ�Ѿ����ɹ�
	char T;
	int Length = str.str.size();
	string S_temp;
	Q.push(str);                   //ԭʼ����ӣ�Ϊ�������Ĺ�ȱ�����׼��
	MAP[str.str] = 1;              //��ʾԭʼ���Ѿ����ʹ���1�ǿ��������
	while (!Q.empty()) {
		STR F_temp = Q.front();    
		Q.pop();
		if (SubString(F_temp.str))                               //���ô�������ĿҪ���������ȣ��ַ�����������
			return F_temp.deep;
		for (int i = 0; i < str.str.size() - 1; ++i) {           //��ѭ���������ѵ�ǰ�������п��ܵ����ڽ�����һ�Σ��г���
			S_temp = F_temp.str;
			T = S_temp[i];
			S_temp[i] = S_temp[i + 1];
			S_temp[i + 1] = T;
			if (MAP.find(S_temp) == MAP.end()) {                 //���ý�������´���ǰľ�г��ֹ������ʾ�ѷ��ʣ�����ӡ�
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
	while(scanf("%d",&N) != EOF){   //���N����Կ��������
		cin>>S;
		printf("%d\n",MoveCounter(str_cos(S,0)));
	}
	return 0;
}
