class RandomizedSet {
public:
  /** Initialize your data structure here. */
  RandomizedSet() {

  }

  /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
  bool insert(int val) {
    auto it = mapping.find(val);
    if (it != mapping.end()) {
      return false;
    }
    data.push_back(val);
    mapping[val] = data.size() - 1;
    return true;
  }

  /** Removes a value from the set. Returns true if the set contained the specified element. */
  bool remove(int val) {
    auto it = mapping.find(val);
    if (it == mapping.end()) {
      return false;
    }
    int last = data.back();
    mapping[last] = it->second;
    data[it->second] = last;
    data.pop_back();
    mapping.erase(val);
    return true;
  }

  /** Get a random element from the set. */
  int getRandom() {
    int size = mapping.size();
    return data[rand() % size];
  }

private:
  vector<int> data;
  unordered_map<int, int> mapping;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

/**
 * The key is the erase for the last element in vector is O(1).
 * So we move the last element to the target number position, and pop_back().
 */
