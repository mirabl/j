#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            swap(s[i], s[n - 1 - i]);
        }
        
        // 2 loops could be merged?

        // Clean up whitespace.
        int lo = 0;
        for (int hi = 0; hi < n; hi++) {
            if ((lo == 0 || (lo > 0 && s[lo - 1] == ' ')) && s[hi] == ' ') {
                continue;
            }
            s[lo] = s[hi];
            lo++;
        }
        if (s[lo - 1] == ' ') {
            lo--;
        }
        n = max(0, lo);
        s.resize(n);
        
        lo = 0;
        while (lo < n) {
            int hi = lo;
            while (hi < n - 1 && s[hi + 1] != ' ') {
                hi++;
            }
            // Reverse word in [lo,hi]
            for (int k = 0; k < (hi + 1 - lo) / 2; k++) {
                swap(s[lo + k], s[hi - k]);
            }
            lo = hi + 2;
        }
    }
};