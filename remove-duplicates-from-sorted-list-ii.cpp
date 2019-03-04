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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy = ListNode(-1);
        dummy.next = head;
        
        ListNode *p = &dummy;
        
        while (p->next) {
            auto q = p->next;
            if (!q->next || q->next->val != q->val) {
                p = p->next;
                continue;
            }
            
            while (q->next && q->next->val == q->val) {
                q = q->next;
            }
            p->next = q->next;
        }
        
        return dummy.next;
    }
};
