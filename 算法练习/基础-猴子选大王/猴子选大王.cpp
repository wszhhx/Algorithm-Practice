#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int main() {
	
	int N;
	cin >> N;
	vector<int> array(N);
	vector<int>::iterator its = array.begin();
	for (int i = 0; i < N; ++i) {
		array[i] = i+1;
	}
	
	while (array.size() > 1) {
		for (int i = 1; i < 3; ++i) {
			its++;
			if (its == array.end())
				its = array.begin();
		}
		its = array.erase(its);
		if (its == array.end())
			its = array.begin();
	}
	cout << *its << endl;
	system("pause");
}