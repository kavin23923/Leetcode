class Solution {
public:
  int scheduleCourse(vector<vector<int>>& courses) {
    auto cmp = [](vector<int> &a, vector<int> &b) {
      return a[1] < b[1];
    };
    priority_queue<int> course_now;
    int now = 0, n = courses.size();
    
    sort(courses.begin(), courses.end(), cmp);
    
    for (int i = 0; i < n; i++) {
      if (now + courses[i][0] <= courses[i][1]) {
        now += courses[i][0];
        course_now.push(courses[i][0]);
      } else if (!course_now.empty() && course_now.top() > courses[i][0]) {
        now = now - course_now.top() + courses[i][0];
        course_now.pop();
        course_now.push(courses[i][0]);
      }
    }
    
    return course_now.size();
  }
};
