

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v): val(v), next(NULL) { }
};

ListNode* insert(ListNode *head, int val) {
	ListNode dummy(0);
	dummy.next = head;
	ListNode *p = &dummy;
	while (p->next) {
		p = p->next;
	}
	p->next = new ListNode(val);
	return dummy.next;
}

ListNode* find(ListNode *head, int v) {
	ListNode *p = head;
	while (p && p->val != v) {
		p = p->next;
	}
	return p;
}

ListNode* deleteNode(ListNode *head, ListNode *p) {
	ListNode dummy(0);
	dummy.next = head;
	ListNode *q = &dummy;
	while (q->next != p) {
		q = q->next;
	}
	q->next = q->next->next;
	return dummy.next;
}

ListNode* reverse(ListNode *head) {
	if (!head) {
		return NULL;
	}
	ListNode *nh = head;
	ListNode *p = head->next;
	nh->next = NULL;
	while (p) {
		ListNode *q = p->next;
		p->next = nh;
		nh = p;
		p = q;
	}
	return nh;
}




void print_list(ListNode *n) {
	ListNode *p = n;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
}


int main() {
	ListNode *h;
	cout << "\n\n[insert]" << endl;
	h = insert(NULL, 0);
	h = insert(h, 1);
	h = insert(h, 2);
	print_list(h);
	cout << " == 0 1 2" << endl;

	cout << "\n\n[find]" << endl;

	cout << find(h, 3) << " == 0 " << endl;
	cout << find(h, 1)->val << " == 1 " << endl;
	cout << find(h, 0)->val << " == 0 " << endl;
	cout << find(h, 2)->val << " == 2 " << endl;

	cout << "\n\n[delete]" << endl;

	h = deleteNode(h, h);
	print_list(h);
	cout << " == 1 2" << endl;
	h = deleteNode(h, h->next);
	print_list(h);
	cout << " == 1" << endl;


	cout << "\n\n[reverse]" << endl;

	h = deleteNode(h, h);
	h = insert(h, 0);
	h = insert(h, 1);
	h = insert(h, 2);
	h = reverse(h);
	print_list(h);
	cout << " == 2 1 0" << endl;

}

