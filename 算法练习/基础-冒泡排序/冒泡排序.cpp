#include<iostream>
using namespace std;

int main() {
	int N, K;
	int array[1000];
	int temp;
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> array[i];
	}
	for (int i = 0; i < K; ++i) {
		for (int j = 1; j < N - i; ++j) {
			if (array[j] < array[j - 1]) {
				array[j - 1] = array[j - 1] ^ array[j];
				array[j] = array[j - 1] ^ array[j];
				array[j - 1] = array[j - 1] ^ array[j];
			}
			
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << array[i] << (i + 1 == N ? '\n' : ' ');
	}
	system("pause");

}