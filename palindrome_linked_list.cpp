/*
https://leetcode.com/problems/palindrome-linked-list/
234. Palindrome Linked List   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 80561
Total Submissions: 255816
Difficulty: Easy
Contributors: Admin
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v): val(v), next(NULL) { }
};

void print_list(ListNode *n) {
	ListNode *p = n;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
}

// Could be rewritten.
ListNode* reverseList(ListNode *head) {
	ListNode *p = head;
	ListNode *q = head->next;
	if (q == NULL) {
		return head;
	}

	p->next = NULL;
	ListNode *r = q->next;

	while (true) {
		q->next = p;
		p = q;
		q = r;
		if (q == NULL) {
			break;
		}
		r = q->next;
	}
	return p;
}

bool isPalindrome(ListNode *head) {
	if (head == NULL || head->next == NULL) {
		return true;
	}
	ListNode *p = head;
	int len = 0;
	while (p != NULL) {
		p = p->next;
		len++;
	}
	p = head;
	for (int i = 0; i < (len + 1) / 2; ++i) {
		p = p->next;
	}
	ListNode *p_rev = reverseList(p);
	p = head;

	for (int i = 0; i < len / 2; ++i) {
		if (p->val != p_rev->val) {
			return false;
		}
		p = p->next;
		p_rev = p_rev->next;
	}
	return true;
}

int main() {
	ListNode n0(1);
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(1);
	ListNode n4(1);
	ListNode n5(0);
	// ListNode n6(0);
	n0.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	// n3.next = &n4;
	// n4.next = &n5;
	// n5.next = &n6;

	cout << isPalindrome(&n0) << " 0" << endl;

	// ListNode *p = reverseList(&n0);
	// print_list(p);
	// cout << endl;

}