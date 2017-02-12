class Solution {
public:
    int bits10(int n) {
        return ((1 << n) - 1) << (8 - n);
    }
    
    bool validUtf8(vector<int>& data) {
        for (int j = 0; j < int(data.size()); ) {
            int n;
            if ((data[j] & 0x80) == 0) {
                n = 1;
            } else {
                for (n = 4; n >= 2; n--) {
                    if ((data[j] & bits10(n + 1)) == bits10(n)) {
                        for (int i = 1; i < n; i++) {
                            if ((data[j + i] & 0xc0) != 0x80) {
                                return false;
                            }
                        }
                        break;
                    }
                }
                if (n == 1) {
                    return false;
                }
            }
            j += n;
        }
        return true;
    }
};