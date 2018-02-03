class Solution {
public:
    int cost(char c) {
        return int(c);
    }
    
    int minimumDeleteSum(string s1, string s2) {
     /*
     abcd
     xyz
     
     if d == z
       d(abc, xy)
     if d != z
       min(cost(d) + d(abc, xyz), cost(z) + d(abcd, xy))
     
             -  x  xy  xyz (m+1)
         -   
         a
        ab
       abc 
      abcd   
      (n+1)
     */
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> A(n + 1, vector<int>(m + 1));
        for (int col = 1; col < m + 1; col++) {
            A[0][col] = A[0][col - 1] + cost(s2[col - 1]);
        }
        for (int row = 1; row < n + 1; row++) {
            A[row][0] = A[row - 1][0] + cost(s1[row - 1]);
        }
        for (int row = 1; row < n + 1; row++) {
            for (int col = 1; col < m + 1; col++) {
                if (s1[row - 1] == s2[col - 1]) {
                    A[row][col] = A[row - 1][col - 1];
                } else {
                    A[row][col] = min(cost(s1[row - 1]) + A[row - 1][col], cost(s2[col - 1]) + A[row][col - 1]);
                }
            }
        }
        return A[n][m];
    }
};

class Solution {
public:
    int cost(char c) {
        return int(c);
    }
    
    int minimumDeleteSum(string s1, string s2) {
     /*
     abcd
     xyz
     
     if d == z
       d(abc, xy)
     if d != z
       min(cost(d) + d(abc, xyz), cost(z) + d(abcd, xy))
     
             -  x  xy  xyz (m+1)
         -   
         a
        ab
       abc 
      abcd   
      (n+1)
     */
        int n = s1.size();
        int m = s2.size();
        s1.insert(s1.begin(), 0);
        s2.insert(s2.begin(), 0);
        vector<vector<int>> A(n + 1, vector<int>(m + 1));
        for (int col = 1; col < m + 1; col++) {
            A[0][col] = A[0][col - 1] + cost(s2[col]);
        }
        for (int row = 1; row < n + 1; row++) {
            A[row][0] = A[row - 1][0] + cost(s1[row]);
        }
        for (int row = 1; row < n + 1; row++) {
            for (int col = 1; col < m + 1; col++) {
                if (s1[row] == s2[col]) {
                    A[row][col] = A[row - 1][col - 1];
                } else {
                    A[row][col] = min(cost(s1[row]) + A[row - 1][col], cost(s2[col]) + A[row][col - 1]);
                }
            }
        }
        return A[n][m];
    }
};



