#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;


int main() {
	char res[100];
	scanf_s("%s", res, sizeof(res));
	for (int i = 0; res[i] != '\0'; ) {
		switch (res[i]) {
		case '-':
			printf("fu");
			break;
		case '0':
			printf("ling");
			break;
		case '1':
			printf("yi");
			break;
		case '2':
			printf("er");
			break;
		case '3':
			printf("san");
			break;
		case '4':
			printf("si");
			break;
		case '5':
			printf("wu");
			break;
		case '6':
			printf("liu");
			break;
		case '7':
			printf("qi");
			break;
		case '8':
			printf("ba");
			break;
		case '9':
			printf("jiu");
			break;
		}
		if (res[++i] != '\0') {
			printf(" ");
		}
		else {
			printf("\n");
		}
	}

	system("pause");
}