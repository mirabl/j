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
class LLNode {
public:
    int val;
    LLNode *next;
    LLNode(int v): val(v), next(NULL) {}
};

class MyQueue {
public:
    LLNode *front;
    LLNode *back;
    /** Initialize your data structure here. */
    MyQueue() {
        front = NULL;
        back = NULL;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        LLNode* n = new LLNode(x);
        if (back) {
            back->next = n;
        }
        back = n;
        if (!front) {
            front = back;
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = front->val;
        
        if (front->next) {
            LLNode *p = front->next;
            delete(front);
            front = p;
        } else {
            delete(front);
            front = NULL;
            back = NULL;
        }
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return front->val;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return front == NULL;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
