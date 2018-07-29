// https://leetcode.com/problems/reordered-power-of-2/description/
class Solution {
public:
    vector<int> digits(int x) {
        vector<int> res;
        while (x != 0) {
            res.push_back(x % 10);
            x /= 10;
        }
        sort(res.begin(), res.end());
        return res;
    }
    
    
    bool reorderedPowerOf2(int N) {
        int M = 1000000000 + 1;
        set<vector<int>> D;
        for (int x = 1; x < M; x *= 2) {
            D.insert(digits(x));
        }
        
        auto digitsN = digits(N);
        return D.count(digitsN) == 1;        
    }
};