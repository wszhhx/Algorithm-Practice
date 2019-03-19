#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;
#define MAXL 10001

int road[MAXL];
int length;

void SubstractSet(int l,int r) {
	for (int i = l; i <= r; ++i) {
		if (road[i] == 0) {
			length--;
			road[i] = 1;
		}
	}
}

int main() {
	int L, M;
	int l, r;
	while (cin >> L >> M) {
		memset(road, 0, sizeof(road));
		length = L + 1;
		for (int i = 0; i < M; ++i) {
			cin >> l >> r;
			SubstractSet(l, r);
		}
		cout << length;
	}
	return 0;
}