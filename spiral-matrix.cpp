class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& M) {
    	int row_start = 0;
    	int row_end = M.size() - 1;
    	int col_start = 0;
    	int col_end = (M.empty() ? -1 : M[0].size() - 1);
    	vector<int> res;
    	while (row_start <= row_end || col_start <= col_end) {
    		for (int col = col_start; row_start <= row_end && col <= col_end; col++) {
    			res.push_back(M[row_start][col]); 
    		}
    		row_start++;
    		for (int row = row_start; col_end >= col_start && row <= row_end; row++) {
    			res.push_back(M[row][col_end]);
    		}
    		col_end--;
    		for (int col = col_end; row_end >= row_start && col >= col_start; col--) {
    			res.push_back(M[row_end][col]);
    		}
    		row_end--;
    		for (int row = row_end; col_start <= col_end && row >= row_start; row--) {
    			res.push_back(M[row][col_start]);
    		}
    		col_start++;
    	} 
        return res;
    }
};