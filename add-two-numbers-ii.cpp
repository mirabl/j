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
    ListNode* rev(ListNode *h) {
        ListNode *p = h;
        ListNode *q = (p ? p->next : NULL);
        p->next = NULL;
        while (q) {
            ListNode *tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        return p;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = rev(l1);
        l2 = rev(l2);

        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *r = NULL;
        int carry = 0;
        while (p || q || carry != 0) {
            int s = (p ? p->val : 0) + (q ? q->val : 0) + carry;
            carry = s / 10;
            ListNode *tmp = new ListNode(s % 10);
            tmp->next = r;
            r = tmp;
            p = (p ? p->next : p);
            q = (q ? q->next : q);
        }
        return r;
    }
};