class UndergroundSystem {
public:
  UndergroundSystem() {

  }

  void checkIn(int id, string stationName, int t) {
    if (cust.find(id) == cust.end()) {
      cust[id] = make_pair(stationName, t);
    }
  }

  void checkOut(int id, string stationName, int t) {
    string station = cust[id].first + stationName;
    int time = t - cust[id].second;
    cust.erase(id);
    if (aver.find(station) == aver.end()) {
      aver[station] = make_pair(time, 1);
    } else {
      aver[station].first += time;
      aver[station].second += 1;
    }
  }

  double getAverageTime(string startStation, string endStation) {
    string station = startStation + endStation;
    return (double) aver[station].first / aver[station].second;
  }
  
private:
  unordered_map<int, pair<string, int>> cust;
  unordered_map<string, pair<int, int>> aver;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
