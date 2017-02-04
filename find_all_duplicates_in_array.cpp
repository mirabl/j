class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> A(nums);
        vector<int> res;
        for (int x: A) {
            x = abs(x);
            if (A[x - 1] < 0) {
                res.push_back(x);
            }
            A[x - 1] = - A[x - 1];
        }
        return res;
    }
};