/*#include<string>
#include<vector>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#define MAXSIZE 100000
using namespace std;

typedef struct{
	int Contain[MAXSIZE];
	int size;
}StackNode,*STACK;

void Push(STACK S, int data) {
	S->Contain[S->size++] = data;
	return;
}

void Pop(STACK S) {
	if (S->size == 0) {
		printf("Invalid\n");
	}
	else {
		printf("%d\n", S->Contain[--S->size]);
	}
	return;
}

void sift(int Heap[], int root, int n) {
	int temp = Heap[root];
	int i = root;
	int j = i * 2;
	bool finished = false;
	while (j <= n && !finished) {
		if (j < n && Heap[j] > Heap[j + 1])
			++j;
		if (temp < Heap[j])
			finished = true;
		else {
			Heap[i] = Heap[j];
			i = j;
			j *= 2;
		}
	}
	Heap[i] = temp;
	return;
}

void CrtHeap(int Heap[], int length) {
	for (int i = length / 2; i >= 1; --i) {
		sift(Heap, i, length);
	}
	return;
}

int NstMinData(int Copy[], int length, int index) {//ÓÃµ½¶ÑÅÅÐò
	CrtHeap(Copy, length);
	int temp;
	for (int i = length; i > length - index +1; --i) {
		temp = Copy[1];
		Copy[1] = Copy[i];  ////////////////////////
		Copy[i] = temp;
		sift(Copy, 1, i - 1);
	}
	return Copy[1];
}

void PeekMedian(STACK S) {
	if (S->size == 0) {
		printf("Invalid\n");
	}
	else {
		int index;
		if (S->size % 2)
			index = (S->size + 1) / 2;
		else
			index = S->size / 2;
		int Copy[MAXSIZE];
		for (int i = 0; i < S->size; ++i)
			Copy[i+1] = S->Contain[i];
		
		cout << NstMinData(Copy, S->size, index) << endl;
	}
	return;
}

int main() {
	STACK S = (StackNode *)malloc(sizeof(StackNode));
	S->size = 0;
	int length, key;
	cin >> length;
	string cmd;
	for (int i = 0; i < length; ++i) {
		cin >> cmd;
		if (cmd.find("Push") < 50) {
			cin >> key;
			Push(S, key);
		}
		else if (cmd.find("PeekMedian") < 50) {
			PeekMedian(S);
		}
		else {
			Pop(S);
		}
	}

	return 0;
}*/

#include<iostream>
#include<stack>
#include<cstring>
#include<string>
#include<vector>
#define MAXSIZE 100000
using namespace std;
int C[MAXSIZE + 1];

int lowbit(int x) {
	return x&(-x);
}

void add(int pos, int value) {
	while (pos < MAXSIZE) {
		C[pos] += value;
		pos += lowbit(pos);
	}
	return;
}

int sum(int pos) {
	int res = 0;
	while (pos > 0) {
		res += C[pos];
		pos -= lowbit(pos);
	}
	return res;
}

int find(int nst) {
	int l = 0, r = MAXSIZE;
	int mid, res;
	while (l < r - 1) {
		mid = (l + r) / 2;
		res = sum(mid);
		if (res < nst)
			l = mid;
		else
			r = mid;
	}
	return l + 1;
}

int main() {
	stack<int> S;
	string cmd;
	int N;
	int key;
	memset(C, 0, sizeof(C));
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> cmd;
		if (cmd.find("Push") < 20) {
			cin >> key;
			S.push(key);
			add(key, 1);
		}
		else if (cmd.find("Pop") < 20) {
			if (S.empty())
				printf("Invalid\n");
			else {
				cout << S.top() << endl;
				add(S.top(), -1);
				S.pop();
				
			}
		}
		else {
			if (S.empty())
				printf("Invalid\n");
			else {
				if (S.size() % 2 == 0)
					cout << find(S.size() / 2) << endl;
				else
					cout << find((S.size() + 1) / 2)<< endl;
			}
		}
		
	}
	return 0;
}