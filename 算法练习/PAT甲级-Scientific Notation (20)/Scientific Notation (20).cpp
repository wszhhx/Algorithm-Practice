/*��ѧ������
��Ŀ��������ѧ�������ǿ�ѧ�������׵ش���������С�����ķ�ʽ����ʾ����������ʽƥ��[+-][1-9]"."[0-9]+E[+-][0-9]������ζ����������ֻ��һλ��
         С������������һλ���֣�������ָ��������������Ҫ��ʾ����ʹΪ����
		 ���ڣ��ÿ�ѧ����������һ����ʵ������A,����Ҫ�ô�ͳ��ʽ���������ͬʱҪ����������Ч���֡�

����������ÿ���������һ�����ӣ�ÿ�����Ӱ���һ�п�ѧ���������ʽ��ÿ�������ַ�������С��9999�ֽ���ָ�����־���ֵ������9999

�������������ÿ�����ӣ���һ�����ô�ͳ�����������A������������Ч����,����ĩβ��0.

ex:���룺+1.23400E-03
   �����0.00123400
 */

#include<iostream>
#include<string.h>
#include<string>
#include<cstdlib>
using namespace std;
#define MAXLENGTH 10000

int main() {
	string A;
	char _A[MAXLENGTH];
	int exponent;
	int point_index;
	cin >> A;
	bool sign = (A[0] == '+' ? true : false);
	point_index = A.find('.');
	sscanf_s(A.substr(A.find('E') + 1).c_str(), "%d", &exponent);  //��ȡָ�����ֲ�������exponent��
	A = A.substr(1, A.find('E')-1);                                //��ָ���ͷ��Ź��˵�.+1.23400E-03 -> 1.23400
	A.erase(A.find('.'), 1);                                       //��С������˵� 1.23400 -> 123400
	if (point_index - 1 + exponent <= 0) {                         //������λ��������0
		A.insert(0, "0." + string(-(point_index - 1 + exponent), '0'));  
	}
	else if (point_index - 1 + exponent > A.size()) {   //������λ��������0
		A = A + string(point_index - 1 + exponent - A.size(),'0');
	}
	else if(point_index - 1 + exponent == A.size()){
		A = A;
	}
	else {
		A.insert(point_index - 1 + exponent, 1, '.');
	}
	bool flag = true;
	while (flag) {                    //ɾȥ��߶����0
		if (A[0] == '0')
			A.erase(0, 1);
		else
			flag = false;
	}
	if (A[0] == '.')                   
		A.insert(0, 1, '0');
	cout << (sign ? "" : "-") << A;
	system("pause");
	return 0;
}