class Solution {
public:
    bool rec(vector<int>& bits, int offset) {
        if (offset == bits.size() - 1) {
            return true;
        } else if (offset == bits.size() - 2) {
            return bits[offset] == 0;
        }
        return rec(bits, offset + 1 + bits[offset]);
    }

    bool isOneBitCharacter(vector<int>& bits) {
        return rec(bits, 0);
    }
};

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for (int offset = 0; ; offset++) {
            if (offset == bits.size() - 1) {
                return true;
            } else if (offset == bits.size() - 2) {
                return bits[offset] == 0;
            }
            if (bits[offset] == 1) {
                offset++;
            }
        }
    }
};

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for (int offset = 0; offset < bits.size() - 1; offset++) {
            if (offset == bits.size() - 2) {
                return bits[offset] == 0;
            }
            if (bits[offset] == 1) {
                offset++;
            }
        }
        return true;
    }
};
