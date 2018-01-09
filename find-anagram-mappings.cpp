class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res;
        for (int x: A) {
            for (int i = 0; i < B.size(); i++) {
                if (B[i] == x) {
                    res.push_back(i);
                    B[i] = -1;
                    break;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        vector<int> res;
        unordered_map<int, vector<int>> M;
        for (int i = 0; i < B.size(); i++) {
            M[B[i]].push_back(i);
        }
        for (int x: A) {
            res.push_back(M[x].back());
            M[x].pop_back();
        }
        return res;
    }
};

