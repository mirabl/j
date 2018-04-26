// contestclass Solution {public:    vector<int> findErrorNums(vector<int>& nums) {        int n = nums.size();        map<int, int> M;        for (auto x: nums) {            M[x]++;        }        int dup = -1;        int miss = -1;        for (int x = 1; x <= n; x++) {            if (M[x] == 0) {                miss = x;            }            if (M[x] == 2) {                dup = x;            }        }        return {dup, miss};    }};// contest
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        map<int, int> M;
        for (auto x: nums) {
            M[x]++;
        }
        int dup = -1;
        int miss = -1;
        for (int x = 1; x <= n; x++) {
            if (M[x] == 0) {
                miss = x;
            }
            if (M[x] == 2) {
                dup = x;
            }
        }
        return {dup, miss};
    }
};
