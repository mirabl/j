// better: reservoir sampling

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    int size = 0;
    ListNode *head;
    Solution(ListNode* h) {
        head = h;
        ListNode *p = head;
        while (p) {
            p = p->next;
            size++;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int e = rand() % size;
        ListNode *p = head;
        for (int i = 0; i < e; i++) {
            p = p->next;
        }
        return p->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */