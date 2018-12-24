/*
https://leetcode.com/problems/delete-node-in-a-linked-list/
237. Delete Node in a Linked List   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 124387
Total Submissions: 274754
Difficulty: Easy
Contributors: Admin
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
alias a='g++ -Wall -std=c++11 delete_node_in_a_linked_list.cpp && ./a.out'
*/
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int v): val(v), next(NULL) {}
};

void deleteNode(ListNode* node) {
	ListNode* p = node;
	while (p != NULL) {
		p->val = p->next->val;
		if (p->next->next == NULL) {
			p->next = NULL;
		}
		p = p->next;
	}
}

void print_list(ListNode *node) {
	ListNode *n = node;
	while (n != NULL) {
		cout << n->val << " ";
		n = n->next;
	}
	cout << endl;
}

int main() {
	ListNode n1(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;


	print_list(&n1);
	deleteNode(&n2);
	print_list(&n1);
}