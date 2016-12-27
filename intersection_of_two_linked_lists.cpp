/*
https://leetcode.com/problems/intersection-of-two-linked-lists/
160. Intersection of Two Linked Lists   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 104941
Total Submissions: 350009
Difficulty: Easy
Contributors: Admin
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.

alias a='g++ -g -Wall -std=c++11 intersection_of_two_linked_lists.cpp && ./a.out'
*/
#include <iostream>
#include <string>

using namespace std;

struct ListNode {
	string val;
	ListNode *next;
	ListNode(string s): val(s), next(NULL) { }
};

ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
	ListNode *p = headA;
	int lenA = 0;
	while (p != NULL) {
		lenA++;
		p = p->next;
	}
	p = headB;
	int lenB = 0;
	while (p != NULL) {
		lenB++;
		p = p->next;
	}

	ListNode *pLong;
	ListNode *pShort;

	int offset;
	if (lenA >= lenB) {
		offset = lenA - lenB;
		pLong = headA;
		pShort = headB;
	} else if (lenA < lenB) {
		offset = lenB - lenA;
		pLong = headB;
		pShort = headA;
	}

	while (offset > 0) {
		pLong = pLong->next;
		--offset;
	}

	while (pLong != NULL && pShort != NULL) {
		if (pLong == pShort) {
			return pLong;
		}
		pLong = pLong->next;
		pShort = pShort->next;
	}

	return NULL;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	ListNode *pA = headA;
	ListNode *pB = headB;

	ListNode *pLong = NULL;
	ListNode *pShort = NULL;

	while (pA != NULL || pB != NULL) {
		if (pA != NULL) {
			pA = pA->next;
		} else {
			if (pLong == NULL) {
				pLong = headB;
				pShort = headA;
			}
		}
		if (pB != NULL) {
			pB = pB->next;
		} else {
			if (pLong == NULL) {
				pLong = headA;
				pShort = headB;
			}
		}
		if (pLong != NULL) {
			pLong = pLong->next;
		}
	}

	if (pLong == NULL) {
		pLong = headA;
		pShort = headB;
	}

	while (pLong != NULL && pShort != NULL) {
		if (pLong == pShort) {
			return pLong;
		}
		pLong = pLong->next;
		pShort = pShort->next;
	}
	return NULL;
}

/*
// https://discuss.leetcode.com/topic/38444/simple-c-solution-5-lines
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *cur1 = headA, *cur2 = headB;
    while(cur1 != cur2){
        cur1 = cur1?cur1->next:headB;
        cur2 = cur2?cur2->next:headA;
    }
    return cur1;
}
*/

int main() {
	ListNode a1("a1");
	ListNode a2("a2");
	ListNode c1("c1");
	ListNode c2("c2");
	ListNode c3("c3");
	ListNode b1("b1");
	ListNode b2("b2");
	ListNode b3("b3");

	a1.next = &a2;
	a2.next = &c1;
	c1.next = &c2;
	c2.next = &c3;
	b1.next = &b2;
	b2.next = &b3;
	b3.next = &c1;

	ListNode *intersection = getIntersectionNode(&a1, &b1);
	cout << intersection->val << endl;

cout << "--" << endl;
	b3.next = NULL;
	// intersection = getIntersectionNode(NULL, NULL);
	intersection = getIntersectionNode(&a1, &a1);
	cout << (intersection ? intersection->val : "NULL") << endl;


}