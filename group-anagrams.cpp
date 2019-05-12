struct Node {
    string key;
    vector<string> value;
    Node *next;
};

class HashMap {
public:
    vector<Node*> T;
    std::hash<string> hasher;
    int M = 1 << 8;
    
    HashMap() {
        T = vector<Node*>(M, NULL);
    }
    
    vector<string> get(string& k) {
        Node *p = T[hash(k)];
        while (p) {
            if (p->key == k) {
                return p->value;
            }
            p = p->next;
        }
        return {};
    }
    
    int hash(string& s) {
       return hasher(s) % M;
    }
    
    void set(string& k, vector<string>& v) {
        Node *p = T[hash(k)];
        while (p) {
            if (p->key == k) {
                break;
            }
            p = p->next;
        }
        
        if (p) {
            p->value = v;
        } else {
            p = new Node();
            p->key = k;
            p->value = v;
            p->next = T[hash(k)];
            T[hash(k)] = p;
        }
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        set<string> keys;
        
        HashMap M;
        for (auto s: strs) {
            auto t = string(s);
            sort(t.begin(), t.end());
            vector<string> v = M.get(t);
            v.push_back(s);
            M.set(t, v);
            keys.insert(t);
        }
        
        vector<vector<string>> res;
        for (auto k: keys) {
            vector<string> V = M.get(k);
            res.push_back(V);
        }
        
        return res;
    }
};


struct Node {
    string key;
    vector<string> value;
    Node *next;
};

class HashMap {
public:
    vector<Node*> T;
    std::hash<string> hasher;
    int M = 1 << 8;
    
    HashMap() {
        T = vector<Node*>(M, NULL);
    }
    
    vector<string> get(string& k) {
        Node *p = T[hash(k)];
        while (p) {
            if (p->key == k) {
                return p->value;
            }
            p = p->next;
        }
        return {};
    }
    
    int hash(string& s) {
        int p = 31;
        int h = 0;
        for (auto c: s) {
            h = (h * p + (c + 1 - 'a')) % M;
        }
        return h;
    }
    
    void set(string& k, vector<string>& v) {
        Node *p = T[hash(k)];
        while (p) {
            if (p->key == k) {
                break;
            }
            p = p->next;
        }
        
        if (p) {
            p->value = v;
        } else {
            p = new Node();
            p->key = k;
            p->value = v;
            p->next = T[hash(k)];
            T[hash(k)] = p;
        }
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        set<string> keys;
        
        HashMap M;
        for (auto s: strs) {
            auto t = string(s);
            sort(t.begin(), t.end());
            vector<string> v = M.get(t);
            v.push_back(s);
            M.set(t, v);
            keys.insert(t);
        }
        
        vector<vector<string>> res;
        for (auto k: keys) {
            vector<string> V = M.get(k);
            res.push_back(V);
        }
        
        return res;
    }
};
