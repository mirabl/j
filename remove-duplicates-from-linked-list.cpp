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
        if (!head || !head->next) {
            return head;
        }
        if (head->val == head->next->val) {
            head->next = head->next->next;
            (void)deleteDuplicates(head);
        } else {
            deleteDuplicates(head->next);
        }
        
        return head;
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head;
        while (p) {
            while (p->next && p->val == p->next->val) {
                p->next = p->next->next;
                // Memory leak.
            }
            p = p->next;
        }
        return head;
    }
};

