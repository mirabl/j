/*
https://leetcode.com/problems/odd-even-linked-list/
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return head;
        }
        ListNode *oHead = head;
        ListNode *oTail = head;
        ListNode *eHead = head->next;
        ListNode *eTail = head->next;
        ListNode *p = head->next->next;
        while (p != NULL) {
            oTail->next = p;
            oTail = oTail->next;
            eTail->next = p->next;
            eTail = eTail->next;
            if (p->next == NULL) {
                break;
            }
            p = p->next->next;
        }
        oTail->next = eHead;
        return oHead;
    }
};