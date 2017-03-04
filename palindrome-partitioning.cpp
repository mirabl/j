class Solution {
public:
    bool isPalindrome(string& s, int lo, int hi) {
        return (hi - lo <= 0) || (s[lo] == s[hi] && isPalindrome(s, lo + 1, hi - 1));
    }

    vector<vector<string>> rec(string& s, int lo, map<int, vector<vector<string>>>& memo) {
        if (memo.count(lo) == 0) {
            vector<vector<string>> res;
            for (int i = lo; i < s.size(); i++) {
                if (isPalindrome(s, lo, i)) {
                    vector<vector<string>> tail = rec(s, i + 1, memo);
                    string start = s.substr(lo, i - lo + 1);
                    for (auto& x: tail) {
                        x.insert(x.begin(), start);
                    }
                    res.insert(res.end(), tail.begin(), tail.end());
                }
            }
            memo[lo] = res;
        }
        return memo[lo];
    }

    vector<vector<string>> partition(string s) {
       map<int, vector<vector<string>>> memo;
       memo[s.size()] = {{}};
       return rec(s, 0, memo);
    }
};

// also simple backtracking: