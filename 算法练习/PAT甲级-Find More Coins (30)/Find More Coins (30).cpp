/*
题目描述：伊娃喜欢收集全世界的硬币，包括其他星球（比如火星）。一天，她参观了可以用所有种类硬币付款的环宇购物中心，然而他们对付款有一定的限制：
         对于没笔订单，她必须付整好的钱，不支持找零，她有10^4枚硬币，她需要你的帮助，你需要告诉她，对于每个数量的钱，她是否能凑出刚刚好够付
		 款的硬币；

输入描述：每次输入包含一个用例，对于每个用例，第一行包含2个正整数N(N<=10^4)为硬币总数，M(M<=100)为伊娃需要付款的总额,第二行给出N个硬币的面
         值,所有数据皆是正整数，所有数据用空格隔开。

输出描述：对于每个测试用例，在一行内递增输出构成M总额的所有硬币的面值，所有数字用空格隔开，结尾不能有多余空格，若解决方案不唯一，输出需要硬币
         数最小的答案，若没有解决方案，则输出“No Solution”
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

int f[MAXTOTAL][MAXAMOUNT];         //f[n][m]表示 前n个数中 得出的 最接近m 的值  
bool has[MAXTOTAL][MAXAMOUNT];      //has[n][m]表示在前n个数中得出最接近m的值时 是否用到c[n]  
int* c = NULL;

int calcClosestSum(int n, int m)
{
	memset(f, 0, sizeof(int)*MAXTOTAL*MAXAMOUNT);
	memset(has, false, sizeof(bool)*MAXTOTAL*MAXAMOUNT);
	int i, j;
	int sec; // 表示放入c[i]后的值  
	for (i = 1; i<n + 1; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (j - c[i]<0) sec = 0; // 如果不满足小于等于j，则说明放入后是非法值，可以设其为0，表示面值无效。  
			else sec = f[i - 1][j - c[i]] + c[i]; // 正常情况下计算放入c[i]的值。  
			if (f[i - 1][j] > sec)
			{
				f[i][j] = f[i - 1][j];
			}
			else
			{
				f[i][j] = sec;
				has[i][j] = true;     //用到c[i]了 设has[i][j]为true  
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
	sort(&c[1], &c[n + 1], cmp);     //从大到小排序  

	int res = calcClosestSum(n, m);
	if (res == m)                   //有解  
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
	else                        //无解  
		cout << "No Solution" << endl;
	return 0;
}