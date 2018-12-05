class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.rbegin(), deck.rend());
        deque<int> res;
        for (auto x: deck) {
            if (!res.empty()) {
                int y = res.back();
                res.pop_back();
                res.push_front(y);
            }
            res.push_front(x);
        }
        
        vector<int> r(res.begin(), res.end());
        return r;
    }
};
