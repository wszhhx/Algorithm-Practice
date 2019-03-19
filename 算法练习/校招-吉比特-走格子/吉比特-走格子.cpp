//#include<iostream>
//#include<algorithm>
//#include<stack>
//#include<vector>
//#include<cstdlib>
////要找最优路径上的最小值
//#define INI 65535
//using namespace std;
//typedef struct {
//	int matrix[1000][1000];
//	int vNum;
//	int eNum;
//}Graph, *G;
//
//int length;
//int N, M;
//G graph;
//int map[1000][1000];
//int indexMap[1000][1000];
//
//void Initial(int array[], int n) {
//	for (int i = 0; i < n; ++i)
//		array[i] = -INI;
//}
//
//void GenerateGraph() {
//	int p;
//	stack<int> S;
//	S.push(1);
//	int *haveView = (int *)malloc(sizeof(int) * length);
//	memset(haveView, 0, length * sizeof(int));
//	graph->matrix[0][1] = map[0][0];
//	for (int i = 0; i < length; ++i) {
//		graph->matrix[i][i] = 0;
//	}
//	while (!S.empty()) {
//		p = S.top();
//		S.pop();
//		if (haveView[p])
//			continue;
//		if (!haveView[p] && (p-1) % N + 1 < N) {
//			graph->matrix[p][p + 1] = map[(p-1) / N][(p-1) % N + 1];
//			S.push(p + 1);
//		}
//		if (!haveView[p] && (p-1) / N + 1 < M) {
//			graph->matrix[p][p + N] = map[(p - 1) / N + 1][(p - 1) % N];
//			S.push(p + N);
//		}
//		haveView[p] = true;
//	}
//}
//
//int ProcMax() {
//	int k = 0,max = -INI;
//	int v, w;
//	int *D = (int *)malloc(sizeof(int) * length + 1);
//	bool *F = (bool*)malloc(sizeof(bool) * length + 1);
//	int *P = (int *)malloc(sizeof(int) * length + 1);
//	stack<int> path;
//	Initial(D, length);
//	memset(F, 0, length * sizeof(bool));
//	memset(P, 0, length * sizeof(int));
//	F[0] = true;
//	for (int i = 0; i < length; ++i)
//		D[i] = graph->matrix[0][i];
//	for (int i = 1; i < length; ++i) {
//		max = -INI;
//		for (int j = 0; j < length; ++j) {
//			if (!F[j] && D[j] > max) {
//				max = D[j];
//				k = j;
//				
//			}
//		}
//		F[k] = true;
//		for (int j = 0; j < length; ++j) {
//			if (!F[j] && max + graph->matrix[k][j] > D[j]) {
//				D[j] = max + graph->matrix[k][j];
//				P[j] = k;
//			}
//		}
//	}
//	k = length - 1;
//	while (k != 0) {
//		path.push(P[k]);
//		k = P[k];
//	}
//	
//	int min, temp, pre;
//	pre = 0;
//	min = graph->matrix[0][path.top()];
//	
//	temp = min;
//
//
//	while (!path.empty()) {
//		temp += graph->matrix[pre][path.top()];
//		pre = path.top();
//		path.pop();
//		
//		if (min > temp)
//			min = temp;
//	}
//
//	return -min + 1;
//}
//
//void temp() {
//	for (int i = 0; i < 1000; ++i)
//		Initial(graph->matrix[i], 1000);
//}
//
//int main() {
//
//	graph = (Graph*)malloc(sizeof(Graph));
//	length = 1;
//	cin >> M >> N;
//	temp();
//	for (int i = 0; i < M; ++i) {
//		for (int j = 0; j < N; ++j) {
//			cin >> map[i][j];
//			indexMap[M][N] = length++;
//		}
//	}
//	
//	graph->vNum = length;
//	GenerateGraph();
//	cout << ProcMax() << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<algorithm>
//#include<stack>
//using namespace std;
//int main() {
//	int map[1000][1000];
//	int M, N, i, j;
//	cin >> M >> N;
//	for (i = 0; i < M; ++i) {
//		for (j = 0; j < N; ++j) {
//			cin >> map[M][N];
//		}
//	}
//	int min = map[0][0];
//	int temp = min;
//	int x, y;
//	i = 0;
//	j = 0;
//	while (i != M - 1 && j != N - 1) {
//		cout << temp << endl;
//		if (i + 1 < M && j + 1 < N) {
//			if (map[i + 1][j] > map[i][j + 1]) {
//				temp += map[i + 1][j];
//				i++;
//			}
//			else {
//				temp += map[i][j + 1];
//				j++;
//			}
//		}
//		else if (i + 1 == M) {
//			temp += map[i][j + 1];
//			i++;
//		}
//		else {
//			temp += map[i + 1][j];
//			j++;
//		}
//		if (temp < min)
//			min = temp;
//	}
//	min = -min;
//	cout << min;
//}

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>

using namespace std;

int main() {
	/*int map[100][100];
	int dp[101][101];*/
	int M, N;
	cin >> M >> N;
	vector<vector<int> > map(M, vector<int>(N, 0));
	vector<vector<int> > dp(M+1, vector<int>(N+1, 0));
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
		}
	}
	int bottom, right;
	for (int i = M - 1; i >= 0; --i) {
		for (int j = N - 1; j >= 0; --j) {
			bottom = 1 > dp[i + 1][j] ? 1 : dp[i + 1][j];
			right = 1 > dp[i][j + 1] ? 1 : dp[i][j + 1];
			dp[i][j] = (bottom < right ? bottom : right) - map[i][j];
		}
	}
	cout << (dp[0][0] > 0 ? dp[0][0] : 1) <<endl;
	return 0;
	
}