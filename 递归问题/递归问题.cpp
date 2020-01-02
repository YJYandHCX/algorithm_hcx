// 递归问题.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

//汉诺塔算法
//输入金盘个数n,串满金盘的针a，目的针b，辅助针c;
void hanoi(char a,char b ,char c,int n) {
	if (n == 1) cout << a << "->" << b << endl;
	else {
		hanoi(a, c,b, n - 1);
		cout << a << "->" << b << endl;//把最下面的一片金盘从a->b
		hanoi(c, b, a, n - 1);
	}
}
//斐波那契数列
int Fibonacci(int n) {
	if (n == 1 || n == 2) return 1;
	else return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main()
{
	/*cout << "请输入汉诺塔的金盘个数\n";
	int n;
	cin >> n;
	hanoi('a', 'b', 'c', n);*/

	cout << "输入斐波那契数列的n\n";
	int n;
	cin >> n;
	int res = Fibonacci(n);
	cout << res;
	system("pause");
}


