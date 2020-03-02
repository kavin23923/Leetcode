class Solution {
public:
  string largestMultipleOfThree(vector<int>& digits) {
    string ans = "";
    vector<int> count(10, 0);
    int total = 0;

    for (int n : digits) {
      total += n;
      count[n]++;
    }

    if (total == 0) {
      return digits.size() == 0 ? ans : "0";
    }

    if (total % 3 == 1) {
      removeNumber(count, &total, 1);
    } else if (total % 3 == 2) {
      removeNumber(count, &total, 2);
    }

    if (total % 3 != 0) {
      removeNumber(count, &total, 1);
      removeNumber(count, &total, 1);
      removeNumber(count, &total, 2);
      removeNumber(count, &total, 2);
    }

    for (int i = 9; i >= 0; i--) {
      for (int j = 0; j < count[i]; j++) {
        ans += i + '0';
      }
    }
    return total % 3 == 0 ? ans : "";
  }
  
  void removeNumber(vector<int> &count, int* total, int base) {
    if (count[base] > 0) {
      count[base]--;
      *total -= base;
    } else if (count[base + 3] > 0) {
      count[base + 3]--;
      *total -= base + 3;
    } else if (count[base + 6] > 0) {
      count[base + 6]--;
      *total -= base + 6;
    }
  }
};
