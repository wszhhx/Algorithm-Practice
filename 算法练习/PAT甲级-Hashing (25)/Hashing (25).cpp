/*
�㷨�������������ܼ򵥣���ĳ��ϣ���ڲ��뻥����ͬ�����������У������ĳ�����ڹ�ϣ���е�λ�ã�����Ĺ�ϣ��������Ϊ
         " H(key) = key % TSize:" ,TSizeΪ��ϣ�����������������ͻʹ�ö���̽�ⷨ��ֻ��������������
		 Ҫע���ϣ������ҪΪ���������������������Ϊ����������Ҫȡ����������������С��������8->11����

����������ÿ���������һ�����ӣ�����ÿ�����ӣ���һ�а���������������MSize(<= 10^4) �� N(<=MSize)ǰ��Ϊ�û������
         ��ϣ������������Ϊ��Ҫ�����ϣ���Ԫ�ظ������ڽ�������һ�и���N����ͬ��������ÿ�������ÿո������

�������������ÿ��������������һ����������Ӧ���ڹ�ϣ���е�λ�ã��±��0��ʼ��������ĩ�����ж���ո��޷��������
         ���á�-������

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

void GeneratePrime() {  //����10000���ڵ������������������ȫ������
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