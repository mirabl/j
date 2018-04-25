class MagicDictionary {
public:
    set<string> S;
    
    /** Initialize your data structure here. */
    MagicDictionary() {

    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        S.insert(dict.begin(), dict.end());
    }
    
    bool distanceOne(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        int numDiff = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                numDiff++;
            }
        }
        return numDiff == 1;
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (string s: S) {
            if (distanceOne(word, s)) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */
