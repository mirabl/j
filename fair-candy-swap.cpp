class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sA = 0;
        for (auto x: A) {
            sA += x;
        }
        set<int> Bs;
        int sB = 0;
        for (auto x: B) {
            sB += x;
            Bs.insert(x);
        }
        int half = (sA + sB) / 2;
    
        for (auto x: A) {
            int d = - (sA - x - half);
            if (Bs.count(d) == 1) {
                return {x, d};
            }
        }
        return {-1, -1};
    }
};
