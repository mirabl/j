class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, pair<int, int>> M;
        int best = 0;
        for (int n: nums) {
            M[n].second += 1;
            M[n - 1].first += 1;
            for (int x = n - 1; x <= n; x++) {
                if (M[x].first > 0 && M[x].second > 0) {
                    best = max(best, M[x].first + M[x].second);
                }
            }
        }
        return best;
    }
};


// 
/*
The idea is to keep a count of all the numbers, and eventually for each of the numbers, check if there's any adjacent number. If it's present, then add the count of both - since these two numbers form subsequence in the array.
Update : from @harkness comment, we don't need to check both +1 and -1;

public int findLHS(int[] nums) {
    Map<Long, Integer> map = new HashMap<>();
    for (long num : nums) {
        map.put(num, map.getOrDefault(num, 0) + 1);
    }
    int result = 0;
    for (long key : map.keySet()) {
        if (map.containsKey(key + 1)) {
            result = Math.max(result, map.get(key + 1) + map.get(key));
        }
    }
    return result;
}
*/
