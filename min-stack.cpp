/*
https://leetcode.com/problems/min-stack/
155. Min Stack   Add to List QuestionEditorial Solution  My Submissions
Total Accepted: 104560
Total Submissions: 401523
Difficulty: Easy
Contributors: Admin
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

alias a='g++ -Wall min_stack.cpp && ./a.out'
*/
#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
	stack<int> main;
	stack<int> mins;
    MinStack() {
        
    }
    
    void push(int x) {
        main.push(x);
        if (mins.empty() || x <= getMin()) {
        	mins.push(x);
        }
    }
    
    void pop() {
    	if (top() == getMin()) {
    		mins.pop();
    	}
        main.pop();
    }
    
    int top() {
    	return main.top();
    }
    
    int getMin() {
		return mins.top();        
    }
};

int main() {
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-3);
	cout << minStack.getMin() << endl;;  // --> Returns -3.
	minStack.pop();
	cout << minStack.top() << endl;     // --> Returns 0.
	cout << minStack.getMin() << endl;  // --> Returns -2.
}
