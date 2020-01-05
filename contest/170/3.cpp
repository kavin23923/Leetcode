class Solution {
public:
  vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
    vector<string> res;
    unordered_map<string, int> count;
    unordered_set<int> exist;
    set<pair<int, string>> tmp;
    
    exist.insert(id);
    bfs(watchedVideos, friends, id, level, count, exist);
    
    for (auto it = count.begin(); it != count.end(); it++) {
      tmp.insert(make_pair(it->second, it->first));
    }
    for (auto it = tmp.begin(); it != tmp.end(); it++) {
      res.push_back(it->second);
    }
    
    return res;
  }
  
  void bfs(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level, unordered_map<string, int>& count, unordered_set<int>& exist) {
    queue<int> target;
    target.push(id);
    int i;
    int j;
    int k;
    int f;
    int size;
    
    for (i = 0; i < level; i++) {
      size = target.size();
      for (j = 0; j < size; j++) {
        f = target.front();
        target.pop();
        for (k = 0; k < friends[f].size(); k++) {
          if (exist.find(friends[f][k]) == exist.end()) {
            exist.insert(friends[f][k]);
            target.push(friends[f][k]);
          }
        }
      }
    }
    
    while (!target.empty()) {
      f = target.front();
      target.pop();
      for (int i = 0; i < watchedVideos[f].size(); i++) {
        count[watchedVideos[f][i]]++;
      }
    }
  } 
};