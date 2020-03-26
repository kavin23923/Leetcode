class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() {
        
  }
    
  void push(int x) {
    if (min_stack.empty() || x <= min_stack.top()) {
      min_stack.push(x);
    }
    all.push(x);
  }
    
  void pop() {
    if (min_stack.top() == all.top()) {
      min_stack.pop();
    }
    all.pop();
  }
    
  int top() {
    return all.top();
  }
    
  int getMin() {
    return min_stack.top();
  }
private:
  stack<int> all;
  stack<int> min_stack;  
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
