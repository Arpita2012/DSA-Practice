class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
     vector<string>  ans;
        for(auto x: words){
            if(detect(x,pattern)){
                ans.push_back(x);
            }
        }
        return ans;
        
        
    }
    
    bool detect(string word, string pattern){
        map<char,char> m1;
        map<char,char> m2;
        
        if(pattern.length()!=word.length()){
            return false;
        }
        
        int N = pattern.length();
        
        for(int i=0; i<N;i++){
            if(m1.find(word[i])==m1.end()){
                m1[word[i]]=pattern[i];
            }
            if(m2.find(pattern[i])==m2.end()){
                m2[pattern[i]]=word[i];
            }
            
            if(m1[word[i]]!=pattern[i]   || m2[pattern[i]]!=word[i])
                return false;
        }
        
        return true;
        
        
        
    }
    
    
};