#include<iostream>
#include<string>
#include<algorithm>

int gcd(int a, int b) {
	int t;
	while (a % b != 0) {
		t = b;
		b = a % b;
		a = t;
	}
	return b;
}

using namespace std;


int main() {
	int a, b;
	scanf_s("%d/%d", &a, &b);
	int temp = gcd(a, b);
	printf("%d/%d\n", a / temp, b / temp);
	

	system("pause");
}