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
		printf("||==                         算法回顾之排序                       ==||\n");
		printf("||	一、插入类排序                                              ||\n");
		printf("||		1.简单插入排序                                      ||\n");
		printf("||		2.希尔排序                                          ||\n");
		printf("||	二、交换类排序                                              ||\n");
		printf("||		3.冒泡排序                                          ||\n");
		printf("||		4.快速排序                                          ||\n");
		printf("||	三、选择类排序                                              ||\n");
		printf("||		5.直接选择排序                                      ||\n");
		printf("||		6.堆排序                                            ||\n");
		printf("||	三、其他类排序                                              ||\n");
		printf("||		7.桶排序                                            ||\n");
		printf("———————————————————————————————————\n");
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
	printf("输入元素个数：");
	cin >> n;
	printf("输入待排序数组：");
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
		printf("第 %d 次插入结果：\n",i+1);
		for (int k = 0; k < i + 1; ++k) {
			printf("%d ", array[k]);
		}
		printf("\t");
		for (int k = i + 1; k < n; ++k) {
			printf("%d ", array[k]);
		}
		cout << endl << endl;
	}
	printf("-------------     结果    --------------\n");
	for (int i = 0; i < n; ++i) {
		printf("%d ", array[i]);
	}
}
