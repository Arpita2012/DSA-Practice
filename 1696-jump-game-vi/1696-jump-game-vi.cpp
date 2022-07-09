class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
       
        int N = nums.size();
        
        int * dp = new int[N];
        
        fill_n(dp,N,INT_MIN);
        
             
        
        // M2 using priority queue
        
        priority_queue <pair<int,int>> pq;
        //NOTE : first element of pair will decide the priority
        
        for(int i=N-1 ; i>=0  ; i--){
           
            
           while(pq.size() && pq.top().second >(i+k) )
               pq.pop();
            
            dp[i]=nums[i];
            if(pq.size()){
            
                dp[i]=dp[i] +  pq.top().first;
            }
            
            pq.push({ dp[i],i});

            
        }
        
        return dp[0];
        
    
        
        
        
        
        /* M1 - TLE 
        dp[N-1]=nums[N-1];
        
        for(int i=N-2 ; i>=0  ; i--){
            
            int track =i+1;
            
            int maxdp = INT_MIN;
            
            while(track<=min(N-1 , i+k)){
                if(dp[track]>maxdp){
                    maxdp=dp[track];
                }
                track++;
            }
            
            dp[i]=nums[i]+maxdp;

        }
        
        return dp[0];
        */
        
    }
};