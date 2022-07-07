class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     
        vector<int> res;
       //M1 O(n^2)
        /* for(int i = 0 ; i<nums.size() ; i++){

            for(int j= i+1 ; j<nums.size() ; j++){
                
                    if((nums[i] + nums[j]) == target)
                    {
                        res.push_back(i);
                        res.push_back(j);
                        
                        return res;
                    }
                
            }       
        }
        
        */
        //M1 O(n) - > using hashmap
        
        map<int,int> m;
        for(int i = 0 ; i<nums.size() ; i++){
            if(m.find(target - nums[i])!=m.end()){
               res.push_back(m[target - nums[i]]);
                res.push_back(i);
                
                break;
                
            }else{
                m[nums[i]]=i; 
            }
        }
        
        
        return res;
        
        
        
    }
};