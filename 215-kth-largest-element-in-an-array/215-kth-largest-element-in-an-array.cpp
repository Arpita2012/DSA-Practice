class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        
        int n = nums.size();
        
        map<int,int> M;
        
        for(auto x : nums){
            if(M.find(x)==M.end()){
                M[x]=1;
                
            }else{
                M[x]++;
            }
        }
        
       
        int j=0;
        int largest = -1; 
        for(auto m : M){
            largest = m.first;
            j = j + m.second;
            if(j>= n-k+1 ){
                break;
            }
            
           
            
            
        }
        
        
        return largest;
        
        
    }
};