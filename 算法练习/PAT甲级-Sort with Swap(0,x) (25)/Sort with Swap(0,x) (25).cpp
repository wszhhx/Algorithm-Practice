/*
题目描述：给出任意一个数字序列｛0，1，2，...，N-1｝，很方便得能将他们增序排序，但是如果只允许做交换{0,x}操作呢？
         你需要找到排好一个序列前N个非负整数所需的最小swap{0,x}操作次数。

输入描述：每次输入包含一个用例，先输入一个正整数N（N<=10^5）接下来跟着一串有N个数字的序列{0,1,...,N-1}一行中所有数据用空格隔开
输出描述：输出需要作的交换的最小次数。
思路：当0不在自己位置上时交换0所在的位置本来应该在的数字，若0在自己位置上则交换一个不在自己位置的数字（为了计算方便，这里用最小的不在自己原本位置的数）
      这样得出的交换次数一定是最小的（贪心算法）
PS：位运算和数组嵌套一起用的话会出错！如：Addr[Addr[0]] ^= Addr[0] ^= Addr[Addr[0]] ^= Addr[0];得出的答案不是交换Addr[Addr[0]]与Addr[0]
*/
#include<iostream>
#define MAXSIZE 100010
using namespace std;

int Addr[MAXSIZE];                          //Addr[i]代表数字i的下标


int main() {
	int N;
	int left = 0;                           //剩余未归位数字
	int min_wrong = -1;                     //最小未归位数字
	int temp;
	int swap_count;
	while (cin >> N) {
		left = 0;
		swap_count = 0;
		min_wrong = -1;
		for (int i = 0; i < N; ++i) {
			cin >> temp;
			Addr[temp] = i;
		}
		for (int i = 1; i < N; ++i) {
			if (Addr[i] != i) {
				if (min_wrong == -1)
					min_wrong = i;
				left++;
			}
		}
		while (left > 0) {
			if (Addr[0] == 0) {
				swap_count++;
				Addr[min_wrong] ^= Addr[0] ^= Addr[min_wrong] ^= Addr[0];
				for (min_wrong += 1; min_wrong < N && Addr[min_wrong] == min_wrong; ++min_wrong);  //重新计算最小未归位数字
			}
			if (Addr[0] == min_wrong)
				for (min_wrong += 1; min_wrong < N && Addr[min_wrong] == min_wrong; ++min_wrong);
			temp = Addr[0];                                    //嵌套加位运算会出错！"Addr[ Addr[0] ] ^= Addr[0] ^= Addr[ Addr[0] ] ^= Addr[0]"
			Addr[0] ^= Addr[temp] ^= Addr[0] ^= Addr[temp];    //交换0和0所占有的位置本来的主人
			left--;
			swap_count++;
		}
		cout << swap_count << endl;
	}
	return 0;
}