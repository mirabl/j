/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    const string nullMarker = "-";
    
    void rs(TreeNode *root, string& s) {
        if (!root) {
            s = s + (s.empty() ? "" : ",") + nullMarker;
            return;
        }
        
        s += (s.empty() ? "" : ",") + to_string(root->val);
        rs(root->left, s);
        rs(root->right, s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        rs(root, s);
        cout << "s=" << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        vector<string> tokens;
        string token;
                
        while (getline(iss, token, ',')) {
            tokens.push_back(token);
            cout << "t=" << token << endl;
        }
       
        stack<TreeNode*> S;
        for (int i = int(tokens.size()) - 1; i >= 0; i--) {
            if (tokens[i] == nullMarker) {
                S.push(NULL);
            } else {
                TreeNode *l = S.top();
                S.pop();
                TreeNode *r = S.top();
                S.pop();
                TreeNode *p = new TreeNode(stoi(tokens[i]));
                p->left = l;
                p->right = r;
                S.push(p);
            }
        }
        
        
        return S.top();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    const string nullMarker = "-";
    
    void sappend(string& s, const string& t) {
        if (!s.empty()) {
            s.append(",");
        }
        s.append(t);
    }
    
    void rs(TreeNode *root, string& s) {
        if (!root) {
            sappend(s, nullMarker);
            return;
        }
        rs(root->right, s);
        rs(root->left, s);

        sappend(s, to_string(root->val));    
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        rs(root, s);
        cout << "s=" << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        vector<string> tokens;
        string token;
        stack<TreeNode*> S;

        while (getline(iss, token, ',')) {
            if (token == nullMarker) {
                S.push(NULL);
            } else {
                TreeNode *l = S.top();
                S.pop();
                TreeNode *r = S.top();
                S.pop();
                TreeNode *p = new TreeNode(stoi(token));
                p->left = l;
                p->right = r;
                S.push(p);
            }
        }
        return S.top();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
