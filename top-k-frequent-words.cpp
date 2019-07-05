// n log n
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> count;
        for (string word: words) {
            count[word]++;
        }
        vector<pair<int, string>> V;
        for (auto p: count) {
            V.push_back({- p.second, p.first});
        }
        sort(V.begin(), V.end());
        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(V[i].second);
        }
        return res;
    }
};

// n log k with priority queue

bool cmp(const pair<int, string>& p, const pair<int, string>& q) {
    return (p.first > q.first || (p.first == q.first && p.second < q.second));
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> F;
        set<string> S;
        for (auto w: words) {
            F[w]++;
            S.insert(w);
        }
        vector<pair<int, string>> V;
        for (auto w: S) {
            V.push_back({F[w], w});
        }
        sort(V.begin(), V.end(), cmp);
        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(V[i].second);
        }
        return res;
    }
};


bool cmp(const pair<int, string>& p, const pair<int, string>& q) {
    return (p.first > q.first || (p.first == q.first && p.second < q.second));
}

struct Node {
    string key;
    int val;
    Node *next;
    Node(string k, int v): key(k), val(v), next(NULL) { }
};

class HT {
public:
    vector<Node*> T;
    int M = 1 << 16;
    
    HT() {
        T.resize(M);    
    }
    
    int get(string& k) {
        int h = hash(k);
        Node *p = T[h];
        while (p) {
            if (p->key == k) {
                return p->val;
            }
            p = p->next;
        }
        return 0;
    }
    
    void put(string& k, int val) {
        int h = hash(k);
        Node *p = T[h];
        while (p) {
            if (p->key == k) {
                p->val = val;
                return;
            }
            p = p->next;
        }
        Node *n = new Node(k, val);
        n->next = T[h];
        T[h] = n;
    }
    
    int hash(string& k) {
        int p1 = 257;
        int h = 0;
        for (auto c: k) {
            h = ((h * p1) + (c + 1)) % M;
        }
        return h;
    }
    
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        HT H;
        
        set<string> S;
        for (auto w: words) {
            H.put(w, H.get(w) + 1);
            S.insert(w);
        }
        vector<pair<int, string>> V;
        for (auto w: S) {
            V.push_back({H.get(w), w});
        }
        sort(V.begin(), V.end(), cmp);
        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(V[i].second);
        }
        return res;
    }
};
