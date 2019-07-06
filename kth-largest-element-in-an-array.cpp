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


class Solution {
public:
    int partition(vector<int>& nums, int lo, int hi) {
        if (lo == hi) {
            return lo;
        }
        int iP = lo;
        for (int i = lo + 1; i <= hi; i++) {
            if (nums[i] < nums[iP]) {
                swap(nums[i], nums[iP + 1]);
                swap(nums[iP + 1], nums[iP]);
                iP++;
            }
        }
        
        return iP;
    }
    
    int qs(vector<int>& nums, int lo, int hi, int k) {
        int iP = partition(nums, lo, hi);
        int kPivot = iP - lo;
        
        if (kPivot == k) {
            return nums[iP];
        } else if (kPivot > k) {
            return qs(nums, lo, iP, k);
        } else {
            return qs(nums, iP + 1, hi, k - kPivot - 1);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        qs(nums, 0, n - 1, n - k);
        return nums[n - k];
    }
};


class Solution {
public:
    int ksma(vector<int>& nums, int lo, int hi, int k) {
        if (lo == hi) {
            return 0;
        }
        /*
         [lo]  [l-1]  [l]        [hi]
                <0    >=         pivot
        */
        int l = lo;
        for (int i = lo; i < hi; i++) {
            if (nums[i] < nums[hi]) {
                swap(nums[i], nums[l]);
                l++;
            }
        }
        swap(nums[hi], nums[l]);

        if (k == l - lo) {
            return k;
        } else if (k < l - lo) {
            return ksma(nums, lo, l - 1, k);
        } else {
            int b = l - lo + 1;
            k -= b;
            lo = l + 1;
            
            return b + ksma(nums, lo, hi, k);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int p = ksma(nums, 0, n - 1, n - k);
        return nums[p];
    }
};
