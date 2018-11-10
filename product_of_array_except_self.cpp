/*
https://leetcode.com/problems/product-of-array-except-self/
A0      A1     A2    
 
1        A0    A0A1  
A1A2     A2    1    
*/

class Solution {
public:
vector<int> productExceptSelf(vector<int>& nums) {
	int n = (int)nums.size();
	vector<int> res(n, 1);
	for (int i = 1; i < n; ++i) {
		res[i] = res[i - 1] * nums[i - 1];
	}
	int r = 1;
	for (int i = n - 1; i >= 0; --i) {
		res[i] *= r;
		r = r * nums[i];
	}
	return res;
}

};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(N);
        for (int i = 0; i < N; i++) {
            res[i] = i > 0 ? res[i - 1] * nums[i - 1] : 1;
        }
        
        int acc = 1;
        for (int i = N - 1; i >= 0; i--) {
            res[i] = res[i] * acc;
            acc *= nums[i];
        }
        
        return res;
    }
};
