class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int N = nums.size();
   
        if(N==1){
            return 1;
        }
        
        int PD = nums[1]-nums[0];
        int cnt = PD!=0?2:1; 
        //when first and second element are different both 
        //contribute to wingle subsequence
        
        
           
        for(int i = 2 ; i< N ; i++){
           int D = nums[i]-nums[i-1];
            
           if((PD>=0 && D< 0)||(PD<=0 && D> 0)){
               PD=D;
               cnt+=1;
               
           } 
            
        }
    
        
        return cnt;
    }
};