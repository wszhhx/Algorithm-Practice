/*
��Ŀ����������ϲ���ռ�ȫ�����Ӳ�ң������������򣨱�����ǣ���һ�죬���ι��˿�������������Ӳ�Ҹ���Ļ�������ģ�Ȼ�����ǶԸ�����һ�������ƣ�
         ����û�ʶ����������븶���õ�Ǯ����֧�����㣬����10^4öӲ�ң�����Ҫ��İ���������Ҫ������������ÿ��������Ǯ�����Ƿ��ܴճ��ոպù���
		 ���Ӳ�ң�

����������ÿ���������һ������������ÿ����������һ�а���2��������N(N<=10^4)ΪӲ��������M(M<=100)Ϊ������Ҫ������ܶ�,�ڶ��и���N��Ӳ�ҵ���
         ֵ,�������ݽ��������������������ÿո������

�������������ÿ��������������һ���ڵ����������M�ܶ������Ӳ�ҵ���ֵ�����������ÿո��������β�����ж���ո������������Ψһ�������ҪӲ��
         ����С�Ĵ𰸣���û�н���������������No Solution��
		 PS:
*/

#include <iostream>  
#include <fstream>  
#include <algorithm>  
#include <cstring>  
#include <vector>  
using namespace std;

#define MAXTOTAL    10001  
#define MAXAMOUNT   101  

int f[MAXTOTAL][MAXAMOUNT];         //f[n][m]��ʾ ǰn������ �ó��� ��ӽ�m ��ֵ  
bool has[MAXTOTAL][MAXAMOUNT];      //has[n][m]��ʾ��ǰn�����еó���ӽ�m��ֵʱ �Ƿ��õ�c[n]  
int* c = NULL;

int calcClosestSum(int n, int m)
{
	memset(f, 0, sizeof(int)*MAXTOTAL*MAXAMOUNT);
	memset(has, false, sizeof(bool)*MAXTOTAL*MAXAMOUNT);
	int i, j;
	int sec; // ��ʾ����c[i]���ֵ  
	for (i = 1; i<n + 1; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (j - c[i]<0) sec = 0; // ���������С�ڵ���j����˵��������ǷǷ�ֵ����������Ϊ0����ʾ��ֵ��Ч��  
			else sec = f[i - 1][j - c[i]] + c[i]; // ��������¼������c[i]��ֵ��  
			if (f[i - 1][j] > sec)
			{
				f[i][j] = f[i - 1][j];
			}
			else
			{
				f[i][j] = sec;
				has[i][j] = true;     //�õ�c[i]�� ��has[i][j]Ϊtrue  
			}
		}
	}
	return f[n][m];
}

bool cmp(const int& A, const int& B)
{
	return A>B;
}

int main()
{
	int n, m;
	cin >> n >> m;
	c = new int[n + 1];
	memset(c, 0, sizeof(int)*(n + 1));

	int i;
	for (i = 0; i<n; i++)
	{
		cin >> c[i + 1];
	}
	sort(&c[1], &c[n + 1], cmp);     //�Ӵ�С����  

	int res = calcClosestSum(n, m);
	if (res == m)                   //�н�  
	{
		vector<int> v;
		while (m)
		{
			while (!has[n][m])
				n--;
			v.push_back(c[n]);
			m = m - c[n];
			n--;
		}
		for (i = 0; i<v.size() - 1; i++)
			cout << v[i] << ' ';
		cout << v[i] << endl;
	}
	else                        //�޽�  
		cout << "No Solution" << endl;
	return 0;
}