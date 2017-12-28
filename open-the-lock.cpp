class Solution {
public:
    
    vector<string> neighbours(string x) {
        vector<string> adds{"1000", "9000", "0100", "0900", "0010", "0090", "0001", "0009"};
        vector<string> res;
        for (string add: adds) {
            string r(x);
            for (int i = 0; i < 4; i++) {
                r[i] = '0' + (((r[i] - '0') + (add[i] - '0')) % 10);
            }
            res.push_back(r);
        }
        return res;
    }
    
    int openLock(vector<string>& deadends, string target) {
        set<string> visited;
        for (string deadend: deadends) {
            visited.insert(deadend);
        }
        queue<string> Q;
        Q.push("0000");
        const string kEndMarker = "";
        Q.push(kEndMarker);
        int steps = 0;
        while (!Q.empty()) {
            string x = Q.front();
            Q.pop();
            if (x == target) {
                return steps;
            } else if (x == kEndMarker) {
                if (!Q.empty()) {
                    steps += 1;
                    Q.push(kEndMarker);
                }
            } else if (visited.count(x) == 0) {
                visited.insert(x);
                for (string y: neighbours(x)) {
                    Q.push(y);
                }
            }
        }
        return -1;
    }
};


//

class Solution {
public:
    
    vector<string> neighbours(string x) {
        vector<string> adds{"1000", "9000", "0100", "0900", "0010", "0090", "0001", "0009"};
        vector<string> res;
        for (string add: adds) {
            string r(x);
            for (int i = 0; i < 4; i++) {
                r[i] = '0' + (((r[i] - '0') + (add[i] - '0')) % 10);
            }
            res.push_back(r);
        }
        return res;
    }
    
    int openLock(vector<string>& deadends, string target) {
        set<string> visited(deadends.begin(), deadends.end());
        queue<string> Q;
        Q.push("0000");
        const string kEndMarker = "";
        Q.push(kEndMarker);
        int steps = 0;
        while (!Q.empty()) {
            string x = Q.front();
            Q.pop();
            if (x == target) {
                return steps;
            } else if (x == kEndMarker) {
                if (!Q.empty()) {
                    steps += 1;
                    Q.push(kEndMarker);
                }
            } else if (visited.count(x) == 0) {
                visited.insert(x);
                for (string y: neighbours(x)) {
                    Q.push(y);
                }
            }
        }
        return -1;
    }
};