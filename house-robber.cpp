/*
https://leetcode.com/problems/house-robber/
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

alias a='g++ -Wall -std=c++11 house_robber.cpp -g && ./a.out'

*/
class Solution {
public:
int rob(vector<int>& nums) {
    int n = int(nums.size());
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return nums[0];
    }
    vector<int> M(n);
    M[0] = nums[0];
    M[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i) {
        M[i] = max(M[i - 1], nums[i] + M[i - 2]);
    }
    return M[n - 1];
}

};