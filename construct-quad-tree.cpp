/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid, int minrow, int maxrow, int mincol, int maxcol) {
        bool v = grid[minrow][mincol];
        for (int row = minrow; row < maxrow; row++) {
            for (int col = mincol; col < maxcol; col++) {
                if (grid[row][col] != v) {
                    // split
                    int midrow = (minrow + maxrow) / 2;
                    int midcol = (mincol + maxcol) / 2;
                    Node *topLeft = construct(grid, minrow, midrow, mincol, midcol);
                    Node *topRight = construct(grid, minrow, midrow, midcol, maxcol);
                    Node *bottomLeft = construct(grid, midrow, maxrow, mincol, midcol);
                    Node *bottomRight = construct(grid, midrow, maxrow, midcol, maxcol);
                    return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
                }
            }
        }
        return new Node(v, true, NULL, NULL, NULL, NULL);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return construct(grid, 0, grid.size(), 0, grid[0].size());
    }
};
