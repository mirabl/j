// https://leetcode.com/problems/advantage-shuffle/description/

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<pair<int, int>> BB;
        for (int i = 0; i < int(B.size()); i++) {
            BB.push_back({B[i], i});
        }
        sort(BB.begin(), BB.end());
        sort(A.begin(), A.end());
        
        int j = 0;
        vector<int> res(A.size());
        stack<int> skipped;
        for (int a: A) {
            if (j == B.size()) {
                break;
            }
            int b = BB[j].first;
            int bidx = BB[j].second;
            
            if (a > b) {
                res[bidx] = a;
                j++;
            } else {
                skipped.push(a);
            }
        }
        
        while (j < BB.size()) {
            int bidx = BB[j].second;
            res[bidx] = skipped.top();
            skipped.pop();
            j++;
        }
        
        return res;
    }
};

