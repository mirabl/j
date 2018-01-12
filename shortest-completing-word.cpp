class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string res;
        
        map<char, int> plate;
        for (char c: licensePlate) {
            if (isalpha(c)) {
                plate[tolower(c)]++;
            }
        }
        
        for (string word: words) {
            map<char, int> W;
            for (char c: word) {
                W[c]++;
            }
            bool completes = true;
            for (auto kv: plate) {
                if (W[kv.first] < kv.second) {
                    completes = false;
                }
            }
            if (completes && (res.empty() || word.size() < res.size())) {
                res = word;
            }
        }
        
        return res;
    }
};

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string res('.', 15 + 1);

        for (string word: words) {
            map<char, int> freq;
            for (char c: word) {
                freq[c]++;
            }
            bool completes = true;
            for (char c: licensePlate) {
                if (isalpha(c)) {
                    if (freq[tolower(c)] == 0) {
                        completes = false;
                        break;
                    }
                    freq[tolower(c)]--;
                }
            }
            if (completes && word.size() < res.size()) {
                res = word;
            }
        }
        return res;
    }
};

