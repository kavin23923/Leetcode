class RecentCounter {
public:
  RecentCounter() {
    
  }
    
  int ping(int t) {
    event.push(t);
    while (event.front() + 3000 < t) {
      event.pop();
    }
    return event.size();
  }
  
private:
  queue<int> event;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
