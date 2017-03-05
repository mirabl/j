class Solution {
public:
    int lookForClosest(vector<int>& A, int t, int lo) {
        int hi = A.size() - 1;
        while (lo < hi - 1) {
            int mid = lo + (hi - lo) / 2;
            if (A[mid] == t) {
                return mid;
            } else if (A[mid] < t) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return abs(t - A[lo]) < abs(A[hi] - t) ?  lo : hi;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        int u = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < N - 2; i++) {
            int x = nums[i];
            for (int j = i + 1; j < N - 1; j++) {
                int y = nums[j];
                int z = nums[lookForClosest(nums, target - x - y, j + 1)];
                if (abs(x + y + z - target) < abs(u - target)) {
                    u = x + y + z;
                }
            }
        }
        return u;
    }
};

// better O(n^2)
// https://discuss.leetcode.com/topic/5192/java-solution-with-o-n2-for-reference