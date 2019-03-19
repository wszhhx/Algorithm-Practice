#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

typedef struct {
	char name[20];
	char birthday[10];
	char sex;
	char tele[17];
	char phone[17];
}mem;

int main() {
	mem mems[10];
	string require;
	int N;
	int num;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		scanf_s("%s %s %c %s %s", mems[i].name, mems[i].birthday, &mems[i].sex, mems[i].tele, mems[i].phone);
	}
	getline(cin, require);
	for (int i = 0; i < require.length(); ++i) {
		if (require[i] >= '0' && require[i] <= '9') {
			num = require[i] - 48;
			if (num >= N)
				cout << "Not Found" << endl;
			else {
				cout << mems[num].name << ' ' << mems[num].tele << ' ' << mems[num].phone << ' ' << mems[num].sex << ' ' << mems[num].birthday << endl;
			}
		}
	}
	return 0;
}