/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return NULL;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = dummy.next->next;
        ListNode *q = &dummy;
        while (p && p->next) {
            p = p->next->next;
            q = q->next;
        }
        TreeNode *root = new TreeNode(q->next->val);
        p = q->next;
        q->next = NULL;
        root->left = sortedListToBST(dummy.next);
        q = p->next;
        p->next = NULL;
        root->right = sortedListToBST(q);
        return root;
    }
};