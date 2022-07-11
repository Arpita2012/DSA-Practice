class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       /* 
        int s_l = s.length();
        
        int p_l = p.length();
        
        
        
        vector<int> ans;
        
        if(p.length() >s.length() ){
            return ans;
        }
        
        //storing frequency of string p characters
        map<char,int>mp;
        
        for(int i=0 ; i< p.length();i++){
            if(mp.find(p[i])==mp.end()){
                mp[p[i]]=1;
            }else{
                mp[p[i]]++;
            }
        }
        
        
        
        //using sliding window method for string s
         map<char,int> m;
        for(int i = 0 ; i< (s.length() -p.length())+1 ; i++){
           
            cout<<" i "<<i<<endl;

            if(i==0){
                for(int j=i; j<i+p.length(); j++){

                //cout<<" j "<<j<<endl;
                    if(m.find(s[j])==m.end()){
                        m[s[j]]=1;
                    }else{
                        m[s[j]]++;
                    }


                }
                
                //comparing both hashmaps
            
                bool f = true;
                for(auto x:mp){

                    cout<< x.first<<"|| "<<m[x.first]<< " | " <<x.second<<endl;
                    if(m[x.first]!=x.second){
                        f=false;
                        break;
                    }
                }
                if(f){
                    ans.push_back(i);
                }
                
                
            }else if(s[i-1] == s[i+p.length()-1]){
                //do nothing -- hashmap remains same
                
                if((ans.size()!= 0) && ans[ans.size()-1]==(i-1)){
                    //if prev was anagram
                    //this will also be
                    ans.push_back(i);
                }
                
                
            }else{
               
                
                if(m[s[i-1]]==1){
                     m.erase(s[i-1]);
                }else{
                    m[s[i-1]]--;
                }
                
                cout<<"s[i+p.length()-1] : "<<s[i+p.length()-1]<<endl;
                if(m.find(s[i+p.length()-1])==m.end()){
                        m[s[i+p.length()-1]]=1;
                }else{
                        m[s[i+p.length()-1]]++;
                }
                
                
                //if prev (i-1) index of s denotes starting of anagram- the current index won't be
                
                 if((ans.size()!= 0 )&&  ans[ans.size()-1]==(i-1)){
                     //do nothing
                 }
                else if(ans.size()== 0){
                    bool f = true;
                        for(auto x:mp){

                            cout<< x.first<<"|| "<<m[x.first]<< " | " <<x.second<<endl;
                            if(m[x.first]!=x.second){
                                f=false;
                                break;
                            }
                        }
                        if(f){
                            ans.push_back(i);
                        }
                }
                
                else{
                      
                     
                     if((mp.find(s[i+p.length()-1])!=mp.end() )
                                   && (mp[s[i+p.length()-1]] == m[s[i+p.length()-1]])
                       && (mp.find(s[i-1])!=mp.end() )
                                   && (mp[s[i-1]] == m[s[i-1]])
                       ){
                     ans.push_back(i);    
                     }
                     

                 }
                

                
            }
            
            
            
            
        }
        
       return ans; 
        */
        
        
        vector<int> mp1(26,0),mp2(26,0);
        int m=s.size(),n=p.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            mp2[p[i]-'a']++;
        }
        int i=0,j=0;
        while(j<m)
        {
            while(j<m&&j-i<n)
            {
                mp1[s[j]-'a']++;
                j++;
            }
            if(mp1==mp2)
            {
                ans.push_back(i);
            }
            mp1[s[i]-'a']--;
            i++;
        }
        return ans;
    }
};