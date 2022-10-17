class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        map<char,int> M;
        
        for(char &c : sentence){
            M[c]++;
            
            if(M.size()==26){
                return true;
            }
            
        }
//          if(M.size()<26){
//                 return false;
//         }
        return false;
        
    }
};