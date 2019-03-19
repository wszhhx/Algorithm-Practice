/*
˼·�����ַ����洢���룬Ȼ��ָ��ַ������۰룩����ת��Ϊ���֣�����ж��Ƿ�������
���䣺�����ͷָ���죬a = z/(10^(z.size/2))  b = z % (10^(z.size/2))

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