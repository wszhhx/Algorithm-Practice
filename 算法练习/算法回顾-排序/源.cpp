#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;

void input_array(int[], int&);
void insert_sort(int[], int);

int main() {
	char switcher;
	int array[100];
	int n;
	while (1) {
		printf("||==                         �㷨�ع�֮����                       ==||\n");
		printf("||	һ������������                                              ||\n");
		printf("||		1.�򵥲�������                                      ||\n");
		printf("||		2.ϣ������                                          ||\n");
		printf("||	��������������                                              ||\n");
		printf("||		3.ð������                                          ||\n");
		printf("||		4.��������                                          ||\n");
		printf("||	����ѡ��������                                              ||\n");
		printf("||		5.ֱ��ѡ������                                      ||\n");
		printf("||		6.������                                            ||\n");
		printf("||	��������������                                              ||\n");
		printf("||		7.Ͱ����                                            ||\n");
		printf("����������������������������������������������������������������������\n");
		switcher = _getch();
		system("cls");
		switch (switcher) {
		case '1':
			input_array(array, n);
			insert_sort(array, n);
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			break;
		case '7':
			break;
		case 'q':
			exit(0);
		}
		system("pause");
	}
	
	
}

void input_array(int array[],int &n) {
	printf("����Ԫ�ظ�����");
	cin >> n;
	printf("������������飺");
	for (int i = 0; i < n; ++i) {
		cin >> array[i];
	}
}

void insert_sort(int array[], int n)
{
	int temp;
	int j;
	for (int i = 0; i < n; ++i) {
		temp = array[i];
		for (j = i; j > 0 && array[j - 1] > temp; --j) {
			array[j] = array[j - 1];
		}
		array[j] = temp;
		printf("�� %d �β�������\n",i+1);
		for (int k = 0; k < i + 1; ++k) {
			printf("%d ", array[k]);
		}
		printf("\t");
		for (int k = i + 1; k < n; ++k) {
			printf("%d ", array[k]);
		}
		cout << endl << endl;
	}
	printf("-------------     ���    --------------\n");
	for (int i = 0; i < n; ++i) {
		printf("%d ", array[i]);
	}
}
