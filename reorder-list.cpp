/*
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
    int listSize(ListNode *p) {
        int i = 0;
        while (p != NULL) {
            i++;
            p = p->next;
        }
        return i;
    }
    
    void reverse_aux(ListNode* h, ListNode** nhead, ListNode **ntail) {
        if (!h->next) {
            *nhead = h;
            *ntail = h;
            return;
        }
        ListNode *nh, *nt;
        reverse_aux(h->next, &nh, &nt);
        h->next = NULL;
        nt->next = h;
        *nhead = nh;
        *ntail = h;
    }
    
    ListNode* reverse(ListNode *h) {
        ListNode *nhead, *ntail;
        reverse_aux(h, &nhead, &ntail);
        return nhead;
    }
    
    void reorderList(ListNode* head) {
        int l = listSize(head);
        if (l <= 2) {
            return;
        }
        ListNode *p = head;
        for (int i = 0; i < ((l + 1) / 2) - 1; i++) {
            p = p->next;
        }
        ListNode* q = p->next;
        p->next = NULL;
        q = reverse(q);
        p = head;
        while (p != NULL) {
            ListNode *tmp = p->next;
            p->next = q;
            p = tmp;
            if (q) {
                tmp = q->next;
                q->next = p;
                q = tmp;
            }
        }
    }
};