class Solution {
public:
    vector<int> A;
    vector<int> mapping;
    
    Solution(vector<int> nums) {
        vector<pair<int, int>> V;
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            V.push_back({nums[i], i});
        }
        sort(V.begin(), V.end());
        for (int i = 0; i < N; i++) {
            A.push_back(V[i].first);
            mapping.push_back(V[i].second);
        }
    }
    
    int pick(int target) {
        vector<int>::iterator itA = lower_bound(A.begin(), A.end(), target);
        vector<int>::iterator itB = upper_bound(A.begin(), A.end(), target);
        int m = (itA - A.begin()) + (random() % (itB - itA));
        return mapping[m];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */