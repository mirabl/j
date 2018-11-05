// https://leetcode.com/problems/push-dominoes/description/
class Solution {
public:
    string pushDominoes(string dominoes) {
        string r(dominoes);
        int n = int(dominoes.size());
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'L' && i > 0 && dominoes[i - 1] == '.' && (i == 1 || dominoes[i - 2] != 'R')) {
                r[i - 1] = 'L';
            } else if (dominoes[i] == 'R' && i < n - 1 && dominoes[i + 1] == '.' && (i == n - 2 || dominoes[i + 2] != 'L')) {
                r[i + 1] = 'R';
            } else {
                
            }
        }
        
        if (r != dominoes) {
            return pushDominoes(r);
        } else {
            return r;
        }
    }
};
