#include<iostream>
#define MAXSIZE 30000
using namespace std;

int main() {
	int array[MAXSIZE];                               //�洢�����һ��Ԫ�ش���һ��λ��
	int Rem, Total;                                   //RemΪ������TotalΪ��ʱ����
	int Index = MAXSIZE - 1;                          //�������ı��
	int N;                                            //N�Ľ׳�
	while (cin >> N) {
		for (int i = 0; i < MAXSIZE; ++i)
			array[i] = 0;
		array[MAXSIZE - 1] = 1;
		Rem = Total = 0;
		for (int i = 2; i <= N; ++i) {
			while (Index > 0 || Rem != 0 || array[Index] != 0) {                       //ÿһλ����Ҫ���Ե�ǰ����
				Total = array[Index] * i + Rem;       //��¼ûλ������ĳ���������Ƿ���Ҫ��λ
				Rem = 0;
				if (Total > 9) {                      //����Ҫ��λ
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
		for (int i = 0; i < MAXSIZE; ++i) {             //ȡ��һλ��Ϊ0������ʼ���
			if (array[i] != 0)
				Flag = true;
			if (Flag)
				cout << array[i];
		}
		cout << endl;
	}
	return 0;
}