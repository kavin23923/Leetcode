class Trie {
public:
  bool is_word;
  Trie *node[26];
  
  Trie() {
    for (int i = 0; i < 26; i++) {
      node[i] = NULL;
    }
    is_word = false;
  }
};

class WordDictionary {
public:
  /** Initialize your data structure here. */
  WordDictionary() {
    root = new Trie();
  }
    
  /** Adds a word into the data structure. */
  void addWord(string word) {
    Trie *tmp = root;
    for (char c : word) {
      if (!tmp->node[c - 'a']) {
        tmp->node[c - 'a'] = new Trie();
      }
      tmp = tmp->node[c - 'a'];
    }
    tmp->is_word = true;
  }
    
  /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
  bool search(string word) {
    return my_search(word, 0, root);
  }
private:
  Trie *root;
  
  bool my_search(string& word, int now, Trie *t) {
    if (word.size() == now) {
      return t->is_word;
    }
    char c = word[now];
    if (c == '.') {
      for (int i = 0; i < 26; i++) {
        if (t->node[i] && my_search(word, now + 1, t->node[i])) {
          return true;
        }
      }
      return false;
    } else{
      if (!t->node[c - 'a']) {
        return false;
      } else {
        return my_search(word, now + 1, t->node[c - 'a']);
      }
    }
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
