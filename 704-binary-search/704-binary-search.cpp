class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int f=0;
        int l = nums.size()-1;
        
        while(f<=l){
            //cout<<"f : "<<f<<" l : "<<l<<endl;
            int m = l - ((l-f)/2);
            
            if(nums[m]==target){
                return m;
            }else if(nums[m]>target){
                //search the left part
                
                l=m-1;
            }else{
               //search the right part 
                f=m+1;
            }
            
            
        }
        return -1;
        
    }
};