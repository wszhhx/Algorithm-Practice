#include<iostream>
using namespace std;

int Charge(int n) {
	int sum = 0;
	for (int i = 1; i < n; ++i) {
		if (n%i == 0)
			sum += i;
	}
	if (sum == n)
		return 1;
	else if (sum > n)
		return 2;
	else
		return 0;
}

int main() {
	int flag[61];
	for (int i = 2; i <= 60; ++i)
		flag[i] = Charge(i);
	cout << "E:";
	for (int i = 2; i <= 60; ++i)
		if (flag[i] == 1)
			cout << ' ' << i;
	cout << endl;
	cout << "G:";
	for (int i = 2; i <= 60; ++i)
		if (flag[i] == 2)
			cout << ' ' << i;
	int n;
	cin >> n;
	return 0;

}