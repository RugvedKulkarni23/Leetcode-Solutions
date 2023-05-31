class UndergroundSystem {
public:
      map<int,pair<string,int>> mp; 
    map<int,pair<string,int>> mp1; 
     map<pair<string,string>,int> mp2 ,mp3;
   
    UndergroundSystem() {
  
    }
    
    void checkIn(int id, string stationName, int t) {
            mp[id]={stationName,t};   
    }
    
    void checkOut(int id, string stationName, int t) {
           mp1[id]={stationName,t};
           if(mp.find(id)!=mp.end()){
               string s1= mp[id].first;
               string s2= mp1[id].first;
               int x1= mp1[id].second;
               int x2= mp[id].second;
               mp2[{s1,s2}]+= (x1-x2);
               mp3[{s1,s2}]++;
           }
    }
    
    double getAverageTime(string startStation, string endStation) {
          double x= mp2[{startStation,endStation}];
          double y= mp3[{startStation,endStation}];
        return (x/y);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */