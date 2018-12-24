/*
https://leetcode.com/problems/kth-largest-element-in-an-array/
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> PQ;
        for (int n: nums) {
            if (int(PQ.size()) < k) {
                PQ.push(- n);
            } else {
                if (PQ.top() > - n) {
                    PQ.pop();
                    PQ.push(- n);
                }
            }
        }
        return - PQ.top();
    }
};