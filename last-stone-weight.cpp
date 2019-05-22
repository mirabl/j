class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> Q;
        for (auto s: stones) {
            Q.push(s);
        }
        
        while (Q.size() > 1) {
            auto x = Q.top();
            Q.pop();
            auto y = Q.top();
            Q.pop();
            if (x > y) {
                swap(x, y);
            }
            int t = y - x;
            if (t > 0) {
                Q.push(t);
            }
        }
        
        return Q.empty() ? 0 : Q.top();
        
    }
};
