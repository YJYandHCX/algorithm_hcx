// 基数排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

/*双循环链表结构的定义*/
typedef struct _doubleLinkList {
	int val;
	struct _doubleLinkList* pre;
	struct _doubleLinkList* next;
}doubleLinkList;

//取下并删除双循环链表的第一个元素
//输入：链表头节点的指针L
//输出：被取下元素的指针，及链表L
doubleLinkList* del_entry(doubleLinkList* L) {
	doubleLinkList *p;
	p = L->next;
	if (p != L) {
		L->next = p->next;
		p->next->pre = L;
	}
	else {
		p = NULL;
	}
	return p;
}

//把一个元素插入双循环链表的表尾
//输入：双循环链表L的头节点指针，被插入的节点指针
//输出：链表L
void add_entry(doubleLinkList* L, doubleLinkList* p) {
	p->pre = L->pre;
	L->pre->next = p;
	L->pre = p;
	p->next = L;
}

//取p所指向关键字的第i位数字（最低位为第0位）
//输入指针p和第i位
//输出第i位数字
int get_digital(doubleLinkList* p, int i) {
	int key = p->val;
	if (i != 0) {
		key = key / pow(10, i);
	}
	key = key % 10;
	return key;
}

//将链表L1的所有元素附加到链表L的尾端
//输入链表L和L1的头节点指针
//输出链表L
void append(doubleLinkList* L, doubleLinkList* L1) {
	if (L1->next != L1) {
		L1->next->pre = L->pre;
		L->pre->next = L1->next;
		L1->pre->next = L;
		L->pre = L1->pre;
	}
}

//基数排序
//输入：存放元素的链表L的头节点，关键字的数字的位数K
//输出：按递增顺序排放的链表L
void radix_sort(int k, doubleLinkList* head) {
	doubleLinkList* Lhead[10], * p;
	int i, j;
	for (i = 0; i < 10; i++) {
		Lhead[i] = new doubleLinkList;
	}
	for( i = 0; i < k; i++) {
		for (j = 0; j < 10; j++) {
			Lhead[j]->pre = Lhead[j]->next = Lhead[j];
		}
		while (head->next != head) {
			p = del_entry(head);//取下链表的第一个元素，并将其从链表中删除；
			j = get_digital(p, i);//将p指向的关键字取第i位数字；
			add_entry(Lhead[j], p);//将p加到Lhead[j]的尾部；	
		}
		for (j = 0; j < 10; j++) {
			append(head, Lhead[j]);//将10个链表的元素链接到L，尾插法；
		}
	}
	for (int i = 0; i < 10; i++) {
		delete(Lhead[i]);
	}
	
}




int main()
{
	/*以头插法初始化双向循环链表*/
	doubleLinkList* head, * node;
	head = new doubleLinkList;
	head->pre = head;
	head->next = head;//构建头节点；
	cout << "请输入，以0结尾" << endl;
	int i;
	cin >> i;
	while (i != 0) {
		node = new doubleLinkList;
		node->val = i;
		node->next = head->next;
		if (head->next != NULL) {//以头插法初始化双向循环链表；
			head->next->pre = node;
		}
		head->next = node;
		node->pre = head;
		cin >> i;
	}
	radix_sort(3,head);
	/*输出*/
	doubleLinkList* p = head;
	while (p->next != head) {
		cout << p->next->val << " ";
		p = p->next;
		
	}
	cout << "---------------";
	doubleLinkList* q = head;
	while (q->pre != head)
	{
		cout << q->pre->val << " ";
		q = q->pre;
	}
	system("pause");
}

