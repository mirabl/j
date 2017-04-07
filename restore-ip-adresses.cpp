class Solution {
public:
    void rec(string& s, int offset, vector<int>& ad, vector<string>& res) {
        if (ad.size() == 4) {
            if (offset == s.size()) {
                res.push_back(to_string(ad[0]) + "." + to_string(ad[1]) + "." + to_string(ad[2]) + "." + to_string(ad[3]));
            }
        } else {
            int i = 0;
            int x = 0;
            do {
                x = 10 * x + (s[offset + i] - '0');
                if (x >= 256) {
                    break;
                }
                ad.push_back(x);
                rec(s, offset + i + 1, ad, res);
                ad.pop_back();
                i++;
            } while (x != 0 && offset + i < s.size());
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<int> ad;
        rec(s, 0, ad, res);
        return res;
    }
};