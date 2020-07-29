class FreqStack {
public:
  FreqStack() {
        
  }
    
  void push(int x) {
    count[x]++;
    mfreq = max(mfreq, count[x]);
    fstack[count[x]].push(x);
  }
    
  int pop() {
    int res = fstack[mfreq].top();
    fstack[mfreq].pop();
    count[res]--;
    if (fstack[mfreq].empty()) mfreq--;
    return res;
  }
  
private:
  unordered_map<int, int> count;
  unordered_map<int, stack<int>> fstack;
  int mfreq = 0;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
