/*
https://leetcode.com/problems/combinations/
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (k > n) {
            return vector<vector<int>>();
        }
        if (k == 0 || n == 0) {
            return vector<vector<int>>(1);
        }
        vector<vector<int>> ra = combine(n - 1, k - 1);
        for (int i = 0; i < int(ra.size()); ++i) {
            ra[i].push_back(n);
        }
        vector<vector<int>> rb = combine(n - 1, k);
        ra.insert(ra.begin(), rb.begin(), rb.end());
        return ra;
    }
};

int main() {
	Solution s;
	vector<vector<int>> vv= s.combine(4, 2);
	for (vector<int> v: vv) {
		cout << "[";
		for (int x: v) {
			cout << x << " ";
		}
		cout << "]" << endl;
	}
}

//
class Solution {
public:
    void rec(vector<int>& A, int from, vector<vector<int>>& res, int n, int k) {
        if (A.size() == k) {
            res.push_back(A);
            return;
        }
        
        for (int i = from; i < n; i++) {
            A.push_back(i);
            rec(A, i + 1, res, n, k);
            A.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> A;
        
        rec(A, 1, res, n + 1, k);
        return res;
    }
};
