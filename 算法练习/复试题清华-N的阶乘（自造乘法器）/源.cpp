#include<iostream>
#define MAXSIZE 30000
using namespace std;

int main() {
	int array[MAXSIZE];                               //存储结果，一个元素代表一个位数
	int Rem, Total;                                   //Rem为余数，Total为临时总数
	int Index = MAXSIZE - 1;                          //结果数组的标记
	int N;                                            //N的阶乘
	while (cin >> N) {
		for (int i = 0; i < MAXSIZE; ++i)
			array[i] = 0;
		array[MAXSIZE - 1] = 1;
		Rem = Total = 0;
		for (int i = 2; i <= N; ++i) {
			while (Index > 0 || Rem != 0 || array[Index] != 0) {                       //每一位都需要乘以当前因数
				Total = array[Index] * i + Rem;       //记录没位数乘以某因数后结果是否需要进位
				Rem = 0;
				if (Total > 9) {                      //若需要进位
					array[Index] = Total % 10;
					Rem = Total / 10;
				}
				else {
					array[Index] = Total;
				}
				Index--;
			}
			Rem = 0;
			Total = 0;
			Index = MAXSIZE - 1;
		}
		bool Flag = false;
		for (int i = 0; i < MAXSIZE; ++i) {             //取第一位不为0的数开始输出
			if (array[i] != 0)
				Flag = true;
			if (Flag)
				cout << array[i];
		}
		cout << endl;
	}
	return 0;
}