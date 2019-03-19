/*
思路：用字符串存储输入，然后分割字符串（折半），再转化为数字，最后判断是否能整除
补充：用整型分割更快，a = z/(10^(z.size/2))  b = z % (10^(z.size/2))

*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main() {
	int N;
	int z, a, b;
	int zsize;
	int temp;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> z;
		zsize = 0;
		temp = z;
		while (temp != 0) {
			zsize++;
			temp /= 10;
		}
		
		a = z / pow(10, zsize / 2);
		b = z % (int)pow(10, zsize / 2);
		if (a == 0 || b == 0) {
			if (z == 0)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
			continue;
		}
		if (z % (a*b) == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}