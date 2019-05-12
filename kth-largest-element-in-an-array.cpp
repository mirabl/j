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

class Solution {
public:
    int partition(vector<int>& A, int lo, int hi) {
        if (lo == hi) {
            return 0;
        }
        
        int pivot = A[hi];
        int j = lo;
        for (int i = lo; i < hi; i++) {
            if (A[i] <= pivot) {
                swap(A[i], A[j]);
                j++;
            }
        }
        swap(A[hi], A[j]);

        return j - lo;
    }

    int qs(vector<int>& A, int lo, int hi, int k) {
        int i = partition(A, lo, hi);
        if (i == k) {
            return A[lo + i];
        } else if (i < k) {
            return qs(A, lo + i + 1, hi, k - i - 1);
        } else {
            return qs(A, lo, lo + i - 1, k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = int(nums.size());
        return qs(nums, 0, n - 1, n - k);
    }
};
