#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

typedef struct node{
	string data;
	int Lchild;
	int Rchild;
}TreeNode;

TreeNode TREE_LIST[21];
int root;
bool flag[21];

void Generate_infix(int n_index) {
	if (n_index == -1)
		return;
	if (n_index != root && (TREE_LIST[n_index].Lchild != -1 || TREE_LIST[n_index].Rchild != -1)) {
		cout << '(';
	}
	Generate_infix(TREE_LIST[n_index].Lchild);
	cout << TREE_LIST[n_index].data;
	Generate_infix(TREE_LIST[n_index].Rchild);
	if (n_index != root && (TREE_LIST[n_index].Lchild != -1 || TREE_LIST[n_index].Rchild != -1)) {
		cout << ')';
	}
}

int main() {
	int N;
	int Lchild, Rchild;
	string data;
	cin >> N;
	memset(flag, false, sizeof(bool)*(N + 1));
	
	for (int i = 1; i <= N; ++i) {
		cin >> data >> Lchild >> Rchild;
		TREE_LIST[i].data = data;
		TREE_LIST[i].Lchild = Lchild;
		TREE_LIST[i].Rchild = Rchild;
		if(Lchild != -1)
			flag[Lchild] = true;
		if(Rchild != -1)
			flag[Rchild] = true;
	}
	for (int i = 1; i <= N; ++i) {
		if (flag[i] == false) {
			root = i;
			break;
		}
	}
	Generate_infix(root);
	cout << endl;
	system("pause");
	return 0;
}