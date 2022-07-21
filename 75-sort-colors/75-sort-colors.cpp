class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt_0 = 0;
        int cnt_1 = 0;
        int cnt_2 = 0;
        
        for(auto x : nums){
            if(x==0){
                cnt_0++;
            }else if(x==1){
                cnt_1++;
            }else{
                cnt_2++;
            }
        }
        
        for(int i=0;i<cnt_0;i++){
            nums[i]=0;
        }
        for(int i=cnt_0;i<cnt_0+cnt_1;i++){
            nums[i]=1;
        }
        
        for(int i=cnt_0+cnt_1;i<nums.size();i++){
            nums[i]=2;
        }
        
        
        
    }
};