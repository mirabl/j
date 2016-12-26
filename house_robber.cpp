/*
https://leetcode.com/problems/house-robber/
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

alias a='g++ -Wall house_robber.cpp -g && ./a.out'

*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int n_houses = 5;
	int gain[n_houses + 2] = {0, 1, 2, 1, 1, 5, 0};

	int max_gain[n_houses + 2];

	for (int i = 0; i < n_houses + 2; ++i) {
		max_gain[i] = gain[i];
	}

	for (int i = 0; i < n_houses + 2; ++i) {
		cout << max_gain[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n_houses + 2; ++i) {
		for (int j = i + 2; j < n_houses + 1; ++j) {
			cout << "i " << i << ", j " << j << ": " << max_gain[j] << " / " << max_gain[i] + gain[j] << endl;
			max_gain[j] = max(max_gain[j], max_gain[i] + gain[j]);

			cout << "\t\t\t";
			for (int i = 0; i < n_houses + 2; ++i) {
				cout << max_gain[i] << " ";
			}
			cout << endl;

		}
	}

	for (int i = 0; i < n_houses + 1; ++i) {
		max_gain[n_houses + 1] = max(max_gain[n_houses + 1], max_gain[i]);
	}

	for (int i = 0; i < n_houses + 2; ++i) {
		cout << max_gain[i] << " ";
	}
	cout << endl;

	return 0;
}