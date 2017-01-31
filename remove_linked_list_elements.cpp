/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// mem leak

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return NULL;
        }
        if (head->val != val) {
            head->next = removeElements(head->next, val);
            return head;
        } else {
            return removeElements(head->next, val);
        }
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return NULL;
        }
        while (head && head->val == val) {
            head = head->next;
        }
        ListNode *p = head;
        while (p && p->next) {
            if (p->next->val == val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};

