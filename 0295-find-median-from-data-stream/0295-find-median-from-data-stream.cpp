class MedianFinder {
public:
    
    vector<int> arr;
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    double median;
    int signum(int a, int b){
        if (a > b) return 1;
        else if (a < b) return -11;
        else return 0;
    }
    double avg(int a, int b){
        return (a+b)/(2.0); 
    }
    MedianFinder() {
        median = 0;
    }
    
    void addNum(int num) {
        if (maxHeap.size() == 0 && minHeap.size() == 0){
            maxHeap.push(num);
            median = num;
            return ;
        }

        int x = signum(maxHeap.size(), minHeap.size());
        if (x == 0){
            if (num > median){
                minHeap.push(num);
                median = minHeap.top();
            }
            else{
                maxHeap.push(num);
                median = maxHeap.top();
            }
        }
        else if (x > 0){
            if (num > median){
                minHeap.push(num);
                median = avg(minHeap.top(), maxHeap.top());
            }
            else{
                int topEle = maxHeap.top(); maxHeap.pop();
                minHeap.push(topEle);
                maxHeap.push(num);
                median = avg(minHeap.top(), maxHeap.top());
            }
        }
        else{
            if (num > median){
                int topEle = minHeap.top(); minHeap.pop();
                maxHeap.push(topEle);
                minHeap.push(num);
                median = avg(minHeap.top(), maxHeap.top());
            }
            else{
                maxHeap.push(num);
                median = avg(minHeap.top(), maxHeap.top());
            }
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */