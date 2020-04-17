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
  /** Initialize your data structure here. */
  Trie() {
    root = new Node();
  }
    
  /** Inserts a word into the trie. */
  void insert(string word) {
    Node *now = root;
    for (char c : word) {
      if (!now->node[c - 'a']) {
        now->node[c - 'a'] = new Node();
      }
      now = now->node[c - 'a'];
    }
    now->is_word = true;
  }
    
  /** Returns if the word is in the trie. */
  bool search(string word) {
    Node *now = root;
    for (char c : word) {
      if (!now->node[c - 'a']) {
        return false;
      }
      now = now->node[c - 'a'];
    }
    return now->is_word;
  }
    
  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix) {
    Node *now = root;
    for (char c : prefix) {
      if (!now->node[c - 'a']) {
        return false;
      }
      now = now->node[c - 'a'];
    }
    return true;
  }
private:
  Node *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
