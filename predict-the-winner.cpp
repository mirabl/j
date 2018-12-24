class Solution {
public:
    map<pair<int, int>, int> maxScore;
    vector<int> sums;
    
    int rec(vector<int>& nums, int i, int j) {
        if (i == j) {
            return nums[i];
        } else if (maxScore.count({i, j}) == 0) {
            maxScore[{i, j}] = sums[j + 1] - sums[i] - min(rec(nums, i + 1, j), rec(nums, i, j - 1));
        }
        return maxScore[{i, j}];
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        sums.push_back(0);
        for (auto x: nums) {
            sums.push_back(x + sums.back());
        }
        
        int m = rec(nums, 0, int(nums.size()) - 1);
        return m >= sums[int(nums.size())] - m;
    }
};

class Solution {
public:
    map<pair<int, int>, int> maxScore;
    vector<int> sums;

    bool PredictTheWinner(vector<int>& nums) {
        sums.push_back(0);
        for (auto x: nums) {
            sums.push_back(x + sums.back());
        }
        const int n = int(nums.size());
        vector<vector<int>> A(n, vector<int>(n, 0));
        for (int k = 0; k < n; k++) {
            A[k][k] = nums[k];
        }
        for (int k = 1; k < n; k++) {
            for (int l = 0; l < n - k; l++) {
                int r = l;
                int c = k + l;
                A[r][c] = sums[c + 1] - sums[r] - min(A[r + 1][c], A[r][c - 1]);
            }
        }
        
        return 2 * A[0][n - 1] >= sums[int(nums.size())];
    }
};