#include<iostream>
#include<conio.h>
using namespace std;

int price[101] = { -1,1,5,8,9,10,17,17,20,24,30 };
int result[101];
int part[101];
int count = 0;

int cut_rod_dg(int n) {	//ԭʼ�ݹ鷽��
	if (n == 0)
		return 0;

	int q = -1;
	int temp;
	for (int i = 1; i <= n; ++i) {
		temp = price[i] + cut_rod_dg(n - i);
		q = q < temp ? temp : q;

	}
	return q;
}

int cut_rod_mem(int n) {	//��������Զ����µݹ�
	if (n == 0)
		return 0;
	if (result[n] >= 0)
		return result[n];
	int q = -1;
	int temp;
	for (int i = 1; i <= n; ++i) {
		temp = price[i] + cut_rod_mem(n - i);
		q = q < temp ? temp : q;
	}
	result[n] = q;
	return q;
}

int cut_rod_bottom_up(int n) {	//�Ե����ϵ��㷨
	result[0] = 0;
	int q, temp;
	for (int i = 1; i <= 100; ++i) {
		q = -1;
		for (int j = 1; j <= i; ++j) {			//��Ϊ���Ե����ϣ������Ѿ���õ�result[i]�Ѿ������Ž�
			temp = price[j] + result[i - j];
			q = q < temp ? temp : q;
			part[i] = j;	//��¼���Ž�ĵ�һ�γ���
			
		}
		result[i] = q;
	}
	return result[n];
}

int main() {
	int n;
	memset(result, -1, 100 * sizeof(int));
	cin >> n;

	cout << endl;
	cout << cut_rod_bottom_up(n) << endl;
	

	system("pause");
	return 0;
}