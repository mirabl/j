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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        
        ListNode *last = NULL;
        while (true) {
            ListNode *p = head;
            ListNode *q = head;
            if (p->next == last) {
                break;
            }
            while (p->next != last) {
                p = p->next;
            }
            p->next = q;
            head = head->next;
            q->next = last;
            last = q;
            
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
    ListNode* reverseList(ListNode* head) {
        ListNode *last = NULL;
        while (head && head->next != last) {
            ListNode *p = head;
            ListNode *q = head;
            while (p->next != last) {
                p = p->next;
            }
            p->next = q;
            head = head->next;
            q->next = last;
            last = q;
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
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return NULL;
        }
        ListNode *p = head;
        ListNode *q = head->next;
        head->next = NULL;
        while (q) {
            ListNode *r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        return p;
    }
};

