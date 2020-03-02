class Solution {
public:
  int daysBetweenDates(string date1, string date2) {
    int day1 = days(date1);
    int day2 = days(date2);
    return abs(day1 - day2);
  }
  
  int days(string date) {
    int res = 0;
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8, 2));
    for (int i = 1971; i < year; i++) {
      if (i % 4 == 0) {
        res += 366;
      } else {
        res += 365;
      }
    }
    for (int i = 1; i < month; i++) {
      if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10) {
        res += 31;
      } else if (i == 4 || i == 6 || i == 9 || i == 11) {
        res += 30;
      } else {
        if (year % 4 == 0) {
          if (year % 100 == 0 && year % 400 != 0) {
            res += 28;
          } else {
            res += 29;
          }
        } else {
          res += 28;
        }
      }
    }
    return res + day;
  }
};
