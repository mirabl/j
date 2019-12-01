/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }
        ListNode p = head;
        ListNode q = head;
        while (p != null) {
            p = p.next != null ? p.next.next : null;
            q = q.next;
        }
        
        ListNode nh = q;
        p = q.next;
        nh.next = null;
        while (p != null) {
            ListNode r = p.next;
            p.next = nh;
            nh = p;
            p = r;
        }
        
        p = head;
        q = nh;
        while (q != null) {
            if (p.val != q.val) {
                return false;
            }
            p = p.next;
            q = q.next;
        }
        
        return true;       
    }
}

