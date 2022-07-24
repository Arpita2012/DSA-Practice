class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int> res(nums.size(), 1);
        
        
        int prev_prod = 1;
        for(int i = 0; i < nums.size(); i++){
            res[i] = prev_prod;
            prev_prod *= nums[i];
        }
        
        
        int next_prod = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            res[i] *= next_prod;
            next_prod*= nums[i];
        }
        return res;
        
    }
};