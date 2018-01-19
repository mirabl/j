class Solution {
public:
    vector<int> partitionLabels(string S) {
        int maxval = 500 + 1;
        vector<pair<int, int>> pos(27, {maxval, -1});
        for (int i = 0; i < S.size(); i++) {
            if (i < pos[S[i] - 'a'].first) {
                pos[S[i] - 'a'].first = i;
            }
            pos[S[i] - 'a'].second = i;
        }
        sort(pos.begin(), pos.end());

        int current_start = 0;
        int current_end = 0;
        vector<int> res;
        for (int i = 0; i < pos.size() && pos[i].first != maxval; i++) {
            if (current_end < pos[i].first) {
                res.push_back(current_end - current_start + 1);
                current_start = pos[i].first;
            }
            current_end = max(current_end, pos[i].second);
        }
        res.push_back(current_end - current_start + 1);
        return res;   
    }
};

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int maxval = 500 + 1;
        vector<pair<int, int>> pos(26, {maxval, -1});
        for (int i = 0; i < S.size(); i++) {
            auto& p = pos[S[i] - 'a'];
            if (i < p.first) {
                p.first = i;
            }
            p.second = i;
        }
        sort(pos.begin(), pos.end());

        int current_start = 0;
        int current_end = 0;
        vector<int> res;
        for (auto p: pos) {
            if (p.first == maxval) {
                break;
            }
            if (current_end < p.first) {
                res.push_back(current_end - current_start + 1);
                current_start = p.first;
            }
            current_end = max(current_end, p.second);
        }
        res.push_back(current_end - current_start + 1);
        return res;   
    }
};