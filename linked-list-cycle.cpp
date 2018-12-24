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
        set<ListNode*> S;
        ListNode *p = head;
        while (p != NULL) {
            if (S.count(p) == 1) {
                return true;
            }
            S.insert(p);
            p = p->next;
        }
        return false;
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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }
        ListNode *p = head->next;
        ListNode *q = head;
        while (p && p->next) {
            if (p == q) {
                return true;
            }
            p = p->next->next;
            q = q->next;
        }
        return false;
    }
};/**
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
