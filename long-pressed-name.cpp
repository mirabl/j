class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if (name.empty() && typed.empty()) return true;
        if (name.empty() || typed.empty()) return false;
        if (name[0] != typed[0]) return false;
        
        bool res = isLongPressedName(name.substr(1), typed.substr(1));
        if (typed.size() > 1 && typed[1] == name[0]) {
            res = res || isLongPressedName(name.substr(1), typed.substr(2));
        }
        return res;
    }
};
