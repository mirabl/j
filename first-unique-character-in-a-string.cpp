/*
https://leetcode.com/problems/first-unique-character-in-a-string/
387. First Unique Character in a String   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 35496
Total Submissions: 78549
Difficulty: Easy
Contributors: Admin
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
alias a='g++ -Wall -std=c++11 first_unique_character_in_a_string.cpp && ./a.out'
*/
#include <iostream>
#include <map>
#include <set>

using namespace std;

int firstUniqChar(string s) {
	map<char, int> M;
	int n = (int)s.size();
	for (int i = 0; i < n; ++i) {
		++M[s[i]];
	}
	for (int i = 0; i < n; ++i) {
		if (M[s[i]] == 1) {
			return i;
		}
	}
	return -1;
}

int firstUniqChar3(string s) {
	set<char> candidates;
	set<char> excluded;
	int n = (int)s.size();
	for (int i = 0; i < n; ++i) {
		char c = s[i];
		if (excluded.count(c) == 0) {
			if (candidates.count(c) != 0) {
				candidates.erase(c);
				excluded.insert(c);
			} else {
				candidates.insert(c);
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (candidates.count(s[i]) != 0) {
			return i;
		}
	}
	return -1;
}

struct ListNode {
	char val;
	int pos;
	ListNode *prev;
	ListNode *next;
	ListNode(char c, int p): val(c), pos(p), prev(NULL), next(NULL) { }
};

void deleteNode(ListNode **head, ListNode **tail, ListNode *n) {
// cout << "deleting " << n->val << endl;
	if (n->next != NULL) {
		n->next->prev = n->prev;
	}
	if (n->prev != NULL) {
		n->prev->next = n->next;
	}
	if (*head == n) {
		*head = (*head)->next;
	}
	if (*tail == n) {
		*tail = (*tail)->prev;
	}
}

void appendNode(ListNode **head, ListNode **tail, ListNode *n) {
	if (*head == NULL) {
		*head = n;
	}
	if (*tail != NULL) {
		(*tail)->next = n;
		n->prev = *tail;
	}
	*tail = n;
}

void printList(ListNode *n) {
	cout << "\t\t\t\t\t";
	while (n != NULL) {
		cout << n->val << " (";
		cout << (n->prev != NULL ? n->prev->val : '-') << "/";
		cout << (n->next != NULL ? n->next->val : '-') << ") ";
		n = n->next;
	}
	cout << endl;
}

int firstUniqChar2(string s) {
	if (s.empty()) {
		return -1;
	}
	map<char, pair<int, ListNode*> > M;
	ListNode *head = NULL;
	ListNode *tail = NULL;

	int n = (int)s.size();
	for (int i = 0; i < n; ++i) {
		char c = s[i];
// cout << "i=" << i << ", c=" << c << endl;
		if (M.count(c) == 0) { // New candidate.
// cout << "\tadding " << c << endl;
			ListNode *n = new ListNode(c, i);
			appendNode(&head, &tail, n);
			M[c] = pair<int, ListNode*>(0, n);
		} else if (M[c].first == 1) {
			ListNode *n = M[c].second;
			deleteNode(&head, &tail, n);
		}
		++M[c].first;
// printList(head);
	}
	if (head != NULL) {
		return head->pos;
	}
	return -1;
}

int main() {
	cout << firstUniqChar("") << " -1" << endl;
	cout << firstUniqChar("a") << " 0" << endl;
	cout << firstUniqChar("aa") << " -1" << endl;
	cout << firstUniqChar("ab") << " 0" << endl;
	cout << firstUniqChar("baa") << " 0" << endl;
	cout << firstUniqChar("bab") << " 1" << endl;
	cout << firstUniqChar("baba") << " -1" << endl;
	cout << firstUniqChar("babac") << " 4" << endl;
	cout << firstUniqChar("leetcode") << " 0" << endl;
	cout << firstUniqChar("loveleetcode") << " 2" << endl;
	cout << firstUniqChar("aadadaad") << " -1" << endl;
}
