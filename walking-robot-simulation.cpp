// https://leetcode.com/contest/weekly-contest-94/problems/walking-robot-simulation/
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        int orient = 0;
        
        vector<int> dx{0, 1, 0, -1};
        vector<int> dy{1, 0, -1, 0};

        map<int, set<int>> O;
        for (auto v: obstacles) {
            O[v[0]].insert(v[1]);
        }
        
        int res = 0;
        for (int command: commands) {
            if (command == -1) {
                orient = (orient + 1) % 4;
            } else if (command == -2) {
                orient = (orient + 3) % 4;
            } else {
                for (int i = 0; i < command; i++) {
                    int x2 = x + dx[orient];
                    int y2 = y + dy[orient];
                    if (O[x2].count(y2) == 0) {
                        x = x2;
                        y = y2;
                    }
                }
            }
            res = max(res, x * x + y * y);
        }
        return res;
    }
};