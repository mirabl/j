class Solution {
public:
    int nextChar(string S, int i) {
        int back = 0;
        
        while (i >= 0) {
            if (S[i] == '#') {
                back++;
            } else {
                if (back == 0) {
                    return i;
                }
                back--;
            } 
            i--;
        }
        return -1;
    }
    
    bool backspaceCompare(string S, string T) {
        int i = int(S.size()) - 1;
        int j = int(T.size()) - 1;
        
        while (i >= 0 || j >= 0) {
            i = nextChar(S, i);
            j = nextChar(T, j);
            char cs = i >= 0 ? S[i] : 0;
            char ct = j >= 0 ? T[j] : 0;
            if (cs != ct) {
                return false;
            }
            i--;
            j--;
        }
        return i == j;
    }
};
