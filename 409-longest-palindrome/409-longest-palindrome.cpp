class Solution {
public:
    int longestPalindrome(string s) {
        
        map<char , int> m;
        
        int N= s.length();
        
        for(int i= 0 ; i<N;i++){
            if(m.find(s[i])==m.end()){
                m[s[i]]=1;
            }else{
                m[s[i]]++;
            }
        }
        
        int len =0;
        
        bool oddDetect = false;
        
        for(auto x : m){
            //cout<<x.first <<" "<< x.second<<endl;
            
            if(x.second %2 == 0){
                len+= x.second;
            }else{
                
                if(!oddDetect){
                    oddDetect = true;
                }
                
                int temp = x.second;
                
                
                if(temp > 1){
                    temp =temp -1;
                    len+=temp;
                    //cout<<endl<<len;
                    
                    
                }
                
                
                
                
            }
        }
        
        return oddDetect? len+1 : len;
        
    }
};