/*
structure
insert
find
deleteNode
reverse

Linked List:
Reverse a singly linked list
Delete/Insert a node in a linked list
Detect if there is a cycle in the list and return its starting point
Merge two sorted lists
Split a list into two lists one has even indexes other has odd indexes

*/
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v): val(v), next(NULL) { }
};

ListNode* insert(ListNode *head, int v) {
	ListNode *n = new ListNode(v);
	if (head == NULL) {
		head = n;
	} else {
		ListNode *p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = n;
	}
	return head;
}

ListNode* find(ListNode *head, int v) {
	ListNode *p = head;
	while (p != NULL && p->val != v) {
		p = p->next;
	}
	return p;
}

ListNode* deleteNode(ListNode *head, ListNode *n) {
	// Memory?
	if (n == head) {
		return n->next;
	}
	ListNode *p = head;
	while (p->next != NULL) {
		if (p->next == n) {
			p->next = n->next;
			return head;
		}
		p = p->next;
	}
	return NULL;  // Never reached.
}

ListNode* appendNode(ListNode* h, ListNode *n) {
	if (h == NULL) {
		return n;
	}
	ListNode *p = h;
	while (p->next) {
		p = p->next;
	}
	p->next = n;
	return h;
}

// Rewrite without traversing each time?
ListNode* reverse(ListNode *head) {
	if (head == NULL) {
		return NULL;
	}
	ListNode *n = reverse(head->next);
	head->next = NULL;
	n = appendNode(n, head);
	return n;
}

/* *********************************** */

void print_list(ListNode *n) {
	ListNode *p = n;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
}


int main() {
	ListNode *h;
	h = insert(NULL, 0);
	h = insert(h, 1);
	h = insert(h, 2);
	print_list(h);
	cout << " == 0 1 2" << endl << endl;

	cout << find(h, 3) << " == 0 " << endl;
	cout << find(h, 1)->val << " == 1 " << endl;
	cout << find(h, 0)->val << " == 0 " << endl;
	cout << find(h, 2)->val << " == 2 " << endl;

	h = deleteNode(h, h);
	print_list(h);
	cout << " == 1 2" << endl << endl;
	h = deleteNode(h, h->next);
	print_list(h);
	cout << " == 1" << endl << endl;

	h = deleteNode(h, h);
	h = insert(h, 0);
	h = insert(h, 1);
	h = insert(h, 2);
	h = reverse(h);
	print_list(h);
	cout << " == 2 1 0" << endl << endl;

}