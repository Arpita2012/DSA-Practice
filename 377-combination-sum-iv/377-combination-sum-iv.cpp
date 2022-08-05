class Solution {
public:

    int combinationSum4(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        unsigned int *table= new unsigned int [target +1];
        fill_n(table,  target+1,0 );
        table[0]=1;
        
        
        for(int i= 1 ; i<=target; i++){
            
            for(int j=0 ; j<nums.size(); j++){
                if(nums[j]> i){
                    break;
                }
                    table[i]+= table[i-nums[j]];
                    cout<<i<<" "<<nums[j]<<" "<<table[i]<<endl;
                
            }
            
        }
        
        
        return table[target];
       
        
       
        
        
    }
};