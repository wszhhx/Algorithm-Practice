#include<iostream>
#include<conio.h>
using namespace std;

int price[101] = { -1,1,5,8,9,10,17,17,20,24,30 };
int result[101];
int part[101];
int count = 0;

int cut_rod_dg(int n) {	//原始递归方法
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

int cut_rod_mem(int n) {	//带记忆的自顶向下递归
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

int cut_rod_bottom_up(int n) {	//自底向上的算法
	result[0] = 0;
	int q, temp;
	for (int i = 1; i <= 100; ++i) {
		q = -1;
		for (int j = 1; j <= i; ++j) {			//因为是自底向上，所以已经求得的result[i]已经是最优解
			temp = price[j] + result[i - j];
			q = q < temp ? temp : q;
			part[i] = j;	//记录最优解的第一段长度
			
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