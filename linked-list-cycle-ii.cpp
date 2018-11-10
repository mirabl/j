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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> M;
        ListNode *p = head;
        while (p) {
            if (M.count(p) == 1) {
                return p;
            }
            M.insert(p);
            p = p->next;
        }
        return NULL;
    }


    ListNode *detectCycle2(ListNode *head) {
        if (!head) {
            return NULL;
        }
        ListNode *p = head->next;
        ListNode *q = head;
        while (p && p->next && p != q) {
            p = p->next->next;
            q = q->next;
        }
        if (p != q) {
            return NULL;
        }
        int c = 0;
        do {
            q = q->next;
            c++;
        } while (q != p);
        p = head;
        for (int i = 0; i < c; i++) {
            p = p->next;
        }
        q = head;
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};

// better: https://discuss.leetcode.com/topic/5284/concise-o-n-solution-by-using-c-with-detailed-alogrithm-description/2

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
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return NULL;
        }
        ListNode *p = head;
        ListNode *q = head;
        while (p && p->next) {
            p = p->next->next;
            q = q->next;
            if (p == q) {
                p = head;
                while (p != q) {
                    p = p->next;
                    q = q->next;
                }
                return p;
            }
        } 
        return NULL;
    }
};

// 
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
    ListNode *detectCycle(ListNode *head) {
        auto p = head;
        auto q = head;
        while (q && q->next) {
            p = p->next;
            q = q->next->next;
            if (p == q) {
                p = head;
                while (p != q) {
                    p = p->next;
                    q = q->next;
                }
                return p;
            }
        }
        return NULL;
    }
};
