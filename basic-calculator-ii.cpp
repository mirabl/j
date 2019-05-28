class Solution {
public:
    int i;
    int n;
    string s;

    stack<int> S;
    stack<char> T;
    
    void skip() {
        while (i < n && s[i] == ' ') {
            i++;
        }
    }
    
    int nextInt() {
        skip();
        int x = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            x = 10 * x + (s[i] - '0');
            i++;
        }
        skip();
        return x;
    }
    
    char nextOp() {
        char c = s[i];
        i++;
        skip();
        return c;
    }
    
    int apply(char op, int x, int y) {
        if (op == '+') return x + y;
        if (op == '-') return x - y;
        if (op == '*') return x * y;
        else return x / y;
    }
    
    void go() {
        char op = T.top();
        T.pop();
        int y = S.top(); 
        S.pop();
        int x = S.top();
        S.pop();
        S.push(apply(op, x, y));
    }
    
    int calculate(string ss) {
        n = ss.size();
        i = 0;
        s = ss;

        while (i < n) {
            int x = nextInt();
            S.push(x);
            if (i == n) {
                break;
            }
            char op = nextOp();
            while (!T.empty() 
                && ((T.top() == '*' || T.top() == '/') 
                    || ((op == '+' || op == '-') && T.top() == '-'))) {
                go();
            }
            T.push(op);
        }
        
        while (!T.empty()) {
            go();
        }
                
        return S.top();
    }
};


class Solution {
public:
    stack<int> S;
    stack<char> T;
    
    int apply(char op, int x, int y) {
        if (op == '+') return x + y;
        if (op == '-') return x - y;
        if (op == '*') return x * y;
        else return x / y;
    }
    
    void go() {
        char op = T.top();
        T.pop();
        int y = S.top(); 
        S.pop();
        int x = S.top();
        S.pop();
        S.push(apply(op, x, y));
    }
    
    int calculate(string ss) {
        istringstream iss(ss);
        int x;
        char op;
        
        while (true) {
            iss >> x;
            S.push(x);
            if (!(iss >> op)) {
                break;
            }
            while (!T.empty() 
                && ((T.top() == '*' || T.top() == '/') 
                    || ((op == '+' || op == '-') && T.top() == '-'))) {
                go();
            }
            T.push(op);
        }
        
        while (!T.empty()) {
            go();
        }
                
        return S.top();
    }
};


// clear solution https://leetcode.com/problems/basic-calculator-ii/discuss/63000/My-28ms-C%2B%2B-code-with-two-stacks-(one-for-op-one-for-oprand)-extension-to-cover-'('-and-')'-also-given
