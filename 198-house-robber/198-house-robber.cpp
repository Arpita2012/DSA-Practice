class Solution {
public:
    int rob(vector<int>& nums) {
        
        vector<int> R(nums.size(),0);
        
        if(nums.size()==1){
            return nums[0];
        }
        
        R[0]=nums[0];
        R[1]=max(nums[0],nums[1]);
        for(int i=2 ;i<nums.size(); i++){
            R[i]=max(nums[i]+ R[i-2],R[i-1]);
        }
        
        return R[nums.size()-1];
        
        
        
    }
};