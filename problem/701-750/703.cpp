class KthLargest {
public:
  KthLargest(int k, vector<int>& nums) {
    for (int n : nums) {
      stream.push(n);
      if (stream.size() > k) {
        stream.pop();
      }
    }
    K = k;
  }
    
  int add(int val) {
    stream.push(val);
    if (stream.size() > K) {
      stream.pop();
    }
    return stream.top();
  }
  
private:
  int K;
  priority_queue<int, vector<int>, greater<int>> stream;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
