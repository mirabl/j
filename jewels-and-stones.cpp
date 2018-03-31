class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> jewels;
        for (char c: J) {
            jewels.insert(c);
        }
        int res = 0;
        for (char c: S) {
            if (jewels.count(c) == 1) {
                res++;
            }
        }
        return res;
    }
};