class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int W = sqrt(area); W >= 0; W--) {
            if (area % W == 0) {
                return vector<int>{area / W, W};
            }
        }
    }
};