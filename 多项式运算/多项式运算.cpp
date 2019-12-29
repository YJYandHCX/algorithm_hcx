// 多项式运算.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

float poly(float a[], float x, int n) {
	float res = 0;
	for (int i = 0; i <= n; i++) {
		res = res + a[i] * pow(x, i);
	}
	return res;
}

int main()
{
	int n;
	cout << "请输入多项式的阶数";
	cin >> n;
	float *a = new float[n];
	cout << "请按照阶数从低至高输入n+1个数";
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
	}
	cout << "请输入x";
	float x;
	cin >> x;
	float res = poly(a, x, n);
	cout << res;
	system("PAUSE");
	return 0;
}


