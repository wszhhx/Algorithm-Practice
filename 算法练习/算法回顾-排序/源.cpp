#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;

void input_array(int[], int&);
void output_array(int[], int);

void insert_sort(int[], int);

void shell_insert(int[], int, int);
void shell_sort(int[], int);

void bubble_sort(int[], int);

int quick_pass(int[], int, int);
void quick_sort_in(int[], int, int);
void quick_sort(int[], int);

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
			output_array(array, n);
			break;
		case '2':
			input_array(array, n);
			shell_sort(array, n);
			output_array(array, n);
			break;
		case '3':
			input_array(array, n);
			bubble_sort(array, n);
			output_array(array, n);
			break;
		case '4':
			input_array(array, n);
			quick_sort(array, n);
			output_array(array, n);
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
	for (int i = 1; i <= n; ++i) {
		cin >> array[i];
	}
}
void output_array(int array[], int n) {
	printf("-------------     结果    --------------\n");
	for (int i = 1; i <= n; ++i) {
		printf("%d ", array[i]);
	}
}

void insert_sort(int array[], int n)
{
	int j;
	for (int i = 1; i <= n; ++i) {
		array[0] = array[i];
		for (j = i; j > 1 && array[j - 1] > array[0]; --j) {
			array[j] = array[j - 1];
		}
		array[j] = array[0];
		printf("第 %d 次插入结果：\n",i+1);
		for (int k = 1; k < i + 1; ++k) {
			printf("%d ", array[k]);
		}
		printf("\t");
		for (int k = i + 1; k <= n; ++k) {
			printf("%d ", array[k]);
		}
		cout << endl << endl;
	}
	
}

void shell_insert(int array[], int n, int delta) {
	int j;
	for (int i = 1 + delta; i <= n; ++i) {
		array[0] = array[i];
		for (j = i; j >= 1 + delta && array[j-delta] > array[0] ; j -= delta) {
			array[j] = array[j - delta];
		}
		array[j] = array[0];
	}
}
void shell_sort(int array[], int n) {
	int delta = n / 2;
	int i = 1;
	while (delta) {
		cout << "delta : " << delta << endl;
		shell_insert(array, n, delta);
		delta /= 2;
		printf("第 %d 次排序结果：\n", i++);
		for (int i = 1; i <= n; ++i) {
			printf("%d ", array[i]);
		}
		cout << endl;
	}
}

void bubble_sort(int array[], int n) {
	int count = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 2; j <= n-i; ++j) {
			if (array[j] < array[j - 1]) {
				array[j] = array[j] ^ array[j - 1];
				array[j - 1] = array[j] ^ array[j - 1];
				array[j] = array[j] ^ array[j - 1];
			}
		}
		printf("第 %d 次排序结果：\n", count++);
		for (int i = 1; i <= n; ++i) {
			printf("%d ", array[i]);
		}
		cout << endl;
	}
}

int quick_pass(int array[], int low, int high) {
	array[0] = array[low];
	while (low < high) {
		while (low < high && array[high] >= array[0])
			high--;
		array[low] = array[high];
		while (low < high && array[low] <= array[0])
			low++;
		array[high] = array[low];
	}
	array[low] = array[0];
	return low;
}

void quick_sort_in(int array[], int low, int high) {
	int pos;
	if (low < high) {
		pos = quick_pass(array, low, high);
		quick_sort_in(array, low, pos - 1);
		quick_sort_in(array, pos + 1, high);
	}
}

void quick_sort(int array[], int n) {
	quick_sort_in(array, 1, n);
}

