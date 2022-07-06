class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int  N = nums.size();
        int currentSum =0;
        int GlobalSum =INT_MIN;
        
        
        
        for(int i= 0 ; i<N; i++){
            
           
            
            if(currentSum < 0){
                currentSum=0;
            }
            
            currentSum=currentSum+nums[i];
            
        
            if(GlobalSum < currentSum){
                GlobalSum=currentSum;
            }
        }
        
        return GlobalSum;
        
        
        
    }
};