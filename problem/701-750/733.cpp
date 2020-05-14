class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    m = image.size();
    n = image[0].size();
    if (newColor != image[sr][sc]) {
      dfs(image, sr, sc, image[sr][sc], newColor);
    }
    return image;
  }
  
  void dfs(vector<vector<int>>& image, int x, int y, int target, int newColor) {
    if (image[x][y] != target) return;
    image[x][y] = newColor;
    if (x - 1 >= 0) dfs(image, x - 1, y, target, newColor);
    if (x + 1 < m) dfs(image, x + 1, y, target, newColor);
    if (y - 1 >= 0) dfs(image, x, y - 1, target, newColor);
    if (y + 1 < n) dfs(image, x, y + 1, target, newColor);
  }
private:
  int m, n;
};
