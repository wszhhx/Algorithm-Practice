/*
在输入棋子的过程中就标记那些行、列、主对角、副对角被棋子占用，之后的输入若有棋子重复则判断该解不成立
*****主对角可以通过横坐标加纵坐标的结果来区别，副对角可以通过横坐标减去纵坐标来指明（用数组存储对角线信息，所以要加N）
PS:MD，去年复试我就是没往这儿想，MMP。。。。这题0分
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

