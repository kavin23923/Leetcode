class LRUCache {
public:
  LRUCache(int capacity) {
    max_size = capacity;
  }

  int get(int key) {
    int res = -1;
    if (cache.find(key) != cache.end()) {
      res = cache[key].first;
      order.erase(cache[key].second);
      order.push_front(key);
      cache[key].second = order.begin();
    }
    return res;
  }

  void put(int key, int value) {
    if (cache.find(key) != cache.end()) {
      order.erase(cache[key].second);
    }
    order.push_front(key);
    cache[key] = make_pair(value, order.begin());
    
    if (cache.size() > max_size) {
      cache.erase(order.back());
      order.pop_back();
    }
  }
  
private:
  int max_size;
  list<int> order;
  unordered_map<int, pair<int, list<int>::iterator>> cache; 
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Push the new thing into the front, and pop the old thing from the back.
 * It can reduce one iterator update.
 */
