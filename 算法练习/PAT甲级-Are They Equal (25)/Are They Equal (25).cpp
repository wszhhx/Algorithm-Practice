/*
��Ŀ���������һ̨�������ܱ���������Ч���֣���ô������12300��12358.9����Ϊ��ͬ�����֣���Ϊ���Ƕ�����Ϊ0.123*10^5��ȥλ����
         �����ڸ���ĳ̨�������ܱ������Ч���ֵ�λ����2������������Ҫ	����û����Ƿ�����������Ϊ��ͬ�����֡�

����������ÿ���������һ������������ÿ�����������������֣�N/A/B������NΪ��Ч���ֵ�λ��(N<100),A��BΪ������Ҫ�Ƚϵĸ�����,ÿ��
         ��������֤��Ϊ������С��10100������λ��С��100��

�������������ÿ������������������������Ϊ��ͬ���������"YES"����"0.d1 d2 d3 ... dN*10^k"�ĸ�ʽ�����������ͬһ��ʽ����������Ϊ0������d1��0��
         ������������Ϊ��ͬ���������"NO"����ͬ�ϸ�ʽ������Եı�׼��ʽ�������ÿո��������ĩβû�ж���ո�
		 PS���򵥵���λ�ǲ������������

˼·���Ƚ�����������ת��Ϊ�ַ���������С����λ�ü����������ֵĽף��ٸ�����Ч���ִ����ַ���������ȥλ������֣��Ƚ��Ƿ���ͬ���ٰѸ�ʽ��׼�������
*/

#include<iostream>
#include<string>
#include<cstdlib>
#include<cmath>
#define MAXSIZE 100
using namespace std;

int CalRank(string &f_str) {
	if (f_str == "0")
		return 0;
	int rank;
	int dot_index = f_str.find('.');
	if (f_str.find('.') == -1) {                                              //������Ϊ����
		if (f_str.find_first_not_of('0') == -1) {   //���ȫΪ0�����
			f_str = "0.";
			return 0;
		}
		f_str.erase(0, f_str.find_first_not_of('0'));      //���00000xxxxxx�����
		rank = f_str.size();
		f_str.insert(0,"0.");                                           //��Ϊ�����
		return rank;
	} 
	else {                                                              //������Ϊ������
		f_str.erase(0, f_str.find_first_not_of('0'));                 //���00000.xxxxx����000xxx.xxxx�����
		if (f_str[0] == '.')
			f_str.insert(0, "0");
		if (f_str[0] == '0') {                                            //������С��1
			int fnum_index;
			f_str[1] = '0';
			fnum_index = f_str.find_first_not_of('0');                 //�ҵ���һ����0������λ��
			if (fnum_index == -1) {
				f_str = "0";
				return 0;
			}
			rank = -(fnum_index - 2); 
			f_str.erase(0, fnum_index);    //�ѵ�һ����0����Ϊ��һλ
			f_str.insert(0, "0.");                                     //��Ϊ�����
			return rank;
		}
		else {                                                           //����������1
			int num_num = f_str.find('.');
			rank = num_num;
			f_str.erase(f_str.find('.'), 1);                            //ȥ��С����
			f_str.insert(0, "0.");                                      //��Ϊ�����
			return rank;
		}
	}
}

void OutPut(string f_str,int rank) {
	if (f_str.find_first_not_of('0') == -1) {
		f_str[1] = '.';
	}
	cout << f_str << "*10^" << rank;
	return;
}

int main() {
	int N;
	int f1_rank = 0;
	int f2_rank = 0;
	string f1_str, f2_str;
	cin >> N >> f1_str >> f2_str;
	f1_rank = CalRank(f1_str);
	f2_rank = CalRank(f2_str);
	f1_str.insert(f1_str.size(), string(150 - f1_str.size(), '0'));   //�ص���䣬�����100���ַ�����ֹ����ȥλ����������磺
	f2_str.insert(f2_str.size(), string(150 - f2_str.size(), '0'));   //0.12����Ϊ5����erase�����﷢���±������
	
	f1_str.erase(2 + N);                         //������λ
	f2_str.erase(2 + N);
	if (f1_rank != f2_rank) {
		cout << "NO ";
		OutPut(f1_str,f1_rank);
		cout << ' ';
		OutPut(f2_str,f2_rank);
		cout << endl;
	}
	else {
		if (f1_str == f2_str) {
			cout << "YES ";
			OutPut(f1_str, f1_rank);
			cout << endl;
		}
		else {
			cout << "NO ";
			OutPut(f1_str, f1_rank);
			cout << ' ';
			OutPut(f2_str, f2_rank);
			cout << endl;
		}
	}
	system("pause");
	return 0;

}