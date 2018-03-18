class Solution {
public:
    typedef pair<int, int> Point;
    typedef vector<Point> Region;
    enum {
        OK,
        INFECTED,
        FROZEN
    };
    
    vector<vector<int>> grid_;
    int num_rows;
    int num_cols;
    
    bool isInGrid(Point p) {
        int row = p.first;
        int col = p.second;
        return row >= 0 && row < num_rows && col >= 0 && col < num_cols;
    }
    
    set<Point> getNeighbours(Point p) {
        set<Point> neighbours;
        vector<int> drow{1, -1,  0, 0};
        vector<int> dcol{0,  0, -1, 1}; 
        for (int i = 0; i < 4; i++) {
            Point q{p.first + drow[i], p.second + dcol[i]};
            if (isInGrid(q)) {
                neighbours.insert(q);
            }
        }
        return neighbours;
    }
    
    void dfs(vector<vector<bool>>& visited, Region& region, Point q) {
        region.push_back(q);
        visited[q.first][q.second] = true;
        for (auto p: getNeighbours(q)) {
            int row2 = p.first;
            int col2 = p.second;
            if (!visited[row2][col2] && grid_[row2][col2] == INFECTED) {
                dfs(visited, region, p);
            }
        }
    }
    
    vector<Region> getRegions() {
        vector<Region> regions;
        vector<vector<bool>> visited(num_rows, vector<bool>(num_cols, false));
        for (int row = 0; row < num_rows; row++) {
            for (int col = 0; col < num_cols; col++) {
                if (!visited[row][col] && grid_[row][col] == INFECTED) {
                    Region region;
                    dfs(visited, region, {row, col});
                    regions.push_back(region);
                }
            }
        }
        return regions;
    }
    
    Region getBorder(Region& region) {
        Region border;
        for (auto p: region) {
            for (auto q: getNeighbours(p)) {
                if (isInGrid(q) && grid_[q.first][q.second] == OK) {
                    border.push_back(q);
                }
            }    
        }
        return border;
    }

    vector<Region> getBorders(vector<Region>& regions) {
        vector<Region> borders;
        for (auto& r: regions) {
            borders.push_back(getBorder(r));
        }
        return borders;
    }
    
    int sizeWithoutDuplicates(Region& region) {
        return set<Point>(region.begin(), region.end()).size();
    }
    
    int getLargestBorder(vector<Region>& borders) {
        int largest_border_index = 0;
        for (int i = 0; i < borders.size(); i++) {
            if (sizeWithoutDuplicates(borders[i]) > sizeWithoutDuplicates(borders[largest_border_index])) {
                largest_border_index = i;
            }
        }
        return largest_border_index;
    }

    void growInfection(vector<Region>& borders, int largest_border_index) {
        for (int i = 0; i < borders.size(); i++) {
            if (i == largest_border_index) {
                continue;
            }
            for (Point p: borders[i]) {
                grid_[p.first][p.second] = INFECTED;
            }
        }
    }
    
    void markRegionAsWalled(Region& region) {
        for (auto p: region) {
            grid_[p.first][p.second] = FROZEN;
        }
    }

    void printRegion(Region& r) {
        for (auto p: r) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
    }
    
    int containVirus(vector<vector<int>>& grid) {
        grid_ = grid;
        num_rows = grid.size();
        num_cols = grid[0].size();
        
        int num_walls = 0;
        while (true) {
            vector<Region> regions = getRegions();
            if (regions.empty()) {
                break;
            }
            vector<Region> borders = getBorders(regions);
            int largest_border_index = getLargestBorder(borders);
            num_walls += borders[largest_border_index].size();
            markRegionAsWalled(regions[largest_border_index]);
            growInfection(borders, largest_border_index);
        }
        
        return num_walls;
    }
};             