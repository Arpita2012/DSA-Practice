#define pis pair<int,string> 
/*class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        map<string,int> m;
        
        vector<pair<string,int>> v(k,{"",-1});
         vector <string> ans(k,"");
        
        for(auto x : words){
            if(m.find(x)==m.end()){
                m[x]=1;
            }else{
                m[x]++;
            }
            
            
            
        }
        int i=0;
        for (auto r = m.rbegin(); r != m.rend(); ++r)  
        { ans[i%k]=r->first;
           
            i++;
            if(i==k){
                break;
            }
        }
            
        
        for(auto yy : ans){
            cout<<yy<<endl;
        }
        
        
       sort(ans.rbegin(),ans.rend());
        
        return ans;
        
        
       
        
        
        
    }
};*/

class myComparator {
  public:
    bool operator() (const pis &p1, const pis &p2) {
      if(p1.first == p2.first) return p1.second < p2.second;
      
      return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
   
        priority_queue<pis,vector<pis>,myComparator> pq;
        map<string,int> mp;
        for(auto i:words) mp[i]++;
        for(auto i:mp) {
            pq.push({i.second,i.first});
            if(pq.size()>k) pq.pop();
        }
     
        vector<string> ans(k);
        while(pq.empty()==false and k--){
            
            auto i = pq.top();
            pq.pop();
            ans[k]=i.second;
        }
       
        return ans;
    }
};