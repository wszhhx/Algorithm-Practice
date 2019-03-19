/*
��Ŀ���������������������ϣ����������ϵ����ƶȶ���Ϊ��(Nc/Nt)*100%, NcΪ������������ͬ���ֵĸ�����Nt����������������������������Ҫ����
         �������������ϵ����ƶȡ�

����������ÿ���������һ��������ÿ��������һ��������������N(N<=50)�����ϵĸ���,������N����ÿ�еĵ�һ��������M��M<=104������ü���
         �������ĸ�����Ȼ�����M��������0~109�����ڼ���������Ϻ����һ��������K��<=2000��������������K�е�ѯ��,ÿ��ѯ�ʸ�����������
		 ��ţ�1~N����ͬһ���е�ÿ�������ÿո����

�������������ÿ��ѯ�ʣ���һ������������������ϵ����ƶ�,�ðٷֱ���ʽ������ȷ��С�����һλ��


˼·����Ҫ�Ǻ����㷨�������㼯�����ƶȣ���Ϊ�Ǽ��������ͬһ�������в������ظ����ֳ���(�Բۣ��������ظ��ģ�)���������ͳ�������������Ƚ����������ƶȣ��Ǹ��Ӷ�����
     O(m*n)����ƽ������ġ����������Ȱ���������������������O��max{m,n}log(max{m,n})����Ȼ��������������ָʾ�����ϵ�ǰ���ݣ���set1�ĵ�ǰ����С
	 ��set2�ĵ�ǰ���ݣ���set1�ĵ�����ָ����һ������������set2�ĵ�����ָ����һ���������ڣ����һ����ͬ����ͬʱ�����������������ĸ�������һ��������ǰһ����ͬ��
	 һ�����ۼӣ������ѭ��֪������һ�������ڵ��߽�λ�ã��ò��ָ��Ӷ�ΪO(m+n)����ʱֻ���뵽������������������Ծ����ԡ�����

˼·2�� ��������MAP����һ�α�����һ�����ϣ���ĳԪ�ظ���Ϊ0���Ϊ1����ĳԪ�ظ����Ѿ�Ϊ1���ظ����֣���������,O(n)
       �ڶ��α����ڶ������ϣ�������δ�ظ�����Ԫ�ض���1,���ͳ��MAP��Ԫ�ظ�����ΪNt,MAP�д���1��Ԫ�ظ�����ΪNC����ϡ�
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
	//		while (i < Set1[0] && j < Set2[0] && (Set1[i + 1] == Set1[i] || Set2[j + 1] == Set2[j])) {   //������ͬ���֣���֤ͳһƫ��
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

