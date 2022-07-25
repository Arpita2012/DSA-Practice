class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int f=0;
        int l=nums.size()-1;
        
        bool flag = false;
        
        while(f<=l){
            int m= f+ (l-f)/2;
            
            if(nums[m]==target){
                
                while(nums[f]!=target){
                    f++;
                }
                while(nums[l]!=target){
                    l--;
                }
                flag=true;
                break;
                
                
            }else if(nums[m]<target){
                f=m+1;
            }else {
                l=m-1;
            }
            
            
        }
        if (flag){
        vector<int> ans = {f,l};
                    return ans;
        
        }
        else{
          vector<int> ans = {-1,-1};  
                    return ans;
        }

    }
};