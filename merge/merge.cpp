// merge.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
//摘白菜问题
void reap(int b[], int n) {
	int *a = new int(n);
	int i, j, k, s, t;
	s = n;
	k = 3;
	for (i = 0; i < n; i++) {
		a[i] = i + 1;
	}
	j = 0;
	int count = 0;
	while (j < n) {
		t = s; s = 0;
		for (i = 0; i < t; i++) {
			if (--k != 0) {
				a[s++] = a[i];
				count++;
			}
			else {
				b[j++] = a[i];
				k = 3;
			}
		}
	}
	cout << count  << endl;
}
int main()
{
	cout << "输入总的白菜棵树";
	int n;
	cin >> n;
	int* b = new int(n);
	reap(b, n);
	for (int i = 0; i < n; i++) {
		cout << b[i];
	}
	system("pause");
}

