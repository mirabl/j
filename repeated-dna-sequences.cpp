/*
https://leetcode.com/problems/repeated-dna-sequences/
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int k = 10;
        map<string, int> M;
        const int n = int(s.size());
        vector<string> res;
        for (int i = 0; i < n + 1 - k; i++) {
            string t = s.substr(i, k);
            M[t]++;
            if (M[t] == 2) {
                res.push_back(t);
            }
        }
        return res;
    }
};


class Solution {
public:
    // Rolling hash.
    vector<string> findRepeatedDnaSequences(string s) {
        const int k = 10;
        map<int, int> M;
        const int n = int(s.size());
        map<char, int> encode;
        encode['A'] = 0;
        encode['C'] = 1;
        encode['G'] = 2;
        encode['T'] = 3;
        
        int h = 0;
        for (int i = 0; i < k - 1 && i < n; i++) {
            h = h << 2 | encode[s[i]];
        }
        
        vector<string> res;
        for (int i = k - 1; i < n; i++) {
            h = (h << 2 | encode[s[i]]) & 0xfffff; // 2^20 - 1
            M[h]++;
            if (M[h] == 2) {
                res.push_back(s.substr(i - k + 1, k));
            }
        }
        return res;
    }
};