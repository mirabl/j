/*
https://leetcode.com/problems/remove-element/
*/
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int removeElement(vector<int>& nums, int val) {
	int n = (int)nums.size();
	int end_pos = n - 1;
	int i = 0;
	while (i <= end_pos) {
		if (nums[i] == val) {
			swap(nums[i], nums[end_pos]);
			--end_pos;
		} else {
			++i;
		}
	}
	return end_pos + 1;
}

void print_vector(const vector<int>& v) {
	for (int i = 0; i < (int)v.size(); ++i) {
		cout << v[i] << " ";
	}
}

int main() {
	vector<int> v{1, 2, 3, 2, 1};
	int s = removeElement(v, 3);
	cout << s << endl;
	print_vector(v);
	cout << endl;
}

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int lo = 0;
        int hi = 0;
        while (hi < n) {
            if (nums[hi] != val) {
                nums[lo] = nums[hi];
                lo++;
            }
            hi++;
        }
        return lo;
    }
};
