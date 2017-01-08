/*
https://leetcode.com/problems/longest-repeating-character-replacement/
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = int(s.size());
        int res = 0;
        int start = 0;
        int maxf = 0;
        unordered_map<char, int> F;
        for (int end = 0; end < n; ++end) {
            F[s[end]]++;
            maxf = max(maxf, F[s[end]]);
            if (maxf < (end - start + 1 - k)) {
                F[s[start]]--;  // Trick: here we don't need to keep maxf accurate. Otherwise, use priority queue.
                start++;
            }
            res = max(res, end - start + 1);
        }
        return res;
    }
};