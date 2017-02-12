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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        dummy.next = NULL;
        ListNode *p = head;
        while (p) {
            ListNode *q = &dummy;
            while (q->next && q->next->val < p->val) {
                q = q->next;
            }
            ListNode *tmp = p->next;
            p->next = q->next;
            q->next = p;
            p = tmp;
        }
        return dummy.next;
    }
};