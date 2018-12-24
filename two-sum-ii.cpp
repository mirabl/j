class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int hi = int(numbers.size()) - 1;
        int lo = 0;
        while (true) {
            int t = numbers[hi] + numbers[lo];
            if (t == target) {
                return vector<int>{lo + 1, hi + 1};
            } else if (t < target) {
                lo++;
            } else {
                hi--;
            }
        }
    }
};