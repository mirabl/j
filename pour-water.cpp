class Solution {
public:
    int move(vector<int>& heights, int x) {
        int last_x = -1;
        while (last_x != x) {
            last_x = x;
            x = tryMoveOne(heights, x);
        }
        return x;
    }
    
    int moveLateral(vector<int>& heights, int x, int dir) {
        for (int i = x + dir; i >= 0 && i < heights.size(); i += dir) {
            if (heights[i] > heights[x]) {
                break;
            } else if (heights[i] < heights[x]) {
                return i;
            }
        }
        return -1;
    }
    
    int tryMoveOne(vector<int>& heights, int x) {
        int n = moveLateral(heights, x, -1);
        if (n != -1) {
            return n;
        }
        n = moveLateral(heights, x, 1);
        return n != -1 ? n : x;
    }
    
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        for (int i = 0; i < V; i++) {
            int final_position = move(heights, K);
            heights[final_position]++;
        }
        return heights;
    }
};


class Solution {
public:
    int moveLateral(vector<int>& heights, int x, int dir) {
        int u = x + dir;
        while (u >= 0 && u < heights.size()) {
            if (heights[u] < heights[x]) {
                return moveLateral(heights, u, dir);
            } else if (heights[u] > heights[x]) {
                return x;
            }
            u += dir;
        }
        return x;
    }
        
    int tryMoveOne(vector<int>& heights, int x) {
        int n = moveLateral(heights, x, -1);
        if (n != x) {
            return n;
        }
        return moveLateral(heights, x, 1);
    }
    
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        for (int i = 0; i < V; i++) {
            int final_position = tryMoveOne(heights, K);
            heights[final_position]++;
        }
        return heights;
    }
};

class Solution {
public:
    int moveLateral(vector<int>& heights, int x, int dir) {
        int u = x + dir;
        while (u >= 0 && u < heights.size() && heights[u] <= heights[x]) {
            if (heights[u] < heights[x]) {
                x = u;
            }
            u += dir;
        }
        return x;
    }
        
    int tryMoveOne(vector<int>& heights, int x) {
        int n = moveLateral(heights, x, -1);
        if (n != x) {
            return n;
        }
        return moveLateral(heights, x, 1);
    }
    
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        for (int i = 0; i < V; i++) {
            int final_position = tryMoveOne(heights, K);
            heights[final_position]++;
        }
        return heights;
    }
};