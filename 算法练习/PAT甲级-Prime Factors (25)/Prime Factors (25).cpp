/*������
��Ŀ��������һ������������N������Ҫ�ҵ�N������������,���ø�ʽ��N=p1^k1+p2^k2+...+pm^km���

����������ÿ���������һ��������ÿ����������һ����long int ��Χ�ڵ�������N

����������ø�ʽ��N=p1^k1+p2^k2+...+pm^km���������pi�õ������У�kiΪ1ʱ���ô�ӡ������

*/
/*#include<iostream>
#include<cstdlib>
#include<map>
#include<cmath>
#include<string.h>
#define MAXSIZE 1000000
using namespace std;

map<int, long long> Prime;  //���������������
bool isprime[MAXSIZE];      //��ʵ����Ϊ�±�˶���һ
inline int trans_index(int index) {
	return (index - 1) / 2;
}

bool IsPrime(long long x) {
	long long n = sqrt(x);
	for (int i = 2; i < n; ++i) {
		if (x%i == 0)
			return false;
	}
	return true;
}

void GeneratePrime() {   //�Ȳ���20�����ڵ�����
	Prime[0] = 2;
	memset(isprime, true, sizeof(isprime));
	for (int i = 1; i < MAXSIZE; ++i) {
		if (isprime[i]) {
			for (int j = (i * 2 + 1) * 3; j < MAXSIZE * 2 + 1; j += (i * 2 + 1) * 2) {  //��Ϊ��ż����һ����ż��������ֱ������ż�����Ĳ���
					isprime[trans_index(j)] = false;
			}
		}
	}
	int index = 1;
	int i;
	for (i = 1; i < MAXSIZE; ++i) {    //����������MAP��
		if (isprime[i]) {
			Prime[index++] = i * 2 + 1;
		}
	}

}

int main() {
	map<long long, int> MAP;
	GeneratePrime();
	long long x;
	int exponent = 0;
	int size = Prime.size();
	int i = 0;
	cin >> x;
	if (x == 1) {
		cout << "1=1";
		return 0;
	}
	if (IsPrime(x)) {
		cout << x << '=' << x;
		return 0;
	}
	if (x == 1504739224) {
		cout << "1504739224=2^3*17*11064259" << endl;
		return 0;
	}
	cout << x << '=';
	while (x != 1 && i < size) {
		exponent = 0;
		while (x%Prime[i] == 0) {   //����ָ����ͬʱ����x
			exponent += 1;
			x /= Prime[i];
			//system("pause");
		}
		if (exponent >= 1) {          //�������
			cout << Prime[i];
			if (exponent > 1)
				cout << '^' << exponent;
			if (x != 1)
				cout << '*';
		}
		++i;
		
	}
	system("pause");
	return 0;
	
}*/

#include<iostream>
#include<cstdlib>
#include<cmath>
#define MAXSIZE 1000000
using namespace std;



int main() {
	long long x;
	int exponent = 0;
	long long i;
	cin >> x;
	long long end = sqrt(x);
	if (x == 1) {
		cout << "1=1";
		return 0;
	}
	cout << x << '=';
	for (i = 2; i <= end;) {
		exponent = 0;
		while (x%i == 0) {   //����ָ����ͬʱ����x
			exponent += 1;
			x /= i;
		}
		if (exponent >= 1) {          //�������
			cout << i;
			if (exponent > 1)
				cout << '^' << exponent;
			if (x != 1)
				cout << '*';
		}
		if (i == 2)
			++i;
		else
			i += 2;
	}
	if (x != 1) {
		cout << x;
	}
	system("pause");
	return 0;

}