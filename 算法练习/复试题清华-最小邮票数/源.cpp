#include<iostream>
#define INF 65535
using namespace std;

int Generator(int stamps[],int M, int N) {
	int values[100];
	for (int i = 0; i <= M; ++i) {   //初始化动态规划组，以总价作为索引
		if (i == 0)
			values[i] = 0;
		else
			values[i] = INF;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = M; j >= stamps[i]; --j) {
			if (values[j - stamps[i]] != INF) {   //如果总价为j的时候去掉当前检测邮票后的总价有配票方式
				if (values[j] > values[j - stamps[i]] + 1)    //在当前可配邮票数与使用当前检测邮票来配票方式数谁者最少选谁
					values[j] = values[j - stamps[i]] + 1;
			}
		}
	}
	if (values[M] == INF)
		return 0;
	else
		return values[M];
}

int main() {
	int N;
	int stamps[20];
	int M;
	while (cin >> M >> N) {
		for (int i = 0; i < N; ++i)
			cin >> stamps[i];
		cout << Generator(stamps,M, N);
	}
}