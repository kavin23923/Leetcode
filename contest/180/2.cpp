class CustomStack {
public:
  CustomStack(int maxSize) {
    size = maxSize;
  }

  void push(int x) {
    if (my_stack.size() < size) {
      my_stack.push_back(x);
    }
  }

  int pop() {
    if (my_stack.size() == 0) {
      return -1;
    } else {
      int res = my_stack.back();
      my_stack.pop_back();
      return res;
    }
  }

  void increment(int k, int val) {
    int s = my_stack.size();
    for (int i = 0; i < k && i < s; i++) {
      my_stack[i] += val;
    }
  }
  
private:
  vector<int> my_stack;
  int size;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
