/*
https://leetcode.com/problems/partition-list/
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
    ListNode* partition(ListNode* head, int x) {
        if(!head) {
            return NULL;
        }
        ListNode A(0);
        ListNode B(0);
        ListNode *Aend = &A;
        ListNode *Bend = &B;
        ListNode *p = head;

        while (p) {
            if (p->val < x) {
                Aend->next = p;
                Aend = p;
            } else {
                Bend->next = p;
                Bend = p;
            }
            p = p->next;
        }
        Bend->next = NULL;
        Aend->next = B.next;
        return A.next;
    }
};