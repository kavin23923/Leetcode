class MedianFinder {
public:
  /** initialize your data structure here. */
  MedianFinder() {
        
  }
    
  void addNum(int num) {
    first.push(num);
    second.push(first.top());
    first.pop();
    if (first.size() < second.size()) {
      first.push(second.top());
      second.pop();
    }
  }
    
  double findMedian() {
    return first.size() == second.size() ? (first.top() + second.top()) / 2.0 : first.top();
  }
  
private:
  priority_queue<int, vector<int>> first;
  priority_queue<int, vector<int>, greater<int>> second;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
