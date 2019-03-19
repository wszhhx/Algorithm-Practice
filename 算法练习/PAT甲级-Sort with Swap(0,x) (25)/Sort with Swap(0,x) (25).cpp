/*
��Ŀ��������������һ���������У�0��1��2��...��N-1�����ܷ�����ܽ������������򣬵������ֻ����������{0,x}�����أ�
         ����Ҫ�ҵ��ź�һ������ǰN���Ǹ������������Сswap{0,x}����������

����������ÿ���������һ��������������һ��������N��N<=10^5������������һ����N�����ֵ�����{0,1,...,N-1}һ�������������ÿո����
��������������Ҫ���Ľ�������С������
˼·����0�����Լ�λ����ʱ����0���ڵ�λ�ñ���Ӧ���ڵ����֣���0���Լ�λ�����򽻻�һ�������Լ�λ�õ����֣�Ϊ�˼��㷽�㣬��������С�Ĳ����Լ�ԭ��λ�õ�����
      �����ó��Ľ�������һ������С�ģ�̰���㷨��
PS��λ���������Ƕ��һ���õĻ�������磺Addr[Addr[0]] ^= Addr[0] ^= Addr[Addr[0]] ^= Addr[0];�ó��Ĵ𰸲��ǽ���Addr[Addr[0]]��Addr[0]
*/
#include<iostream>
#define MAXSIZE 100010
using namespace std;

int Addr[MAXSIZE];                          //Addr[i]��������i���±�


int main() {
	int N;
	int left = 0;                           //ʣ��δ��λ����
	int min_wrong = -1;                     //��Сδ��λ����
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
				for (min_wrong += 1; min_wrong < N && Addr[min_wrong] == min_wrong; ++min_wrong);  //���¼�����Сδ��λ����
			}
			if (Addr[0] == min_wrong)
				for (min_wrong += 1; min_wrong < N && Addr[min_wrong] == min_wrong; ++min_wrong);
			temp = Addr[0];                                    //Ƕ�׼�λ��������"Addr[ Addr[0] ] ^= Addr[0] ^= Addr[ Addr[0] ] ^= Addr[0]"
			Addr[0] ^= Addr[temp] ^= Addr[0] ^= Addr[temp];    //����0��0��ռ�е�λ�ñ���������
			left--;
			swap_count++;
		}
		cout << swap_count << endl;
	}
	return 0;
}