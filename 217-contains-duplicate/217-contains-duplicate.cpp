class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        set<int> S;
        
        for(auto x: nums){
            if(S.find(x)==S.end()){
                S.insert(x);
            }else{
                //duplicate found 
                return true;
            }
        }
        
        return false;
    }
};