/*
算法描述：这个任务很简单：向某哈希表内插入互不相同的正整数序列，并输出某整数在哈希表中的位置，本题的哈希函数定义为
         " H(key) = key % TSize:" ,TSize为哈希表的最大容量，处理冲突使用二次探测法（只用正数增量）。
		 要注意哈希表容量要为素数，如果给出的容量不为素数，则需要取给大于所给数的最小素数（如8->11）。

输入描述：每次输入包含一个例子，对于每个例子：第一行包含两个正整数：MSize(<= 10^4) 和 N(<=MSize)前者为用户定义的
         哈希表容量，后者为需要进入哈希表的元素个数。在接下来的一行给出N个不同正整数，每个整数用空格隔开。

输出描述：对于每个测试用例，在一行中输出其对应的在哈希表中的位置（下标从0开始）且在行末不能有多余空格，无法插入的数
         字用‘-’代替

4 4
10 6 4 15

0 1 4 -

*/
#include<iostream>
#include<cstdlib>
#define MAXSIZE 10001
using namespace std;

bool IsPrime[(MAXSIZE - 1) / 2 + 1];
bool HashTable[MAXSIZE];
int Sequence[MAXSIZE];
int MSize;

inline int trans_index(int a) {
	return (a - 1) / 2;
}

void GeneratePrime() {  //产生10000以内的素数用奇数数组替代全数数组
	memset(IsPrime, true, sizeof(IsPrime));
	for (int i = 1; i <= (MAXSIZE - 1) / 2; ++i) {
		if (IsPrime[i]) {
			for (int j = (i * 2 + 1) * 2; j <= MAXSIZE; j += i * 2 + 1) {
				if (j % 2 == 1) {
					IsPrime[trans_index(j)] = false;
				}
			}
		}
	}
	return;
}

int main() {
	GeneratePrime();
	memset(HashTable, false, sizeof(HashTable));
	int N;
	int index;
	int j;
	cin >> MSize >> N;
	if (MSize == 1)
		MSize = 3;
	if (MSize % 2 == 0) {
		MSize++;
	}
	while (!IsPrime[trans_index(MSize)]) {
		MSize += 2;
	}
	for (int i = 0; i < N; ++i) {
		cin >> Sequence[i];
	}

	for (int i = 0; i < N; ++i) {
		for (j = 0; j < MSize; ++j) {
			if (HashTable[(Sequence[i] + j*j) % MSize] == false) {
				cout << (Sequence[i] + j*j) % MSize << ( i < N-1 ? " " : "\n");
				HashTable[(Sequence[i] + j*j) % MSize] = true;
				break;
			}
		}
		if (j == MSize)
			cout << '-' << (i < N-1 ? " " : "\n");
	}
	system("pause");
	return 0;
}