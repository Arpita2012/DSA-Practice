class Solution {
public:
    vector<vector<int>> result;
    
   /*
    void permutation(vector<int> &nums,int i,int n){
        if(i==n){
            result.push_back(nums);
            return ;
        }

        for(int j=i;j<=n;j++){
            swap( nums[i],nums[j]);
            permutation(nums,i+1,n);
            swap( nums[i],nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        permutation(nums,0,nums.size()-1);
        
        return result;
    }*/
    
    
    
    
    void permutation( vector<int> & nums, vector<int> & DS,vector<vector<int>> & ans, int Freq [], int n){
        if(DS.size()==n){
            ans.push_back(DS);
            return;
        }
        
        for(int i = 0 ; i<n;i++){
            if(!Freq[i]){
                Freq[i]=1;
                DS.push_back(nums[i]);
                permutation(nums,DS, ans, Freq,n);
                DS.pop_back();
                Freq[i]=0;
                
                
                
            }
        }
        
    }

    
    
        vector<vector<int>> permute(vector<int>& nums) {
        
            vector<vector<int>> ans;
            vector<int> DS;    

            int n = nums.size() ;
            int *Freq  =new int[n];
            fill_n(Freq, n , 0);

            permutation(nums,DS, ans, Freq,n);

            return ans;
         }
    
};