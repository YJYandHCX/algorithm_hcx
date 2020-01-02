// sort.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
void temp(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
//冒泡排序法
void maopao(int a[], int n) {
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[i] < a[j]) {
				temp(a[i], a[j]);
			}
		}
	}
} 

//改进的冒泡算法
void maopao1(int a[],int n) {
	bool flag = true;
	int k = n - 1;
	while (flag) {
		flag = false;
		k = k - 1;
		for (int i = 0; i <= k; i++) {
			if (a[i] > a[i + 1]) {
				temp(a[i], a[i + 1]);
				flag = 1;
			}
		}
	}

}
//插入法
void insert_sort(int a[], int n) {
	int j,temp;
	for (int i = 1; i < n; i++) {
		temp = a[i];
		j = i - 1;
		while (j >=0 && temp <a[j]) {
				a[j + 1] = a[j];
				j--;
		}
		a[j + 1] = temp;
	}
}//从后往前比较，需用一个temp变量记住啊[i];

//合并排序法
void merge(int a[], int p, int q, int r) {
	int* temp = new int(r - p + 1);
	int i = p, j = q + 1, k = 0;
	while (i <= q && j <= r) {
		if (a[i] < a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
		}
	}
	if (i == q + 1) {
		while (j <= r) {
			temp[k++] = a[j++];
		}
	}
	else {
		while (i <= q) {
			temp[k++] = a[i++];
		}
	}
	k = 0;
	for (int i = p; i <= r; i++) {
		a[i] = temp[k++];
	}
}
void merge_sort(int a[], int n) {
	int s, i, t = 1;//s:被合并序列的大小s;i被合并序列的起始位置i;合并后序列的大小t;
	while (t < n) {//s相当于上一个循环的步长，t相当于当前循环的步长；
		s = t; t = 2 * s; i = 0;
		while (i + t < n) {
			merge(a,i, i + s - 1, i + t - 1);
			i = i + t;
		}
		if (i + s < n) {
			merge(a,i, i + s - 1, n - 1);
		}
	}
} 



int main()
{
    cout << "请输入一个无序数组的元素个数\n"; 
	int n;
	cin >> n;
	cout << "请输入此无序数组\n";
	int* a = new int(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	//maopao(a, n);
	//maopao1(a, n);
	//insert_sort(a, n);
	//merge(a, 0, 1, 1);
	merge_sort(a, n);
	for (int j = 0; j < n; j++) {
		cout << a[j] << " ";
	}
	system("pause");
	
}
