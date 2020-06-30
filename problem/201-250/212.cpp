class Solution {
public:
  class Node {
    public:
      Node *node[26];
      bool is_word;
    
      Node() {
        for (int i = 0; i < 26; i++) {
          node[i] = NULL;
        }
        is_word = false;
      }
  };
  
  class Trie {
    public:
      Node *root;
    
      Trie() {
        root = new Node();
      }
    
      void insert(string &word) {
        Node *now = root;
        for (char c : word) {
          if (now->node[c - 'a'] == NULL) {
            now->node[c - 'a'] = new Node();
          }
          now = now->node[c - 'a'];
        }
        now->is_word = true;
      }
  };
  
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    m = board.size();
    n = m == 0 ? 0 : board[0].size();
    vector<string> res;
    string tmp = "";
    Trie *trie = new Trie();
    
    for (string &s : words) {
      trie->insert(s);
    }
    
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        dfs(board, i, j, trie->root, tmp, res);
      }
    }
    
    return res;
  }
  
  void dfs(vector<vector<char>>& board, int i, int j, Node* root, string &tmp, vector<string> &res) {
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '.') {
      return;
    }
    char c = board[i][j];
    if (root->node[c - 'a'] == NULL) return;
    
    tmp += c;
    if (root->node[c - 'a']->is_word) {
      root->node[c - 'a']->is_word = false; // avoid duplication
      res.push_back(tmp);
    }
    
    board[i][j] = '.';
    Node* now = root->node[c - 'a'];
    dfs(board, i + 1, j, now, tmp, res);
    dfs(board, i - 1, j, now, tmp, res);
    dfs(board, i, j + 1, now, tmp, res);
    dfs(board, i, j - 1, now, tmp, res);
    board[i][j] = c;
    tmp.pop_back();
  }
  
private:
  int m, n;
};
