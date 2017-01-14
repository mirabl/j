/*
https://leetcode.com/problems/sort-list/
*/
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
    void cutInHalf(ListNode *h, ListNode** right)  {
        if(!h) {
            *right = NULL;
            return;
        }
        ListNode *p1 = h->next;
        ListNode *p2 = h;
        while (p1 && p1->next) {
            p1 = p1->next->next;
            p2 = p2->next;
        }
        *right = p2->next;
        p2->next = NULL;        
    }
    
    ListNode* mergeSortedHalves(ListNode *left, ListNode *right) {
        ListNode dummy(0);
        ListNode* m = &dummy;
        ListNode* l = left;
        ListNode* r = right;
        while (l || r) {
            if (!r || (l && l->val < r->val)) {
                m->next = l;
                l = l->next;
            } else {
                m->next = r;
                r = r->next;
            }
            m = m->next;
        }
        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *right;
        cutInHalf(head, &right);
        return mergeSortedHalves(sortList(head), sortList(right));
    }
};