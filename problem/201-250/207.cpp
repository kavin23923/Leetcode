class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> course(numCourses, 0); // white
    vector<vector<int>> require(numCourses, vector<int>());
    
    for (auto &v : prerequisites) {
      require[v[1]].push_back(v[0]);
    }
    
    for (int i = 0; i < numCourses; i++) {
      if (!course[i] && !dfs(numCourses, course, require, i)) {
        return false;
      }
    }
    
    return true;
  }
  
  bool dfs(int numCourses, vector<int> &course, vector<vector<int>> &require, int target) {
    if (course[target] == -1) {
      return true;
    }
    course[target] = 1; // gray
    
    for (int i = 0; i < require[target].size(); i++) {
      if (course[require[target][i]] == 1 || !dfs(numCourses, course, require, require[target][i])) {
        return false;
      } 
    }
    
    course[target] = -1; // black
    return true;
  }
};
