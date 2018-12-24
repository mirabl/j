class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> F1;
        for (int x: nums1) {
            F1[x]++;
        }
        vector<int> res;
        for (int y: nums2) {
            if (F1[y] > 0) {
                res.push_back(y);
                F1[y]--;
            }
        }
        return res;
    }
};