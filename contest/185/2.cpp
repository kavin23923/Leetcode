class Solution {
public:
  vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    vector<vector<string>> res;
    set<string> food;
    unordered_map<string, int> mapping; 
    map<int, vector<int>> count;
    
    for (auto &v : orders) {
      food.insert(v[2]);
    }
    int now = 0;
    vector<string> first;
    first.push_back("Table");
    for (auto s : food) {
      mapping[s] = now++;
      first.push_back(s);
    }
    res.push_back(first);
    
    for (auto &v : orders) {
      int table = stoi(v[1]);
      if (count.find(table) == count.end()) {
        count[table] = vector<int>(food.size());
      }
      count[table][mapping[v[2]]]++;
    }
    
    for (auto it = count.begin(); it != count.end(); it++) {
      vector<string> tmp;
      tmp.push_back(to_string(it->first));
      for (int num : it->second) {
        tmp.push_back(to_string(num));
      }
      res.push_back(tmp);
    }
    
    return res;
  }
};
