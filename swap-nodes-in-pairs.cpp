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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        while (p->next && p->next->next) {
            ListNode *q = p->next;
            ListNode *r = q->next;
            ListNode *s = r->next;
            p->next = r;
            r->next = q;
            q->next = s;
            p = q;
        }
        return dummy.next;
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        while (p->next && p->next->next) {
            ListNode *r = p->next->next;
            ListNode *s = r->next;
            p->next->next->next = p->next;
            p->next->next = s;
            p->next = r;
            p = p->next->next;
        }
        return dummy.next;
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *res = head->next;
        head->next = swapPairs(res->next);
        res->next = head;
        return res;
    }
};
