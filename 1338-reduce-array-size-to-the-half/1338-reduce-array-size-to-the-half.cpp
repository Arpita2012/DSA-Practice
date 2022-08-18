class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        int N = arr.size();
        priority_queue<pair<int,int>> pq;
        map<int,int> M;
        
        for(int i=0 ; i< N; i++){
            M[arr[i]]++;
        }
        
        for(auto x : M){
            pq.push({x.second, x.first});
        }
        
        
        int MAX_FREQ=0;
        
        set<int> S;
        
        while(!pq.empty()){
            pair <int,int> P = pq.top();
            pq.pop();
            
            S.insert(P.second);
            MAX_FREQ+= P.first;
            
            if(MAX_FREQ>=N/2){
                break;
            }
            
            
        }
        
        return S.size();

        
        
    }
};