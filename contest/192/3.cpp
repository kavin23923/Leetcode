class BrowserHistory {
public:
  BrowserHistory(string homepage) {
    history.push_back(homepage);
    now = history.begin();
  }
    
  void visit(string url) {
    auto tmp = now; tmp++;
    history.erase(tmp, history.end());
    history.push_back(url);
    now++;
  }
    
  string back(int steps) {
    for (int i = 0; i < steps; i++, now--) {
      if (now == history.begin()) {
        break;
      }
    }
    return *now;
  }
    
  string forward(int steps) {
    for (int i = 0; i < steps; i++, now++) {
      auto tmp = now; tmp++;
      if (tmp == history.end()) {
        break;
      }
    }
    return *now;
  }
  
private:
  list<string> history;
  list<string>::iterator now;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
