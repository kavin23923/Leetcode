class Solution {
public:
  string entityParser(string text) {
    string res = "";
    int now = 0, len = text.size();
    
    while (now < len) {
      if (text[now] != '&') {
        res += text[now++];
      } else{
        if (now + 6 <= len && text[now + 1] == 'q' && text.substr(now, 6) == "&quot;") {
          res += '"';
          now += 6;
        } else if (now + 6 <= len && text[now + 1] == 'a' && text.substr(now, 6) == "&apos;") {
          res += '\'';
          now += 6;
        } else if (now + 5 <= len && text[now + 1] == 'a' && text.substr(now, 5) == "&amp;") {
          res += '&';
          now += 5;
        } else if (now + 4 <= len && text[now + 1] == 'g' && text.substr(now, 4) == "&gt;") {
          res += '>';
          now += 4;
        } else if (now + 4 <= len && text[now + 1] == 'l' && text.substr(now, 4) == "&lt;") {
          res += '<';
          now += 4;
        } else if (now + 7 <= len && text[now + 1] == 'f' && text.substr(now, 7) == "&frasl;") {
          res += '/';
          now += 7;
        } else {
          res += text[now++];
        }
      }
    }
    
    return res;
  }
};
