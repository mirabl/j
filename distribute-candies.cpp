class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> S;
        for (int c: candies) {
            S.insert(c);
        }
        return min(S.size(), candies.size() / 2);
    }
};

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        if (candies.empty()) {
            return 0;
        }
        sort(candies.begin(), candies.end());
        int last_val = candies[0] - 1;
        int kinds = 0;
        for (int c: candies) {
            if (last_val != c) {
                kinds++;
                last_val = c;
            }
        }        
        return min(kinds, int(candies.size() / 2));
    }
};

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(), candies.end());
        int last_val = candies.empty() ? 0 : candies[0] - 1;
        int kinds = 0;
        for (int c: candies) {
            if (last_val != c) {
                kinds++;
                last_val = c;
            }
        }        
        return min(kinds, int(candies.size() / 2));
    }
};

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(), candies.end());
        int kinds = 0;
        for (int i = 0; i < candies.size(); i++) {
            if (i == 0 || candies[i] != candies[i - 1]) {
                kinds++;
            }
        }
        return min(kinds, int(candies.size() / 2));
    }
};

