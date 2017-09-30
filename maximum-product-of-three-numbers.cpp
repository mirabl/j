class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n - 1] * max(nums[0] * nums[1], nums[n - 3] * nums[n - 2]);
    }
};

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int> qm;
        priority_queue<int> qM;
        for (int x: nums) {
            qm.push(- x);
            qM.push(x);
        }
        int max_val = qM.top();
        qM.pop();
        int v1 = qM.top();
        qM.pop();
        v1 *= qM.top();
        int v2 = - qm.top();
        qm.pop();
        v2 *= - qm.top();
        return max_val * max(v1, v2);;
    }
};

