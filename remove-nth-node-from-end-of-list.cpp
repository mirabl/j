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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        ListNode *q = &dummy;
        for (int i = 0; i < n; i++) {
            p = p->next;
        }
        while (p->next) {
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;
        return dummy.next;
    }
};