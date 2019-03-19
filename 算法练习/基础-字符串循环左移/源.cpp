#include<iostream>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;

int main() {
	char str_array[100][10];
	char temp[10];
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> str_array[i];
	}
	for (int i = 0; i < K; ++i) {
		for (int j = 1; j < N - i; ++j) {
			if (strcmp(str_array[j - 1], str_array[j]) > 0) {
				strcpy(temp, str_array[j - 1]);
				strcpy(str_array[j - 1], str_array[j]);
				strcpy(str_array[j], temp);
			}
		}
	}
	for (int i = 0; i < N - 1; ++i) {
		cout << str_array[i] << endl;
	}
	cout << str_array[N - 1];
}