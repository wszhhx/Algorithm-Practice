#include<iostream>

using namespace std;
int main() {
	int a1, a2, p, q, k,temp;
	while (cin >> a1 >> a2 >> p >> q >> k) {
		if (k == 0)
			cout << a1 % 10000;
		else if (k == 1)
			cout << a2 % 10000;
		else {
			for (int i = 2; i <= k; ++i) {
				temp = (p*a2 + q*a1)%10000;
				a1 = a2;
				a2 = temp;
			}
			cout << temp;
		}
		cout << endl;
	}
	return 0;
}