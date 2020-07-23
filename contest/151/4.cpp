class DinnerPlates {
public:
  DinnerPlates(int capacity) {
    size = capacity;
  }
    
  void push(int val) {
    if (usable.size() == 0) {
      usable.insert(plate.size());
    }
    int target = *(usable.begin());
    plate[target].push_back(val);
    if (plate[target].size() == size) {
      usable.erase(target);
    }
  }
    
  int pop() {
    while (plate.size() > 0 && plate.rbegin()->second.size() == 0) {
      plate.erase(plate.rbegin()->first);
    }
    if (plate.size() == 0) return -1;
    int target = plate.rbegin()->first;
    int res = popAtStack(target);
    return res;
  }
    
  int popAtStack(int index) {
    if (plate[index].size() == 0) return -1;
    int top = plate[index].back();
    plate[index].pop_back();
    usable.insert(index);
    return top;
  }
  
private:
  int size;
  map<int, vector<int>> plate;
  set<int> usable;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
