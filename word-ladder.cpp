/*
https://leetcode.com/problems/word-ladder/
*/
// Could be simplified.

class Solution {
public:
    bool oneLetterDifference(string s, string t) {
        bool one_diff = false;
        for (int i = 0; i < int(s.size()); ++i) {
            if (s[i] != t[i]) {
                if (one_diff) {
                    return false;
                }
                one_diff = true;
            }
        }
        return one_diff;
    }

    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int n = int(wordList.size());
        vector<string> words(wordList.begin(), wordList.end());
        sort(words.begin(), words.end());
        words.push_back(beginWord);
        words.push_back(endWord);        
        vector<vector<int>> adj(n + 2);
        for (int i = 0; i < n + 2; ++i) {
            for (int j = i + 1; j < n + 2; ++j) {
                if (oneLetterDifference(words[i], words[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        set<int> visited;
        queue<int> Q; // BFS
        Q.push(n);
        Q.push(-1);
        int d = 1;
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            if (visited.count(x) == 1) {
                continue;
            }
            if (x == -1) {
                if (Q.empty()) {
                    break;
                }
                d += 1;
                Q.push(-1);
            } else {
                if (x == n + 1) {
                    return d;
                }
                visited.insert(x);
                for (int y: adj[x]) {
                    Q.push(y);
                }
            }
        }
        return 0;
    }
};
