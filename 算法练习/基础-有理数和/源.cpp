#include<iostream>
#include<cstdlib>
using namespace std;

int gcd(int a, int b) {
	int t;
	while (a % b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	return b;
}

int gbs(int a, int b) {
	if (a < b) {
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	int temp = a;
	while (a % b != 0) {
		a += temp;
	}
	return a;
}

int main() {
	int a1, b1, a2, b2;
	scanf_s("%d/%d %d/%d", &a1, &b1, &a2, &b2);
	int fm = gbs(b1, b2);
	int fz = a1 * (fm / b1) + a2 * (fm / b2);
	int gys = gcd(fm, fz);
	if (fz % fm == 0) {
		cout << fz / fm << endl;
	}
	else
		cout << fz / gys << '/' << fm / gys << endl;
	return 0;
}