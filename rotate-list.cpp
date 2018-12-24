/*
https://leetcode.com/problems/rotate-list/
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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p = head;
        ListNode *last_node = NULL;
        int len = 0;
        while (p) {
            last_node = p;
            p = p->next;
            len++;
        }
        
        if (len < 2 || k % len == 0) {
            return head;
        }
        k = k % len;
        
        p = head;
        for (int i = 0; i < len - k - 1; i++) {
            p = p->next;
        }

        ListNode *nh = p->next;
        p->next = NULL;
        last_node->next = head;
        return nh;
    }
};