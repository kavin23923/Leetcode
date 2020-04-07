class Solution {
public:
  int leastInterval(vector<char>& tasks, int n) {
    int res = 0, max_event = 0;
    int count[26] = {0};
    
    for (char c : tasks) {
      count[c - 'A']++;
    }
    sort(count, count + 26, greater<int>());
    
    for (int i = 0; i < 26 && count[i] == count[0]; i++) {
      max_event++;
    }
  
    return max((int)tasks.size(), (n + 1) * (count[0] - 1) + max_event);
  }
};
/**
 * Can also use greedy and heap to get top n+1 events to solve 
 */
