class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {}
    void addNum(int val) {
        if (maxHeap.empty() || val < maxHeap.top()){
            maxHeap.push(val);
        }
        else{
            minHeap.push(val);
        }

        if (maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
        return ;
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top())/2.0;
        }
        return (double) maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */