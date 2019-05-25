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
    ListNode* middleNode(ListNode* head) {
        if (!head) {
            return NULL;
        }
        
        auto f = head;
        auto s = head;
        while (f && f->next) {
            f = f->next ? f->next->next : NULL;
            s = s->next;
        }
        return s;
    }
};
