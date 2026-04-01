class MedianFinder {
public:
    std::priority_queue<int> max_heap;
    std::priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {}
    
    void addNum(int num) {
        max_heap.push(num);

        if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top()) {
            int tmp = max_heap.top();
            max_heap.pop();
            min_heap.push(tmp);
        }

        if (max_heap.size() > min_heap.size() + 1) {
            int tmp = max_heap.top();
            max_heap.pop();
            min_heap.push(tmp);
        }
        
        if (min_heap.size() > max_heap.size() + 1) {
            int tmp = min_heap.top();
            min_heap.pop();
            max_heap.push(tmp);
        }
    }
    
    double findMedian() {
        if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        } else if (max_heap.size() < min_heap.size()) {
            return min_heap.top();
        } else {
            return (double)(max_heap.top() + min_heap.top()) / 2;
        }
    }
};
