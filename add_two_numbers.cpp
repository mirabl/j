/*
* g++ add_two_numbers.cpp 
* alias a='g++ add_two_numbers.cpp && ./a.out '
* alias b='a && valgrind --leak-check=full ./a.out '
* https://leetcode.com/problems/add-two-numbers/
*/
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v) : val(v), next(NULL) { }
};

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode* sum_head = NULL;
	ListNode *sum_tail = NULL;

	ListNode *p1 = l1;
	ListNode *p2 = l2;
	int carry = 0;

	while (p1 != NULL || p2 != NULL) {
		int d = carry;
		if (p1 != NULL) {
			d += p1->val;
			p1 = p1->next;
		}
		if (p2 != NULL) {
			d += p2->val;
			p2 = p2->next;
		}
		carry = (int) d / 10;
		ListNode *sum_digit = new ListNode(d % 10);
		if (sum_head == NULL) {
			sum_head = sum_digit;
		}
		if (sum_tail != NULL) {
			sum_tail->next = sum_digit;
		}
		sum_tail = sum_digit;
	}
	if (carry != 0) {
		sum_tail->next = new ListNode(carry);
		sum_tail = sum_tail->next;
	}
	return sum_head;
}

void freeList(ListNode *p) {
	if (p->next != NULL) {
		freeList(p->next);
	}
	delete(p);
}

ListNode *buildListFromNumber(int num) {
	ListNode *head = new ListNode(num % 10);
	num = num / 10;
	ListNode *tail = head;
	while (num != 0) {
		ListNode *new_node = new ListNode(num % 10);
		tail->next = new_node;
		tail = new_node;
		num = num / 10;
	}

	return head;
}

int convertListToNumber(ListNode *head) {
	int num = 0;
	ListNode *p = head;
	int mult = 1;
	while (p != NULL) {
		num = num + (p->val) * mult;
		mult *= 10;
		p = p->next;
	}
	return num;
}

void printList(ListNode *head) {
	ListNode *p;
	p = head;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

int add_nums(int x, int y) {
	ListNode *x1 = buildListFromNumber(x);
	ListNode *y1 = buildListFromNumber(y);
	ListNode *res1 = addTwoNumbers(x1, y1);
	int res_int = convertListToNumber(res1);

	freeList(res1);
	freeList(x1);
	freeList(y1);
	return res_int;
}

void test() {
	int N = 1<<14;
	for (int i = 0; i < N; ++i) {
		int rand_max = 1<<30;
		int x = rand() % rand_max;
		int y = rand() % rand_max;
		int z = add_nums(x, y);
		assert(x+y == z);
	}
}

int main() {

	cout << add_nums(342, 465) << endl;
	cout << add_nums(10, 2) << endl;
	cout << add_nums(16, 7) << endl;
	cout << add_nums(6, 7) << endl;
	cout << add_nums(19, 18) << endl;

	test();

	return 0;
}