class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> A;
    MyStack() {
            
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        A.push(x);
        for (int i = 0; i < int(A.size()) - 1; i++) {
            A.push(A.front());
            A.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = A.front();
        A.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return A.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return A.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

struct LLNode {
    int val;
    LLNode* next;
    LLNode(int v): val(v), next(NULL) {}
    LLNode(): LLNode(0) {}
};

class MyStack {
public:
    LLNode* head;
    
    /** Initialize your data structure here. */
    MyStack() {
        head = NULL;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        auto n = new LLNode(x);
        n->next = head;
        head = n;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int v = head->val;
        head = head->next;
        return v;
    }
    
    /** Get the top element. */
    int top() {
        return head->val;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return head == NULL;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
