/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode nh(0);
        RandomListNode h(0);
        h.next = head;
        RandomListNode *p = &h;
        RandomListNode *q = &nh;

        map<RandomListNode*, RandomListNode*> M{{NULL, NULL}};
        
        while (p->next) {
            q->next = new RandomListNode(p->next->label);
            q->next->random = p->next->random;
            M[p->next] = q->next;
            q = q->next;
            p = p->next;
        }
        
        q = &nh;
        while (q) {
            q->random = M[q->random];
            q = q->next;
        }
        
        return nh.next;
        
    }
};

