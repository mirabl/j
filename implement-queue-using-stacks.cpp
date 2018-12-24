class MyQueue {
public:
    stack<int> A;
    stack<int> B;
    
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        A.push(x);    
    }
    
    void fill() {
        while (!A.empty()) {
            int x = A.top();
            A.pop();
            B.push(x);
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (B.empty()) {
            fill();
        }
        int x = B.top();
        B.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if (B.empty()) {
            fill();
        }
        return B.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return A.empty() && B.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */