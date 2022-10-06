class TimeMap {
public:
  map<string, map<int,string>> M;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        M[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
       

        if(M[key].find(timestamp)!=M[key].end()){
            return M[key][timestamp];
        }

        int prev = timestamp-1;
        string value;
        
        while(prev>=1){
              if(M[key].find(prev)!=M[key].end()){
                    return M[key][prev];
              }
              prev-=1;
              
        
        }
      
        return "";
        
//         for(auto t_v : M[key]){
//             if(t_v.first < timestamp){
//                 prev = t_v.first;
//                 value = t_v.second;
                
//             }
//         }
//         return value;
        
    }

};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */