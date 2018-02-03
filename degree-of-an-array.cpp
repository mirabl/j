class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> freq;
        for (int num: nums) {
            freq[num]++;
        }
        int max_freq = 1;
        set<int> max_elements;
        for (auto kv: freq) {
            if (kv.second > max_freq) {
                max_freq = kv.second;
                max_elements.clear();
            }
            if (kv.second == max_freq) {
                max_elements.insert(kv.first);
            }
        }
        map<int, int> first;
        map<int, int> last;
        for (int i = 0; i < nums.size(); i++) {
            if (max_elements.count(nums[i]) == 1) {
                if (first.count(nums[i]) == 0) {
                    first[nums[i]] = i;
                }
                last[nums[i]] = i;
            }
        }
        int min_range = 50000 + 1;
        for (int num: max_elements) {
            min_range = min(min_range, last[num] - first[num] + 1);
        }
        return min_range;
    }
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> freq;
        int max_freq = 1;
        set<int> max_elements;
        for (int num: nums) {
            freq[num]++;
            if (freq[num] > max_freq) {
                max_freq = freq[num];
                max_elements.clear();
            }
            if (freq[num] == max_freq) {
                max_elements.insert(num);
            }
        }
        map<int, int> first;
        map<int, int> last;
        for (int i = 0; i < nums.size(); i++) {
            if (max_elements.count(nums[i]) == 1) {
                if (first.count(nums[i]) == 0) {
                    first[nums[i]] = i;
                }
                last[nums[i]] = i;
            }
        }
        int min_range = 50000 + 1;
        for (int num: max_elements) {
            min_range = min(min_range, last[num] - first[num] + 1);
        }
        return min_range;
    }
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> freq;
        int max_freq = 1;
        set<int> max_elements;
        for (int num: nums) {
            freq[num]++;
            if (freq[num] > max_freq) {
                max_freq = freq[num];
                max_elements.clear();
            }
            if (freq[num] == max_freq) {
                max_elements.insert(num);
            }
        }
        map<int, int> first;
        map<int, int> last;
        for (int i = 0; i < nums.size(); i++) {
            first[nums[nums.size() - 1 - i]] = nums.size() - 1 - i;
            last[nums[i]] = i;
        }
        int min_range = 50000 + 1;
        for (int num: max_elements) {
            min_range = min(min_range, last[num] - first[num] + 1);
        }
        return min_range;
    }
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> freq;
        int max_freq = 1;
        set<int> max_elements;
        map<int, int> first;
        map<int, int> last;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            freq[num]++;
            if (freq[num] > max_freq) {
                max_freq = freq[num];
                max_elements.clear();
            }
            if (freq[num] == max_freq) {
                max_elements.insert(num);
            }
            first[nums[nums.size() - 1 - i]] = nums.size() - 1 - i;
            last[num] = i;
        }
        int min_range = 50000 + 1;
        for (int num: max_elements) {
            min_range = min(min_range, last[num] - first[num] + 1);
        }
        return min_range;
    }
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, int> freq;
        map<int, set<int>> max_elements;
        map<int, int> first;
        map<int, int> last;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            freq[num]++;
            max_elements[freq[num]].insert(num);
            first[nums[nums.size() - 1 - i]] = nums.size() - 1 - i;
            last[num] = i;
        }
        int min_range = 50000 + 1;
        for (int num: (*(max_elements.rbegin())).second) {
            min_range = min(min_range, last[num] - first[num] + 1);
        }
        return min_range;
    }
};

