
// contest
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> G;
        for (auto x: answers) {
            G[x + 1]++;
        }
        
        int res = 0;
        for (auto kvp: G) {
            int c = kvp.first;
            int x = kvp.second;
            res += c * (1 + ((x - 1) / c)); 
        }
        return res;
    }
};
