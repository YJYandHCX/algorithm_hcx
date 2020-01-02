// 堆（堆排序）.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
//上移
void sift_up(int H[], int i) {
	bool done = false;
	if (i != 1) {
		while (!done && i != 1) {
			if (H[i] > H[i / 2]) {
				swap(H[i], H[i / 2]);
			}
			else {
				done = true;
			}
			i = i / 2;
		}
	}
}
//下移
void sift_down(int H[], int n, int i) {
	bool done = false;
	if ((2 * i) <= n) {//判断是否存在儿子节点
		while (!done && (i = 2 * i) <= n) {
			if ((i + 1) <= n && H[i + 1] > H[i]) {//找到最大的儿子节点进行交换（若存在）
				i = i + 1;
			}
			if (H[i] > H[i / 2]) {
				swap(H[i], H[i / 2]);
			}
			else {
				done = true;
			}
		}
	}
}
//插入
void insert_dui(int H[], int &n, int x) {
	n = n + 1;
	H[n] = x;
	sift_up(H, n);
}

//删除
void delete_dui(int H[], int& n, int i) {
	int x = H[i];
	int y = H[n];
	n = n - 1;
	if (i <= n) {
		H[i] = y;
		if (y > x) {//H[n]比H[i]大，上移，则说明此数应该往原堆的上方走；反之下移；
			sift_up(H, i);
		}
		else {
			sift_down(H, n, i);
		}
	}
}

//删除关键字最大的元素，并返回最大值
int delete_max(int H[], int& n) {
	int x = H[1];
	H[1] = H[n];
	n = n - 1;
	sift_down(H, n, 1);
	return  x;
}

//堆的建立
void make_head(int A[], int n) {
	A[n] = A[0];
	for (int i = n / 2; i >= 1; i--) {//堆的调整从最后一个非叶子节点开始调整，采取下移操作。
		sift_down(A, n, i);
	}
}

void heat_sort(int A[], int n) {
	make_head(A, n);
	for (int i = n; i > 1; i--) {
		swap(A[1], A[i]);
		sift_down(A, i-1, 1);
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
	//make_head(a, n);
	heat_sort(a, n);
	for (int j = 1; j <= n; j++) {
		cout << a[j] << " ";
	}
	system("pause");
}

