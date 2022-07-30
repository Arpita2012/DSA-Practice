class Solution {
public:
    
    
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        map<char, int> MAX;
        
        for(string &s : words2){
            
            map<char, int> m2;
            for(char c : s)
            {   
            
                if(m2.find(c)==m2.end()){
                    m2[c]=1;
                }else{
                    m2[c]++;
                }
                
                if((MAX.find(c)==MAX.end()) || (MAX[c]<m2[c])){
                     MAX[c]=m2[c];
                }
                
            }
   
        }
        
        vector<string> ans;
        
         for(string &s : words1){
            bool flag =true;
            map<char, int> m1 ;
            for(char c : s)
            {   
            
                if(m1.find(c)==m1.end()){
                    m1[c]=1;
                }else{
                    m1[c]++;
                }
            }
             
             
            for(auto x : MAX){

                    if((m1.find(x.first)!=m1.end()) && (m1[x.first]>=x.second)){
                        continue;
                    }else{
                        flag=false;
                        break;
                    }

                }
                if(flag){
                    ans.push_back(s);
                }
                
        
        
         }
         return ans;
        
        
        /*vector<map<char, int>> V;
        
        for(string &s : words2){
            
            map<char, int> m2;
            for(char c : s)
            {   
            
                if(m2.find(c)==m2.end()){
                    m2[c]=1;
                }else{
                    m2[c]++;
                }
            }
            V.push_back(m2);
   
        }
        
        
        vector<string> ans;
        set<string> done;
        set<string> notdone;
        
        
        for(string &s : words1){
            bool flag =true;
            map<char, int> m1 ;
            for(char c : s)
            {   
            
                if(m1.find(c)==m1.end()){
                    m1[c]=1;
                }else{
                    m1[c]++;
                }
            }
            
            for(auto MM:V){
            
                for(auto x : MM){

                    if((m1.find(x.first)!=m1.end()) && (m1[x.first]>=x.second)){
                        continue;
                    }else{
                        flag=false;
                        break;
                    }

                }
                if(flag){
                    ans.push_back(s);
                }
                
            }
            
        }
        return ans;*/
        
    }
};