/*
��Ŀ������
  ��������ǧ���򻯵Ľ���������������������һ���˵�ϰ�߽����ﳣ����ӳ������˵ĸ��ԣ�������ϰ�߳�Ϊ��Kuchigues��������ϰ�����ձ�����
�������л���������Կ��ţ��ٸ����ӣ���"nyan~"��Ϊ��β�ľ��ӳ�������˵������ӵ����Ǹ���è�ء�
���ۣ�nyan~
���������ߣ�nyan~
���ڸ��㼸��ĳ������˵�ľ��ӣ����ܷ���������β����ɶ��

����������
  ÿ���������һ������������ÿ����������һ�и���һ��������N   ��2<=N<=100��
��������N��ÿ����һ���ַ�����0~256�ľ��ӣ�ÿ�仰����ĳ���Ը������˵�Ļ����Ҵ�Сд���С�

���������
  ����ÿ���������������������˵�β�����������о��ӹ��еģ�����Ǹ�β׺������Ҳ������������nai��
  
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
	while(Is_Find( Strs, *(Strs[0].end() - R_index - 1), R_index)){  //����һ���ĩβ��ĸ��ʼ��������ĩβ�Ƚϣ������Ƿ����о��� 
		R_index++;												     //��Ե���λ���Ƿ�һ�� 
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
	//cout<<*(Strs[0].end()-i);  ��ȡ������i���ַ�
	Process(Strs);
 
}
