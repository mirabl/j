/*
https://leetcode.com/problems/heaters/
475. Heaters   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 4290
Total Submissions: 14245
Difficulty: Easy
Contributors: neelamgehlot
Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:
Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.
Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int findClosestHeater2(vector<int>& heaters, int x) {
	int n = (int)heaters.size();
	if (x <= heaters[0]) {
		return 0;
	} else if (x > heaters[n - 1]) {
		return n - 1;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (heaters[i] <= x && x <= heaters[i + 1]) {
			if (x - heaters[i] < heaters[i + 1] - x) {
				return i;
			} else {
				return i + 1;
			}
		}
	}
	return -1; // Never reached.
}

int findClosestHeater(vector<int>& heaters, int x) {
	int n = (int)heaters.size();
	if (x <= heaters[0]) {
		return 0;
	} else if (x > heaters[n - 1]) {
		return n - 1;
	}
	int hi = n - 1;
	int lo = 0;
	int mid = lo;
	while (hi - lo > 1) {
		mid = lo + (hi - lo) / 2;
		if (heaters[mid] < x) {
			lo = mid;
		} else {
			hi = mid;
		}
	}	
	if (heaters[hi] - x < x - heaters[lo]) {
		return hi;
	} else {
		return lo;
	}
	return 0; // Never reached.
}

int findRadius2(const vector<int>& houses, vector<int>& heaters) {
	if (houses.empty()) {
		return 0;
	}
	sort(heaters.begin(), heaters.end());

	int min_radius = -1;
	for (int i = 0; i < (int)houses.size(); ++i) {
		int closest_heater = findClosestHeater(heaters, houses[i]);
		int d = abs(heaters[closest_heater] - houses[i]);
		if (min_radius == -1 || d > min_radius) {
			min_radius = d;
		}
	}
	return min_radius;
}

int dist(int x, int y) {
	return abs(x - y);
}

int findRadius(vector<int>& houses, vector<int>& heaters) {
	sort(heaters.begin(), heaters.end());
	sort(houses.begin(), houses.end());

	int min_radius = 0;
	int current_heater = 0;
	int num_heaters = (int)heaters.size();
	for (int i = 0; i < (int)houses.size(); ++i) {
		while (current_heater < num_heaters - 1 
			   && (dist(houses[i], heaters[current_heater]) >= dist(houses[i], heaters[current_heater + 1]))) {
			++current_heater;
		}
		int d = dist(houses[i], heaters[current_heater]);
		min_radius = max(min_radius, d);
	}
	return min_radius;
}

int main() {
	vector<int> h1{1, 2, 3};
	vector<int> h2{1, 2, 3};

	vector<int> hh1{1, 2, 3};
	cout << findRadius(hh1, h1) << " 1" << endl;
	// cout << findRadius(vector<int>{1, 2, 3, 4}, h2) << " 1" << endl;
	cout << endl;
}