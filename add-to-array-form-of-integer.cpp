class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> B(A.rbegin(), A.rend());
        vector<int> C;
        int i = 0;
        int carry = 0;
        while (i < B.size() || carry != 0 || K != 0) {
            int s = (i < B.size() ? B[i] : 0) + (K % 10) + carry;
            int d = s % 10;
            carry = s / 10;
            C.push_back(d);
            i++;
            K /= 10;
        }
        reverse(C.begin(), C.end());
        return C;
    }
};
