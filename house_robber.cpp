/*
https://leetcode.com/problems/house-robber/
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

alias a='g++ -Wall -std=c++11 house_robber.cpp -g && ./a.out'

*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int rob(const vector<int>& nums) {
	vector<int> gain(nums);
	gain.insert(gain.begin(), 0);
	gain.push_back(0);
	int n_houses = (int)gain.size() - 2;
	int max_gain[n_houses + 2];

	for (int i = 0; i < n_houses + 2; ++i) {
		max_gain[i] = gain[i];
	}

	for (int i = 0; i < n_houses + 2; ++i) {
		for (int j = i + 2; j < n_houses + 1; ++j) {
			max_gain[j] = max(max_gain[j], max_gain[i] + gain[j]);
		}
	}

	for (int i = 0; i < n_houses + 1; ++i) {
		max_gain[n_houses + 1] = max(max_gain[n_houses + 1], max_gain[i]);
	}
	return max_gain[n_houses + 1];
}


int main() {
	vector<int> gain = {0, 1, 2, 1, 1, 5, 0};
	cout << rob(gain) << endl;
	cout << rob(vector<int>{1, 1, 1}) << endl;
	return 0;
}