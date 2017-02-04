class Solution {
public:
    vector<int> A;
    vector<int> pos;
    Solution(vector<int> nums) {
        A = vector<int>(nums.begin(), nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return A;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        const int n = int(A.size());
        vector<int> res(A);
        for (int i = 0; i < n; i++) {
            int r = random() % (n - i);
            swap(res[n - 1 - i], res[r]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */