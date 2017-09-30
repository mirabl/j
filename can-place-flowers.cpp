class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();
        int n2 = 0; // number of flowers that can be placed in flowerbed[i + 2:]
        int n1 = 0; // flowerbed[i + 1:]
        for (int i = l - 1; i >= 0; i--) {
            int s = (i > 0 ? flowerbed[i - 1] : 0) + flowerbed[i] + (i < l - 1 ? flowerbed[i + 1] : 0);
            int n0 = max(n1, s == 0 ? 1 + n2 : 0);
            n2 = n1;
            n1 = n0;
        }
        return n1 >= n;
    }
};

// better: simple greedy works