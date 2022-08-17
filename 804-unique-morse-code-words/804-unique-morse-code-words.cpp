class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        string morse[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> SET_;
        
        for(auto w : words){
            
            string s = "";
                
            for(auto c : w){
                
                s = s + morse[c-'a'];
                
            }
            
            SET_.insert(s); 
            
        }
        
        return SET_.size();
        
        
    }
};