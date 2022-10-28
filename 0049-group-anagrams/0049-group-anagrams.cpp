class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> M;
        
        for(string& s: strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            
            M[temp].push_back(s);
        }
        
         vector<vector<string>> ana;
        for(auto & x : M){
            ana.push_back(x.second);
        }
        
        return ana;
        
        
    }
    
    
    
   
};