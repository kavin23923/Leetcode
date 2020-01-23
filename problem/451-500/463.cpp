class Solution {
public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int m = grid.size();
	int n = m == 0 ? 0 : grid[0].size();
	int peri = 0;
	int i, j, count;

	for (i = 0; i < m; i++) {
	  for (j = 0; j < n; j++) {
	    if (grid[i][j] == 0) {
		  continue;
		}
	    count = 4;
		if (i - 1 >= 0 && grid[i - 1][j] == 1) count--;
		if (i + 1 < m && grid[i + 1][j] == 1) count--;
		if (j - 1 >= 0 && grid[i][j - 1] == 1) count--;
		if (j + 1 < n && grid[i][j + 1] == 1) count--;
		peri += count;
	  }
	}
	return peri;
  }
};
