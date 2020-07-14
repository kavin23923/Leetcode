class Solution {
public:
  string dayOfTheWeek(int day, int month, int year) {
    // 1971 1 1 : Friday
    unordered_map<int, string> value = {{3, "Sunday"}, {4, "Monday"}, {5, "Tuesday"}, {6, "Wednesday"}, {0, "Thursday"}, {1, "Friday"}, {2, "Saturday"}}; 
    int res = 0;
    
    for (int i = 1971; i < year; i++) {
      if (i % 4 != 0 || (i % 100 == 0 && i % 400 != 0)) {
        res += 365;
      } else {
        res += 366;
      }
    }
    
    for (int i = 1; i < month; i++) {
      if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
        res += 31;
      } else if (i == 4 || i == 6 || i ==9 || i == 11){
        res += 30;
      } else {
        if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) {
          res += 28;
        } else {
          res += 29;
        }
      }
    }
    
    res += day;
    
    return value[res % 7];
  }
};
