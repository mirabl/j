
// contest
class Solution {
public:
    vector<int> notIn(int a, int b, int N) {
        vector<int> res;
        for (int i = 0; i < N; i++) {
            if (i != a && i != b) {
                res.push_back(i);
            }
        }
        return res;
    }
    
    bool judgePoint24(vector<double>& nums) {
        int N = nums.size();

        if (N == 1) {
            return abs(nums[0] - 24) < 0.00001;
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    continue;
                }
                vector<double> A;
                vector<int> B = notIn(i, j, N);
                for (int k: B) {
                    A.push_back(nums[k]);
                }
                
                vector<double> V{nums[i] + nums[j], nums[i] - nums[j], nums[i] * nums[j]};
                if (nums[j] != 0) {
                    V.push_back(nums[i] / nums[j]);
                }
                
                for (double v: V) {
                    A.push_back(v);
                    if (judgePoint24(A)) {
                        return true;
                    }
                    A.pop_back();
                }
            }
        }
        return false;
    }
    
    bool judgePoint24(vector<int>& nums) {
        vector<double> A;   
        for (auto n: nums) {
            A.push_back(double(n));
        }
        return judgePoint24(A);
    }
};
