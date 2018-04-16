// contest
class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 1) {
            return true;
        }
        if (s[0] == '0' && s[1] != '.') {
            return false;
        }
        if (s.find('.') != string::npos && s[s.size() - 1] == '0') {
            return false;
        }
        
        return true;
    }
    
    vector<string> all(string s) {
        vector<string> dotted;
        dotted.push_back(s);
        int N = s.size();
        for (int i = 0; i < N - 1; i++) {
            auto t = s.substr(0, i + 1) + "." + s.substr(i + 1);
            dotted.push_back(t);
        }

        vector<string> res;
        for (auto t: dotted) {
            if (isValid(t)) {
                res.push_back(t);
            }
        }

        return res;
    }
    
    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;
        int N = S.size();
        // 0 1 2 3 4, N = 5
        // ( a b c )
        //  0 1 2 3 
        for (int cut = 1; cut < N - 2; cut++) {
            string left = S.substr(1, cut);
            string right = S.substr(1 + cut, N - 2 - cut);
            vector<string> allLeft = all(left);
            vector<string> allRight = all(right);
            
            for (auto aleft: allLeft) {
                for (auto aright: allRight) {
                    res.push_back("(" + aleft +  ", " + aright + ")");
                }
            }
        }
        return res;
    }
};
