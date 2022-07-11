class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        map<char,int> m_r;
        for(int i=0 ; i<ransomNote.length();i++){
            
            if(m_r.find(ransomNote[i])==m_r.end()){
                m_r[ransomNote[i]]=1;
            }else{
                m_r[ransomNote[i]]++;
            }
            
        }
        
        map<char,int> m_m;
        for(int i=0 ; i<magazine.length();i++){
            
            if(m_m.find(magazine[i])==m_r.end()){
                m_m[magazine[i]]=1;
            }else{
                m_m[magazine[i]]++;
            }
            
        }
        
        for(auto x : m_r){
            if((m_m.find(x.first)==m_m.end()) || (m_m[x.first]<x.second)){
                return false;
            }
        }
        
        return true;
        
    }
};