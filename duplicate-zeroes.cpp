class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> res;
        for (int x: arr) {
            if (x == 0) {
                res.push_back(0);
            }
            res.push_back(x);
        }
        res.resize(arr.size());
        swap(res, arr);
    }
};
