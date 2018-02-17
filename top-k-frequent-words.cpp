// n log n
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> count;
        for (string word: words) {
            count[word]++;
        }
        vector<pair<int, string>> V;
        for (auto p: count) {
            V.push_back({- p.second, p.first});
        }
        sort(V.begin(), V.end());
        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(V[i].second);
        }
        return res;
    }
};

// n log k with priority queue