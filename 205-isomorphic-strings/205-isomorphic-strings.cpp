class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        map<char, char> m1, m2 ;
        
        for(int i=0 ; i< s.length() ; i++){
            //cout<<s[i]<<" ";

                if(m1.find(s[i])==m1.end() && m2.find(t[i])==m2.end() ){  
                    m1[s[i]]=t[i];
                    m2[t[i]]='X';
                    
                }else if(m1[s[i]]!=t[i]){
                    return false;
                }
        }
        
        
        
        return true;
        
        
    }
};