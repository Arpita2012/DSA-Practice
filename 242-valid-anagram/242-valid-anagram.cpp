class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.length()!=t.length()){
            return false;
        }
        
        map<char,int> m_r;
        for(int i=0 ; i<s.length();i++){
            
            if(m_r.find(s[i])==m_r.end()){
                m_r[s[i]]=1;
            }else{
                m_r[s[i]]++;
            }
            
        }
        
        map<char,int> m_m;
        for(int i=0 ; i<t.length();i++){
            
            if(m_m.find(t[i])==m_r.end()){
                m_m[t[i]]=1;
            }else{
                m_m[t[i]]++;
            }
            
        }
        
       /* for(auto x : m_r){
            if((m_m.find(x.first)==m_m.end()) || (m_m[x.first]<x.second)){
                return false;
            }
        }*/
        
        if(m_r == m_m){
            return true;
        }else{
            return false;
        }
        
        
    }
};