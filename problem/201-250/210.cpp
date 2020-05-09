class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> res;
    vector<int> course(numCourses, 0); // white
    vector<vector<int>> require(numCourses, vector<int>());
    
    for (auto &v : prerequisites) {
      require[v[1]].push_back(v[0]);
    }
    
    for (int i = 0; i < numCourses; i++) {
      if (!course[i] && !dfs(numCourses, res, course, require, i)) {
        return {};
      }
    }
    
    reverse(res.begin(), res.end());
    return res;
  }
  
  bool dfs(int numCourses, vector<int>& res, vector<int> &course, vector<vector<int>> &require, int target) {
    if (course[target] == -1) {
      return true;
    }
    course[target] = 1; // gray
    
    for (int i = 0; i < require[target].size(); i++) {
      if (course[require[target][i]] == 1 || !dfs(numCourses, res, course, require, require[target][i])) {
        return false;
      } 
    }
    
    course[target] = -1; // black
    res.push_back(target);
    return true;
  }
};
