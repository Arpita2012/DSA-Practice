class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<int> R(nums.size(),0);
        
        if(nums.size()==1){
            return nums[0];
        }
        /* M1
        R[0]=nums[0];
        R[1]=max(nums[0],nums[1]);
        for(int i=2 ;i<nums.size(); i++){
            R[i]=max(nums[i]+ R[i-2],R[i-1]);
        }
        
        return R[nums.size()-1];
        */
        
        //M2
        
        int MAX=0;
        int prev_prev =nums[0];
        //int prev =nums[1];
        MAX=max(nums[1],prev_prev);
        
        for(int i=2 ;i<nums.size(); i++){
            int t = MAX;
            MAX= max(nums[i]+ prev_prev, MAX );
            prev_prev=t;
            
        }
        return MAX;
        
        
        
    }
};