// contest
class MapSum {
public:
    map<string, int> M;
    
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        M[key] = val;
    }
    
    int sum(string prefix) {
        int res = 0;
        for (auto kvp: M) {
            string k = kvp.first;
            if (k.substr(0, prefix.size()) == prefix) {
                res += kvp.second;
            }
        }
        return res;
    }
};
