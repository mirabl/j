class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        int n = list1.size();
        int m = list2.size();
        for (int d = 0; d < n + m - 1; d++) {
            for (int i = max(0, d - m + 1); i <= d && i < n; i++) {
                if (list1[i] == list2[d - i]) {
                    res.push_back(list1[i]);
                }
            }
            if (!res.empty()) {
                break;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string, int> H;
        for (int i = 0; i < list1.size(); i++) {
            H[list1[i]] = i;
        }
        int sum = -1;
        for (int j = 0; j < list2.size(); j++) {
            if (H.count(list2[j]) != 0) {
                if (H[list2[j]] + j < sum) {
                    res.clear();
                }
                if (res.empty() || H[list2[j]] + j <= sum) {
                    res.push_back(list2[j]);
                    sum = H[list2[j]] + j;
                }
            }
        }        
        return res;
    }
};

