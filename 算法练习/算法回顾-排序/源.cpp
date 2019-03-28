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

void select_sort(int[], int);

void sift_down(int[], int, int);
void heap_sort(int[], int);

void merge_r(int[], int, int, int);
void merge_sort_in_r(int[], int, int);
void merge_sort_r(int[], int);

void merge(int[], int, int, int, int);
void merge_sort(int[], int);

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
		printf("||		8.归并排序(递归)                                     ||\n");
		printf("||		9.归并排序(非递归)                                  ||\n");
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
			input_array(array, n);
			select_sort(array, n);
			output_array(array, n);
			break;
		case '6':
			input_array(array, n);
			heap_sort(array, n);
			output_array(array, n);
			break;
		case '7':
			break;
		case '8':
			input_array(array, n);
			merge_sort_r(array, n);
			output_array(array, n);
			break;
		case '9':
			input_array(array, n);
			merge_sort(array, n);
			output_array(array, n);
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

void select_sort(int array[], int n) {
	int k = 0;
	for (int i = 1; i < n; ++i) {
		k = i;
		for (int j = k + 1; j <= n; ++j) {
			if (array[j] < array[k]) {
				k = j;
			}
		}
		if (i != k) 
		{
			array[i] = array[i] ^ array[k];
			array[k] = array[i] ^ array[k];
			array[i] = array[i] ^ array[k];
		}
		printf("第 %d 次排序结果：\n", i);
		for (int x = 1; x <= n; ++x) {
			printf("%d ", array[x]);
		}
		cout << endl;
	}
}

void sift_down(int array[], int start, int end) {
	int i = start;
	int j = start * 2;
	while (j <= end) {
		if (j + 1 <= end && array[j + 1] > array[j])
			j += 1;
		if (array[j] <= array[i])
			return;
		array[j] = array[j] ^ array[i];
		array[i] = array[j] ^ array[i];
		array[j] = array[j] ^ array[i];
		i = j;
		j *= 2;
	}
}
void heap_sort(int array[], int n) {
	for (int i = n / 2; i >= 1; --i) 
	{
		sift_down(array, i, n);
	}
	printf("\n初始堆：\n");
	for (int i = 1; i <= n; ++i) {
		printf("%d ", array[i]);
	}
	cout << endl;
	int count = 1;
	for (int i = n; i > 1; --i) {
		array[1] = array[1] ^ array[i];
		array[i] = array[1] ^ array[i];
		array[1] = array[1] ^ array[i];
		sift_down(array, 1, i - 1);
		printf("\n第 %d 次重建堆:", count++);
		for (int j = 1; j <= n; ++j) {
			printf("%d ", array[j]);
		}
		cout << endl;
	}
}

void merge_r(int array[], int start, int mid, int end) {
	int result[100];
	int i, j, k;
	i = start;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= end) {
		if (array[i] > array[j])
			result[k++] = array[j++];
		else
			result[k++] = array[i++];
	}
	while (i <= mid)
		result[k++] = array[i++];
	while (j <= end)
		result[k++] = array[j++];
	for (i = 0; i < k; ++i)
		array[start + i] = result[i];
}
void merge_sort_in_r(int array[], int start, int end) {
	if (start < end) {
		int mid = start + (end - start) / 2;
		merge_sort_in_r(array, start, mid);
		merge_sort_in_r(array, mid + 1, end);
		merge_r(array, start, mid, end);
	}
}
void merge_sort_r(int array[], int n) {
	merge_sort_in_r(array, 1, n);
}

void merge(int array[], int l_start, int r_start, int len, int n) {
	int l_len, r_len;
	if (r_start + len -1 > n) { //左长右短
		l_len = len;
		r_len = n - r_start + 1;
	}
	else {
		l_len = r_len = len;
	}
	printf("左半部：");
	for (int i = l_start; i < l_start + l_len; ++i) {
		printf("%d ", array[i]);
	}
	cout << endl;
	printf("右半部：");
	for (int i = r_start; i < r_start + r_len; ++i) {
		printf("%d ", array[i]);
	}
	cout << endl;
	int result[100];
	int i, j, k;
	i = l_start;
	j = r_start;
	k = 0;
	while (i < l_start + l_len && j < r_start + r_len) {
		if (array[i] > array[j])
			result[k++] = array[j++];
		else
			result[k++] = array[i++];
	}
	while (i < l_start + l_len)
		result[k++] = array[i++];
	while (j < r_start + r_len)
		result[k++] = array[j++];
	for (i = 0; i < k; ++i)
		array[l_start + i] = result[i];
}

void merge_sort(int array[], int n) {
	int step = 1;
	int count = 1;
	while (step <= n) {
		for (int i = 1; i <= n - step; i += 2 * step) {
			merge(array, i, i + step, step, n);
		}
		printf("\n第 %d 次归并:",count++);
		for (int j = 1; j <= n; ++j) {
			printf("%d ", array[j]);
		}
		cout << endl;
		step *= 2;
	}
}