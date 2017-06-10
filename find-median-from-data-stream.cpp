class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> A; // max heap
    priority_queue<int> B; // min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (A.empty() || num <= A.top()) {
            A.push(num);
        } else {
            B.push(- num);
        }
        int d = A.size() - B.size();
        if (d == 2) {
            B.push(- A.top());
            A.pop();
        } else if (d == -2) {
            A.push(- B.top());
            B.pop();
        }
    }
    
    double findMedian() {
        int d = A.size() - B.size();
        if (d == 1) {
            return A.top();
        } else if (d == -1) {
            return - B.top();
        } else {
            return (A.top() - B.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */