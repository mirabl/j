class Solution {
public:
    enum Colors { WHITE, GREY, BLACK };

    bool dfs(vector<vector<int>>& L, int i, vector<int>& colors) {
        colors[i] = GREY;
        for (int j: L[i]) {
            if (colors[j] == GREY || !dfs(L, j, colors)) {
                return false;
            }
        }
        colors[i] = BLACK;
        return true;
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> L(numCourses);
        for (auto e: prerequisites) {
            L[e.first].push_back(e.second);
        }
        vector<int> colors(numCourses, WHITE);
        for (int i = 0; i < numCourses; i++) {
            if (colors[i] == BLACK) {
                continue;
            }
            if (!dfs(L, i, colors)) {
                return false;
            }
        }
        return true;
    }
};