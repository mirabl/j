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
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        
        ListNode *p = head;
        ListNode *q = head->next;
        
        while (true) {
            if (p == q) {
                return true;
            }
            if (!q || !q->next) {
                return false;
            }
            
            p = p->next;
            q = q->next->next;
        }
    }
};
