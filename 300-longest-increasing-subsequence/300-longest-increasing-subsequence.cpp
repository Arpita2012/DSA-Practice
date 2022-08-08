class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        int * L = new int [n];
        fill_n(L , n , INT_MIN);
        
        L[0]=1;
        
        for(int i= 1 ; i<n ;i++){
            L[i]=1;
            for(int j=0; j<i; j++){
                
                if(nums[j]< nums[i]  &&  L[i] <1+ L[j] ){
                    L[i] = 1+ L[j];
                }
                
            }
        }
        
        return *max_element(L, L+n);
        
    }
};