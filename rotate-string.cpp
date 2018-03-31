class Solution {
public:
    bool rotateString(string A, string B) {
        string C = A + A;
        return A.length() == B.length() && C.find(B) != string::npos;
    }
};