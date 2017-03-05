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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *s = &dummy;
        for (int i = 0; i < m - 1; i++) {
            s = s->next;
        }
        ListNode *nh = NULL;
        ListNode *p = s->next;
        for (int i = m; i <= n; i++) {
            ListNode *q = p->next;
            p->next = nh;
            nh = p;
            p = q;
        }
        s->next->next = p;
        s->next = nh;
        return dummy.next;
    }
};