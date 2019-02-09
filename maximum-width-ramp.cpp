class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        /*
        0 1 2 3 4 5
        6 0 8 2 1 5
        
        0 1 2 5 6 8
        1 4 3 5 0 2
        5 5 5 5 2 -1
          
        */
        
        vector<pair<int, int>> B;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            B.push_back({A[i], i});
        }
        sort(B.begin(), B.end());
        
        int ans = 0;
        int v = -1;
        for (int i = n - 2; i >= 0; i--) {
            v = max(v, B[i + 1].second);
            if (v - B[i].second >= 0) {
                ans = max(ans, v - B[i].second);
            }
        }
            
        return ans;
    }
};
