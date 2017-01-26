class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        for (int x: nums) {
            set<vector<int>> S;
            for (vector<int> w: res) {
                if (x >= w[w.size() - 1]) {
                    vector<int> v(w);
                    v.push_back(x);
                    S.insert(v);
                }
            }
            res.insert(S.begin(), S.end());
            vector<int> v;
            v.push_back(x);
            res.insert(v);
        }
        vector<vector<int>> resf;
        for (vector<int> v: res) {
            if (v.size() >= 2) {
                resf.push_back(v);
            }
        }
        return resf;
    }
};

class Solution {
public:
   void rec(vector<int>& nums, int start, vector<int>& seq, set<vector<int>>& acc) {
       if (start >= int(nums.size())) {
           return;
       }
       if (seq.empty() || nums[start] >= seq[seq.size() - 1]) {
           seq.push_back(nums[start]);
           vector<int> v(seq);
           if (v.size() >= 2) {
               acc.insert(v);
           }
           rec(nums, start + 1, seq, acc);
           seq.pop_back();
       }
       rec(nums, start + 1, seq, acc);
   }
 
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> resS;
        vector<int> seq;
        rec(nums, 0, seq, resS);
        vector<vector<int>> res;
        for (auto x: resS) {
            res.push_back(x);
        }
        return res;
    }
};

class Solution {
public:
   void rec(vector<int>& nums, int start, vector<int>& seq, set<vector<int>>& acc) {
       if (start >= int(nums.size())) {
           return;
       }
       for (int i = start; i < int(nums.size()); i++) {
           if (seq.empty() || nums[i] >= seq[seq.size() - 1]) {
               seq.push_back(nums[i]);
               vector<int> v(seq);
               if (v.size() >= 2) {
                   acc.insert(v);
               }
               rec(nums, i + 1, seq, acc);
               seq.pop_back();
           }
       }
   }
 
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> resS;
        vector<int> seq;
        rec(nums, 0, seq, resS);
        vector<vector<int>> res;
        for (auto x: resS) {
            res.push_back(x);
        }
        return res;
    }
};