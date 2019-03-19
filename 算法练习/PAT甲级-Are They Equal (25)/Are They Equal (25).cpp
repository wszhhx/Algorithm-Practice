/*
题目描述：如果一台机器仅能保存三个有效数字，那么浮点数12300与12358.9被视为相同的数字，因为他们都被视为0.123*10^5简单去位保存
         。现在给你某台机器的能保存的有效数字的位数与2个浮点数，你要	求出该机器是否视这两个数为相同的数字。

输入描述：每个输入包含一个测试用例，每个用例给出三个数字：N/A/B，其中N为有效数字的位数(N<100),A和B为两个需要比较的浮点数,每个
         浮点数保证不为负数，小于10100，且总位数小于100。

输出描述：对于每个测试用例，若两个数字视为相同数，则输出"YES"且以"0.d1 d2 d3 ... dN*10^k"的格式输出两个数的同一格式（除非数字为0，否则d1≠0）
         若两个数字视为不同数，则输出"NO"且以同上格式输出各自的标准格式。两者用空格隔开，且末尾没有多余空格
		 PS：简单的舍位是不用四舍五入的

思路：先将两个浮点数转化为字符串，根据小数点位置计算整数部分的阶，再根据有效数字处理字符串，留下去位后的数字，比较是否相同，再把格式标准化，输出
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
	if (f_str.find('.') == -1) {                                              //若该数为整数
		if (f_str.find_first_not_of('0') == -1) {   //针对全为0的情况
			f_str = "0.";
			return 0;
		}
		f_str.erase(0, f_str.find_first_not_of('0'));      //针对00000xxxxxx的情况
		rank = f_str.size();
		f_str.insert(0,"0.");                                           //化为规格数
		return rank;
	} 
	else {                                                              //若该数为浮点数
		f_str.erase(0, f_str.find_first_not_of('0'));                 //针对00000.xxxxx或是000xxx.xxxx的情况
		if (f_str[0] == '.')
			f_str.insert(0, "0");
		if (f_str[0] == '0') {                                            //若该数小于1
			int fnum_index;
			f_str[1] = '0';
			fnum_index = f_str.find_first_not_of('0');                 //找到第一个非0数所在位置
			if (fnum_index == -1) {
				f_str = "0";
				return 0;
			}
			rank = -(fnum_index - 2); 
			f_str.erase(0, fnum_index);    //把第一个非0数作为第一位
			f_str.insert(0, "0.");                                     //化为规格数
			return rank;
		}
		else {                                                           //若该数大于1
			int num_num = f_str.find('.');
			rank = num_num;
			f_str.erase(f_str.find('.'), 1);                            //去掉小数点
			f_str.insert(0, "0.");                                      //化为规格数
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
	f1_str.insert(f1_str.size(), string(150 - f1_str.size(), '0'));   //重点语句，填充至100个字符，防止后面去位导致溢出，如：
	f2_str.insert(f2_str.size(), string(150 - f2_str.size(), '0'));   //0.12精度为5则在erase函数里发生下标上溢出
	
	f1_str.erase(2 + N);                         //砍掉低位
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