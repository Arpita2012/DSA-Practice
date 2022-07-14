class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue <int> pq;
        
        for(auto x:stones){
            pq.push(x);
        }
        
        while(1){
            
            if(pq.size()==1){
                return pq.top();
            }
            
            
            int x =pq.top();
            pq.pop();
            int y =pq.top();
            pq.pop();
            
            
            if(x!=y){
                
                pq.push(x-y);
            }
            
            if(pq.empty()){
                return 0;
            }
            
            if(pq.size()==1){
                return pq.top();
            }
            
            
            
        }
        
    }
};