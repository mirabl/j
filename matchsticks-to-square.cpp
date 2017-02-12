class Solution {
public:
    bool sumsTo(vector<int>& nums, int target, int mask, vector<int>& pos) {
        int s = 0;
        for (int i = 0; i < int(pos.size()); i++) {
            if (((mask >> i) & 1) == 0) {
                s += nums[pos[i]];
            }
        }
        return s == target;
    }

    bool makesquare(vector<int>& nums) {
        int perimeter = accumulate(nums.begin(), nums.end(), 0);
        int side = perimeter / 4;
        if (side == 0 || side * 4 != perimeter) {
            return false;
        }
        const int n = int(nums.size());
        vector<int> pos_;
        for (int i = 0; i < n; i++) {
            pos_.push_back(i);
        }
        for (int x = 0; x < (1 << n); x++) {
            if (sumsTo(nums, 2 * side, x, pos_)) {
                vector<int> pos[2];
                for (int i = 0; i < n; i++) {
                    pos[(x >> i) & 1].push_back(i);
                }
                vector<int> sizes{pos[0].size(), pos[1].size()};
                for (int y = 0; y < (1 << sizes[0]); y++) {
                    if (sumsTo(nums, side, y, pos[0])) {
                        for (int z = 0; z < (1 << sizes[1]); z++) {
                            if (sumsTo(nums, side, z, pos[1])) {
                               return true;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};
 
// also possible DFS

