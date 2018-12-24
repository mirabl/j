/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

19. Remove Nth Node From End of List QuestionEditorial Solution  My Submissions
Total Accepted: 148559
Total Submissions: 465029
Difficulty: Easy
Contributors: Admin
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

alias a='g++ remove_nth_node_from_end_of_list.cpp -Wall -g && ./a.out'


*/
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v): val(v), next(NULL) { }
};

ListNode* removeNthFromEnd(ListNode *head, int n) {
	ListNode* right = head;
	for (int i = 0; i < n; ++i) {
		right = right->next;
	}

	if (right == NULL) {
		return head->next;
	}

	ListNode* left = head;
	while (right->next != NULL) {
		right = right->next;
		left = left->next;
	}
	left->next = left->next->next;

	return head;
}

void printList(ListNode *head) {
	ListNode *p = head;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

int main() {
	ListNode n1 = ListNode(1);
	ListNode n2 = ListNode(2);
	ListNode n3 = ListNode(3);
	ListNode n4 = ListNode(4);
	ListNode n5 = ListNode(5);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	printList(&n1);
	ListNode *r = removeNthFromEnd(&n1, 5);
	printList(r);

	return 0;
}/*
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

19. Remove Nth Node From End of List QuestionEditorial Solution  My Submissions
Total Accepted: 148559
Total Submissions: 465029
Difficulty: Easy
Contributors: Admin
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

alias a='g++ remove_nth_node_from_end_of_list.cpp -Wall -g && ./a.out'


*/
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v): val(v), next(NULL) { }
};

ListNode* removeNthFromEnd(ListNode *head, int n) {
	ListNode* right = head;
	for (int i = 0; i < n; ++i) {
		right = right->next;
	}

	if (right == NULL) {
		return head->next;
	}

	ListNode* left = head;
	while (right->next != NULL) {
		right = right->next;
		left = left->next;
	}
	left->next = left->next->next;

	return head;
}

void printList(ListNode *head) {
	ListNode *p = head;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

int main() {
	ListNode n1 = ListNode(1);
	ListNode n2 = ListNode(2);
	ListNode n3 = ListNode(3);
	ListNode n4 = ListNode(4);
	ListNode n5 = ListNode(5);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	printList(&n1);
	ListNode *r = removeNthFromEnd(&n1, 5);
	printList(r);

	return 0;
}