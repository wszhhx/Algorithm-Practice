/*
˼·�����Ȼ����ж��ǿ϶�Ҫ�ģ���string��reverse�ܿ�����жϣ������Ϊ����̫�󣬵����ַ������в�������Ĵ�������ӷ����㡣
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string SAddition(string a, string b) {
	string sum;
	int a_size = a.size();
	int b_size = b.size();
	int carry = 0;
	int temp = 0;
	int i = a.size() - 1;
	int j = b.size() - 1;
	while (i >= 0 && j >= 0) {
		temp = a[i] - 48 + b[j] - 48 + carry;
		sum.push_back(temp % 10 + 48);
		carry = temp / 10;
		--i;
		--j;
	}//��Ϊa,b�����϶�һ�����Բ��ô�����ܵ�ʣ�����ݡ�
	if (carry != 0) {
		sum.push_back(carry + 48);
	}
	reverse(sum.begin(), sum.end());
	return sum;
}

int main() {
	string source;
	string resource;
	string sum;
	int cnt;
	while (cin >> source) {
		cnt = 0;
		resource = source;
		reverse(resource.begin(), resource.end());
		while (source != resource && cnt < 10) {
			sum = SAddition(source, resource);
			printf("%s + %s = %s\n", source.c_str(), resource.c_str(), sum.c_str());
			source = sum;
			resource = sum;
			reverse(resource.begin(), resource.end());
			cnt++;
		}
		if (cnt == 10)
			printf("Not found in 10 iterations.\n");
		else
			printf("%s is a palindromic number.\n", source.c_str());
	}
	return 0;
}