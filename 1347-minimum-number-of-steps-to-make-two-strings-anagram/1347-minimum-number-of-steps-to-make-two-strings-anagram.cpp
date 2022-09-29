class Solution {
public:
    int minSteps(string s, string t) {
        
        map<char,int> M;
        
        for(auto & c : s){
            M[c]++;
        }
        for(auto & c : t){
            M[c]--;
        }
        
        int steps = 0;
        
        for(auto e : M){
            if(e.second < 0){
                steps = steps + abs(e.second);
            }
        }
        
        return steps;
        
        
    }
};