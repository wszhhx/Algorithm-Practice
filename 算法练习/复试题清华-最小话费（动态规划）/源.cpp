#include<iostream>
using namespace std;
int main() {
	int N, A, B;
	long long Distance[10000];
	long long Dp[10000];
	long long L1, L2, L3, C1, C2, C3;
	long long temp_length;
	long long temp_cost;
	while (cin >> L1 >> L2 >> L3 >> C1 >> C2 >> C3) {
		cin >> A >> B >> N;
		Distance[1] = 0;
		for (int i = 2; i <= N; ++i)
			cin >> Distance[i];
		if (A == B) {
			cout << '0' << endl;
			continue;
		}
		if (A > B) {
			int temp = A;
			A = B;
			B = temp;
		}

		for (int i = A; i <= B; ++i)
			Dp[i] = -1;
		Dp[A] = 0;
		for (int i = A; i <= B; ++i) {
			for (int j = i + 1; j <= B; ++j) {
				temp_length = Distance[j] - Distance[i];
				if (temp_length > L3)							break;
				else if (L2 < temp_length && temp_length <= L3)	temp_cost = C3;
				else if (L1 < temp_length && temp_length <= L2)	temp_cost = C2;
				else											temp_cost = C1;
				if (Dp[j] == -1 || Dp[i] + temp_cost < Dp[j])	Dp[j] = Dp[i] + temp_cost;
			}
		}
		cout << Dp[B] << endl;
	}
	return 0;
}