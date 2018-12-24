/*
https://leetcode.com/problems/maximum-product-of-word-lengths/
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks;
        for (string word: words) {
            int m = 0;
            for (char c: word) {
                m = m | (1 << (c - 'a'));
            }
            masks.push_back(m);
        }
        int n = int(words.size());
        int cur_max = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((masks[i] & masks[j]) == 0) {
                    cur_max = max(cur_max, int(words[i].size() * words[j].size()));
                }
            }
        }
        return cur_max;
    }
};