class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int f=0;
        int l=nums.size()-1;
        int first_pos=-1;
        int last_pos=-1;
        
        
        
        while(f<=l){
            int m= f+ (l-f)/2;
            
            if(nums[m]==target){
                
                first_pos = m-1;
                while(first_pos >=0 && nums[first_pos]==target){
                    first_pos--;
                }
                last_pos=m+1;
                while(last_pos <nums.size() && nums[last_pos]==target){
                    last_pos++;
                }
                first_pos++;
                last_pos--;
                
                
                break;
                
                
            }else if(nums[m]<target){
                f=m+1;
            }else {
                l=m-1;
            }
            
            
        }
        
         vector<int> ans = {first_pos,last_pos};
        return ans;
        
    }
};