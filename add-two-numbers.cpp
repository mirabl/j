/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode h(0);
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *r = &h;
        int s = 0;
        while (p || q) {
            s += (p ? p->val : 0) + (q ? q->val : 0);
            r->next = new ListNode(s % 10);
            s = s / 10;
            r = r->next;
            p = p ? p->next : NULL;
            q = q ? q->next : NULL;
        }
        if (s != 0) {
            r->next = new ListNode(s);
        }
        return h.next;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rec(ListNode *l1, ListNode *l2, int carry) {
        int s = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        ListNode *n = new ListNode(s % 10);
        if ((l1 && l1->next) || (l2 && l2->next) || s >= 10) {
            n->next = rec(l1 ? l1->next : NULL, l2 ? l2->next : NULL, s / 10);
        }
        return n;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return rec(l1, l2, 0);
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rec(ListNode *l1, ListNode *l2, int carry) {
        int s = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        ListNode *n = new ListNode(s % 10);
        ListNode *p = l1 ? l1->next : NULL;
        ListNode *q = l2 ? l2->next : NULL;
        if (p || q || s >= 10) {
            n->next = rec(p, q, s / 10);
        }
        return n;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return rec(l1, l2, 0);
    }
};

