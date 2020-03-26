class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int size = nums.size(), index;
    vector<int> tmp, res(size, -1);
    
    for (int i = 0; i < size * 2; i++) {
      index = i % size;
      while (tmp.size() != 0 && nums[tmp.back()] < nums[index]) {
        res[tmp.back()] = nums[index];
        tmp.pop_back();
      }
      if (i < size) {
        tmp.push_back(index);
      }
    }

    return res;
  }
};
/**
 * Just use vector as stack.
 * Store index in tmp vector, then we do not have to store (index,value) pair.
 */
