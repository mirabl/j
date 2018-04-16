// contest
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
    int numComponents(ListNode* head, vector<int>& G) {
        ListNode *p = head;
        int res = 0;
        set<int> setG(G.begin(), G.end());
        bool inRun = false;
        while (p != NULL) {
            if (setG.count(p->val) == 0) {
                inRun = false;
            } else {
                if (!inRun) {
                    inRun = true;
                    res++;
                }
            }
            p = p->next;
        }
        
        return res;
    }
};