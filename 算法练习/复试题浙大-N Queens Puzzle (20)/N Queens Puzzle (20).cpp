/*
���������ӵĹ����оͱ����Щ�С��С����Խǡ����ԽǱ�����ռ�ã�֮����������������ظ����жϸýⲻ����
*****���Խǿ���ͨ���������������Ľ�������𣬸��Խǿ���ͨ���������ȥ��������ָ����������洢�Խ�����Ϣ������Ҫ��N��
PS:MD��ȥ�긴���Ҿ���û������룬MMP������������0��
*/


#include<iostream>
#include<cstdlib>
using namespace std;
#define MAXN 1000

bool Cb_flag[4][MAXN*2];

int main() {
	bool flag;
	int x, y;
	int N;
	int M;
	cin >> N;
	for (int j = 0; j < N; ++j) {
		flag = true;
		memset(Cb_flag, false, sizeof(bool) * 4 * MAXN * 2);
		cin >> M;
		for (int i = 0; i < M; ++i) {
			x = i;
			cin >> y;
			if (Cb_flag[0][y] == false)
				Cb_flag[0][y] = true;
			else
				flag = false;
			if (Cb_flag[1][x] == false)
				Cb_flag[1][x] = true;
			else
				flag = false;
			if (Cb_flag[2][x + y] == false)
				Cb_flag[2][x + y] = true;
			else
				flag = false;
			if (Cb_flag[3][x - y + MAXN] == false)
				Cb_flag[3][x - y + MAXN] = true;
			else
				flag = false;
		}
		if (!flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}

