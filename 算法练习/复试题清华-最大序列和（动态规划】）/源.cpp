#include<iostream>
#define INF -65535
using namespace std;
int main() {
	long long sum, temp_sum, unit;
	int N;
	while (cin >> N) {
		sum = INF;
		temp_sum = 0;
		for (int i = 0; i < N; ++i) {
			if (temp_sum < 0)
				temp_sum = 0;
			cin >> unit;
			temp_sum += unit;
			if (sum < temp_sum)
				sum = temp_sum;
		}
		cout << sum << endl;
	}
	return 0;
}