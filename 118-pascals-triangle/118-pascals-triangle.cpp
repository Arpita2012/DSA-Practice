class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<int> prev ;
        prev.push_back(1);
        
        vector<vector<int>> res;
        
        
        for(int i=1; i<=numRows; i++){
            res.push_back(prev);
            
            vector<int> curr ;
            curr.push_back(1);
            
            for(int j=1 ; j<prev.size(); j++){
                curr.push_back(prev[j]+prev[j-1]);
            }
            curr.push_back(1);
            
            prev=curr;
        }
        
        return res;
        
        
        
    }
};