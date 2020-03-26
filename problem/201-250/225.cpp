class MyStack {
public:
  /** Initialize your data structure here. */
  MyStack() {

  }

  /** Push element x onto stack. */
  void push(int x) {
    while (!main.empty()) {
      tmp.push(main.front());
      main.pop();
    }
    main.push(x);
    while (!tmp.empty()) {
      main.push(tmp.front());
      tmp.pop();
    }
  }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    int top = main.front();
    main.pop();
    return top;
  }

  /** Get the top element. */
  int top() {
    return main.front();
  }

  /** Returns whether the stack is empty. */
  bool empty() {
    return main.empty();
  }

private:
  queue<int> main;
  queue<int> tmp;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
