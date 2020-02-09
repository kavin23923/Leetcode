class TweetCounts {
public:
  TweetCounts() {
    
  }

  void recordTweet(string tweetName, int time) {
    tweet[tweetName][time]++;
  }

  vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
    int f = 86400;
    if (freq == "minute") {
      f = 60;
    } else if (freq == "hour") {
      f = 3600;
    }
    vector<int> res((endTime - startTime) / f + 1, 0);
    
    auto it = tweet[tweetName].lower_bound(startTime);
    while (it != tweet[tweetName].end() && it->first <= endTime) {
      res[(it->first - startTime) / f] += it->second;
      it++;
    }
    return res;
  }

private:
  unordered_map<string, map<int, int>> tweet;
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
