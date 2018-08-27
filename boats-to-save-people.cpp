class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int hi = people.size() - 1;
        int lo = 0;
        
        int res = 0;
        while (hi >= lo) {
            if (people[hi] + people[lo] <= limit) {
                lo++;
            }
            hi--;
                
            res++;
        }
        return res;
    }
};
