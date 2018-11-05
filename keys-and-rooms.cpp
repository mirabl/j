// https://leetcode.com/problems/keys-and-rooms/description/
class Solution {
public:
    set<int> v;
    vector<vector<int>> r;
    
    bool rec(int room) {
        if (v.count(room) == 1) {
            return false;
        }
        v.insert(room);
        if (v.size() == r.size()) {
            return true;
        }
        
        for (auto next: r[room]) {
            if (rec(next)) {
                return true;
            }
        }
        return false;
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        r = rooms;
        return rec(0);
    }
};
