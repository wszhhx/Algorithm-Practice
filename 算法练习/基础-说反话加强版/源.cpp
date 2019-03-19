#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	vector<string> words_ar;
	string words;
	int index, len;
	getline(cin, words);
	index = words.find_first_not_of(' ');
	while (index != -1) {
		for (len = 0; index + len < words.length() && words[index + len] != ' '; ++len);
		words_ar.push_back(words.substr(index, len));
		words.erase(index, len);
		index = words.find_first_not_of(' ');
	}
	for (int i = words_ar.size() - 1; i >= 0; --i) {
		cout << words_ar[i] << (i == 0 ? '\n' : ' ');
	}
	return 0;
}