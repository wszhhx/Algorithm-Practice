/*科学计数法
题目描述：科学计数法是科学家能容易地处理大数或很小的数的方式。表示法与正则表达式匹配[+-][1-9]"."[0-9]+E[+-][0-9]，它意味着整数部分只有一位数
         小数部分至少有一位数字，底数与指数的正负符号总要显示，即使为正。
		 现在，用科学计数法给出一个真实的数字A,你需要用传统方式输出该数，同时要保留所有有效数字。

输入描述：每个输入包含一个例子，每个例子包括一行科学计数法表达式，每个输入字符串长度小于9999字节且指数部分绝对值不超过9999

输出描述：对于每个例子，在一行内用传统计数法输出数A，保留所有有效数字,包括末尾的0.

ex:输入：+1.23400E-03
   输出：0.00123400
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
	sscanf_s(A.substr(A.find('E') + 1).c_str(), "%d", &exponent);  //截取指数部分并保存在exponent中
	A = A.substr(1, A.find('E')-1);                                //把指数和符号过滤掉.+1.23400E-03 -> 1.23400
	A.erase(A.find('.'), 1);                                       //把小数点过滤掉 1.23400 -> 123400
	if (point_index - 1 + exponent <= 0) {                         //考虑左位不够，增0
		A.insert(0, "0." + string(-(point_index - 1 + exponent), '0'));  
	}
	else if (point_index - 1 + exponent > A.size()) {   //考虑右位不够，增0
		A = A + string(point_index - 1 + exponent - A.size(),'0');
	}
	else if(point_index - 1 + exponent == A.size()){
		A = A;
	}
	else {
		A.insert(point_index - 1 + exponent, 1, '.');
	}
	bool flag = true;
	while (flag) {                    //删去左边多余的0
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