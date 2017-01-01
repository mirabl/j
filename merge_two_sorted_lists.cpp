/*
https://leetcode.com/problems/merge-two-sorted-lists/
*/
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v): val(v), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode dummy(0);
	ListNode *p = &dummy;
	ListNode *l1p = l1;
	ListNode *l2p = l2;
	while (l1p != NULL || l2p != NULL) {
		ListNode **a;
		if (l1p == NULL || (l2p != NULL && l1p->val > l2p->val)) {
			a = &l2p;
		} else {
			a = &l1p;
		}
		p->next = *a;
		*a = (*a)->next;
		p = p->next;
	}
	return dummy.next;
}	

void print_list(ListNode *n) {
	ListNode *p = n;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
}

int main() {
	ListNode A1(1);
	ListNode A2(4);
	ListNode A3(8);
	ListNode A4(15);
	ListNode B1(2);
	ListNode B2(3);
	ListNode B3(10);
	ListNode B4(19);
	ListNode B5(21);
	A1.next = &A2;
	A2.next = &A3;
	A3.next = &A4;
	B1.next = &B2;
	B2.next = &B3;
	B3.next = &B4;
	B4.next = &B5;

	ListNode *r = mergeTwoLists(&A1, &B1);
	print_list(r);
	cout << endl;
}