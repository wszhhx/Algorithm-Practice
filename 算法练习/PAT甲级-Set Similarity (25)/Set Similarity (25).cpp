/*
题目描述：给出两个整数集合，这两个集合的相似度定义为：(Nc/Nt)*100%, Nc为两个集合中相同数字的个数，Nt是两个集合中整数的总数，你需要计算
         给定的两个集合的相似度。

输入描述：每次输入包含一个用例，每个用例第一个给出的正整数N(N<=50)代表集合的个数,接下来N行中每行的第一个正整数M（M<=104）代表该集合
         中整数的个数，然后跟着M个整数（0~109）。在集合输入完毕后给出一个正整数K（<=2000），接下来给出K行的询问,每个询问给出两个集合
		 编号（1~N），同一行中的每个数字用空格隔开

输出描述：对于每次询问，在一行中输出所求两个集合的相似度,用百分比形式，并精确到小数点后一位。


思路：主要是核心算法——计算集合相似度，因为是集合嘛，所以同一个集合中不会有重复数字出现(卧槽，还真有重复的！)，如果按传统做法，用两两比较来计算相似度，那复杂都得有
     O(m*n)，是平方级别的。所以我们先把两个集合内容升序排序O（max{m,n}log(max{m,n})），然后用两个迭代器指示两集合当前数据，若set1的当前数字小
	 于set2的当前数据，则set1的迭代期指向下一个，若大于则set2的迭代器指向下一个，若等于，则记一个相同数，同时看看这两个集合中哪个集合下一个数字与前一个相同，
	 一样做累加，，如此循环知道其中一个迭代期到边界位置，该部分复杂度为O(m+n)。暂时只能想到这个方法。。。。试试就试试。。。

思路2： 利用两次MAP，第一次遍历第一个集合，若某元素个数为0则变为1，若某元素个数已经为1（重复出现）则不作处理,O(n)
       第二次遍历第二个集合，把所有未重复出现元素都增1,最后统计MAP的元素个数作为Nt,MAP中大于1的元素个数作为NC，完毕。
	 */
#include<iostream>
#include<cstdlib>
#include<vector>
#include<set>
#include<iomanip>
#define MAXN 51
using namespace std;

int M, N, K;
vector<set<int> > Contain;
vector<vector<double> > Record(MAXN, vector<double>(MAXN,-1.0));

double CalSim(int s1, int s2) {
	int Nc = 0;
	int Nt = 0;
	if (Contain[s1].size() < Contain[s2].size()) {
		Nt = Contain[s2].size();
		for (auto its = Contain[s1].begin(); its != Contain[s1].end(); ++its) {
			if (Contain[s2].find(*its) != Contain[s2].end())
				++Nc;
			else
				++Nt;
		}
	}
	else {
		Nt = Contain[s1].size();
		for (auto its = Contain[s2].begin(); its != Contain[s2].end(); ++its) {
			if (Contain[s1].find(*its) != Contain[s1].end())
				++Nc;
			else
				++Nt;
		}
	}

	return (Nc*100.0) / Nt;
}

int main() {
	int temp;
	cin >> N;
	Contain.resize(N+1);
	for (int i = 1; i <= N; ++i) {
		cin >> M;
		for (int j = 0; j < M; ++j) {
			cin >> temp;
			Contain[i].insert(temp);
		}
	}
	int set1, set2;
	cin >> K;
	for (int i = 0; i < K; ++i) {
		cin >> set1 >> set2;
		if (set1 == set2)
			cout << "100.0%" << endl;
		else if (Record[set1][set2] == -1) {
			Record[set1][set2] = CalSim(set1, set2);
			cout << fixed << setprecision(1) << Record[set1][set2] << '%' << endl;
		}
		else
			cout << fixed << setprecision(1) << Record[set1][set2] << '%' << endl;
	}
	system("pause");
	return 0;
}



/*#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<iomanip>
#include<map>
#define MAXN 50
#define MAXM 104
#define MAXK 2000
using namespace std;

int N, M, K;
int Contain[MAXN + 1][MAXM + 1];

double CalSim(int set1, int set2) {
	int *Set1, *Set2;
	int Nc = 0;
	int Nt = 0;
	map<int, int> TOSET;
	map<int, bool> VISITED;
	Set1 = Contain[set1];
	Set2 = Contain[set2];
	for (int i = 1; i <= Set1[0]; ++i) {
		if(TOSET[Set1[i]] == 0)
			TOSET[Set1[i]]++;
	}
	for (int i = 1; i <= Set2[0]; ++i) {
		if (!VISITED[Set2[i]]) {
			TOSET[Set2[i]]++;
			VISITED[Set2[i]] = true;
		}
	}
	for (map<int, int>::iterator its = TOSET.begin(); its != TOSET.end(); ++its) {
		if (its->second > 1)
			Nc++;
	}
	//TOSET[Set1[1]] += 1;
	//TOSET[Set2[1]] += 1;
	//for (i = 1, j = 1; i <= Set1[0] && j <= Set2[0];) {
	//	if (Set1[i] < Set2[j]) {
	//		++i;
	//		TOSET[Set1[i]] += 1;
	//	}
	//	else if (Set1[i] > Set2[j]) {
	//		++j;
	//		TOSET[Set2[j]] += 1;
	//	}
	//	else {
	//		Nc++;
	//		while (i < Set1[0] && j < Set2[0] && (Set1[i + 1] == Set1[i] || Set2[j + 1] == Set2[j])) {   //过滤相同数字，保证统一偏移
	//			if (Set1[i + 1] == Set1[i]) {
	//				++i;
	//			}
	//			if (Set2[j + 1] == Set2[j]) {
	//				++j;
	//			}
	//		}
	//		++i;
	//		++j;
	//		if(i <= Set1[0])
	//			TOSET[Set1[i]] += 1;
	//		if(j <= Set2[0])
	//			TOSET[Set2[j]] += 1;
	//	}
	//}
	Nt = TOSET.size();
	return (Nc*100.0) / Nt;
}

int main() {
	cin >> N;
	int set1, set2;
	for (int i = 1; i <= N; ++i) {
		cin >> M;
		Contain[i][0] = M;
		for (int j = 1; j <= M; ++j) {
			cin >> Contain[i][j];
		}
		sort(Contain[i] + 1, Contain[i] + M);
	}
	cin >> K;
	for (int i = 0; i < K; ++i) {
		cin >> set1 >> set2;
		cout << fixed << setprecision(1) << CalSim(set1, set2) << '%' << endl;
	}
	system("pause");
	return 0;
	
}*/

