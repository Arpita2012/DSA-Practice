class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        vector<int> pref ;
        
        //building prefix sum vector
        pref.push_back(0);
        pref.push_back(nums[0]);
        
        
        for(int i=1 ; i< nums.size(); i++){
            
            pref.push_back(pref[i] + nums[i]);
            
        }
        
        
        
        int pivot_index = -1;
        
        
        for(int i=0 ; i< pref.size()-1; i++){
           
         
           if(pref[i]== (pref[pref.size() - 1] - pref[i] - nums[i])){
               pivot_index=i;
                break;
           }
            
        }
        
        
        return pivot_index;
        
        
        
        
    }
};