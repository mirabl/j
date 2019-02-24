class Solution {
public:
    string strWithout3a3b(int A, int B) {
       
        if (A < B) {
            auto s = strWithout3a3b(B, A);
            string t;
            for (auto c: s) {
                t.push_back(c == 'a' ? 'b' : 'a');
            }
            return t;
        }
        
        if (B == 0) {
            if (A == 0) {
                return "";
            } else if (A == 1) {
                return "a";
            } else if (A == 2) {
                return "aa";
            }
        }
        
        if (A > B) {
            return string("aab") + strWithout3a3b(A - 2, B - 1);    
        } else {
            return string("ab") + strWithout3a3b(A - 1, B - 1);
        }
       
    }
};
