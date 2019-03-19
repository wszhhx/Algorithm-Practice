#include<iostream>
using namespace std;
int main() {
	char str1[11];
	char str2[11];
	int str1_length;
	int str2_length;
	int ans;
	while (scanf("%s %s", str1, str2) != EOF) {
		ans = 0;
		for (str1_length = 0; str1[str1_length] != '\0'; ++str1_length);
		for (str2_length = 0; str2[str2_length] != '\0'; ++str2_length);
		for (int i = 0; i < str1_length; ++i) {
			if (str1[i] == '0')
				continue;
			for (int j = 0; j < str2_length; ++j) {
				if (str2[j] == '0')
					continue;
				ans += (str1[i] - 48)*(str2[j] - 48);
			}
		}
		cout << ans << endl;
	}
	return 0;
}