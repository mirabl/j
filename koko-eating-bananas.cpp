// https://leetcode.com/contest/weekly-contest-94/problems/koko-eating-bananas/
class Solution {
public:
    int f(int k, vector<int>& piles) {
        int s = 0;
        for (int p: piles) {
            s += (p + k - 1) / k;
        }
        return s;
    }
    
    int minEatingSpeed(vector<int>& piles, int H) {
        int lo = 1;
        int hi = 1000000000;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            // cout << "lo=" << lo << ", mid=" << mid << ", hi=" << hi << endl;
            int s = f(mid, piles);
            
            if (s > H) {
                lo = mid + 1;
            } else if (s <= H) {
                hi = mid;
            }
            
        }
        return lo;
        
    }
};
