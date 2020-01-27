class Solution {
public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    // Floyd–Warshall algorithm
    int size = edges.size();
    int i, j, k;
    vector<vector<int> > dist(n, vector<int>(n, 1e9));
    
    for (i = 0; i < size; i++) { 
      dist[edges[i][0]][edges[i][1]] = edges[i][2];
      dist[edges[i][1]][edges[i][0]] = edges[i][2];
    }
    for (i = 0; i < n; i++) {
      dist[i][i] = 0;
    }
    
    for (k = 0; k < n; k++) {
      for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    
    int res, smallest = INT_MAX, count;
    for (i = 0; i < n; i++) {
      count = 0;
      for (j = 0; j < n; j++) {
        if (dist[i][j] <= distanceThreshold) {
          count++;
        }
      }
      if (count <= smallest) {
        smallest = count;
        res = i;
      }
    }
    
    return res;
  }
};
