class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> F;
        int m = 0;
        for (int x: nums) {
            F[x]++;
            if (F[x] >= F[m]) {
                m = x;
            }
        }
        return m;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> F;
        const int n = int(nums.size());
        for (int x: nums) {
            F[x]++;
            if (F[x] > n / 2) {
                return x;
            }
        }
        return -1; // Never reached.
    }
};

