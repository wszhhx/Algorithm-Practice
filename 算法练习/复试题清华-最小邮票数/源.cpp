#include<iostream>
#define INF 65535
using namespace std;

int Generator(int stamps[],int M, int N) {
	int values[100];
	for (int i = 0; i <= M; ++i) {   //��ʼ����̬�滮�飬���ܼ���Ϊ����
		if (i == 0)
			values[i] = 0;
		else
			values[i] = INF;
	}
	for (int i = 0; i < N; ++i) {
		for (int j = M; j >= stamps[i]; --j) {
			if (values[j - stamps[i]] != INF) {   //����ܼ�Ϊj��ʱ��ȥ����ǰ�����Ʊ����ܼ�����Ʊ��ʽ
				if (values[j] > values[j - stamps[i]] + 1)    //�ڵ�ǰ������Ʊ����ʹ�õ�ǰ�����Ʊ����Ʊ��ʽ��˭������ѡ˭
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