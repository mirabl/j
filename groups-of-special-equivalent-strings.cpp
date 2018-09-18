class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<map<int, int>> S;
        
        for (auto s: A) {
            map<int, int> F;
            for (int i = 0; i < s.size(); i++) {
                F[s[i]] += 1 + (i % 2 == 0 ? 0 : 10000);
            }
            S.insert(F);
        }
        
        return S.size();
    }
};
