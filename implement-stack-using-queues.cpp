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