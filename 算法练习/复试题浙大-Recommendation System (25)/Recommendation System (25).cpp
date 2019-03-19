#include<iostream>
#include<set>
using namespace std;

int Count[50001];

typedef struct node {
	int ID;
	int CNT;
	node(int a, int b) :ID(a), CNT(b) {}
	bool operator < (const node &a) const {
		return (CNT == a.CNT) ? ID < a.ID : CNT > a.CNT;
	}
}Node;

int main() {
	int N;
	set<Node> SET;
	int k;
	cin >> N >> k;
	int id;
	cin >> id;
	SET.insert(node(id, 1));
	Count[id] = 1;
	set<Node>::iterator its;
	for (int i = 1; i < N; ++i) {
		cin >> id;
		its = SET.begin();
		cout << id << ":";
		for (int j = 0; j < k && its != SET.end(); ++its, ++j) {
			cout << ' ' << its->ID;
		}
		auto its2 = SET.find(node(id, Count[id]));
		if (its2 == SET.end()) {
			Count[id] = 1;
		}
		else {
			Count[id] += 1;
			SET.erase(its2);
		}
		SET.insert(node(id, Count[id]));
		cout << endl;
	}
	return 0;
}