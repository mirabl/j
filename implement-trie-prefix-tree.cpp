struct TrieNode {
    map<char, TrieNode*> children;
    TrieNode() { };
};

class Trie {
private:
    char end = '\0';
    TrieNode root;
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        word += end;
        TrieNode *p = &root;
        for (char c: word) {
            if (!p->children[c]) {
                TrieNode *q = new TrieNode();
                p->children[c] = q;
            }
            p = p->children[c];
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return startsWith(word + end);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = &root;
        for (char c: prefix) {
            if (!p->children[c]) { 
                return false;
            }
            p = p->children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */


 struct TrieNode {
    char val;
    vector<TrieNode*> children;
    TrieNode(char v): val(v) { };
};

class Trie {
private:
    char end = '\0';
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('*');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        word += end;
        TrieNode *p = root;
        for (char c: word) {
            TrieNode *child = NULL;
            for (TrieNode* q: p->children) {
                if (q->val == c) {
                    child = q;
                    break;
                }
            }
            if (!child) {
                child = new TrieNode(c);
                p->children.push_back(child);
            }
            p = child;
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return startsWith(word + end);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (char c: prefix) {
            TrieNode *child = NULL;
            for (TrieNode* q: p->children) {
                if (q->val == c) {
                    child = q;
                    break;
                }
            }
            if (!child) {
                return false;
            }
            p = child;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */


 // could use member variable end in TrieNode to avoir creating new node for end of word.