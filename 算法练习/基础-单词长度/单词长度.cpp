#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main() {
	vector<int> result;
	char res[1000];
	gets_s(res);
	int word_len = 0;
	int j;
	
	for (int i = 0; res[i] != '\0' && res[i] != '.'; ++i) {
		if (res[i] == ' ') {
			continue;
		}
		else {
			word_len = 0;
			for (j = i; res[j] != '\0' && res[j] != '.' && res[j] != ' '; ++j) {
				word_len++;
			}
			i = j;
			result.push_back(word_len);
		}
	}
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << (i + 1 == result.size() ? '\n' : ' ');
	}
	system("pause");
}
