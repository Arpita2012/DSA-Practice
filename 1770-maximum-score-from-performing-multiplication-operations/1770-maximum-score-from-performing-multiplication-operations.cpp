class Solution {
public:
    
    
    /*int MAX_UTIL(vector<int>& nums, vector<int>& multipliers,int num_strt, int num_end, int mul_str){
        
        if(mul_str == multipliers.size()){
            return 0;
            
        }
        
        return max(nums[num_strt] *multipliers[mul_str] + MAX_UTIL(nums,multipliers, num_strt+1, num_end, mul_str+1) , 
        nums[num_end] *multipliers[mul_str] + MAX_UTIL(nums,multipliers, num_strt, num_end-1, mul_str+1) );
        
        
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        return MAX_UTIL (nums, multipliers, 0, nums.size()-1 , 0);
  
        
    }*/
    
        vector<vector<int>> dp;
    int solve(int i, int n, int j, vector<int> &nums, vector<int> &multipliers){
        if (j == multipliers.size()) return 0;
        if (dp[i][j] != INT_MIN) return dp[i][j];
        int left = solve(i + 1, n, j + 1, nums, multipliers) + (nums[i] * multipliers[j]);
        int right = solve(i, n, j + 1, nums, multipliers) + (nums[(n - 1) - (j - i)] * multipliers[j]);
        return dp[i][j] = max(left, right);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {   
        int n = nums.size(), m = multipliers.size();
        dp.resize(m + 1, vector<int>(m + 1, INT_MIN));
        return solve(0, n, 0, nums, multipliers);
    }

    
};
