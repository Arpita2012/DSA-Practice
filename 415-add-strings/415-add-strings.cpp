class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int l1=num1.size()-1;
        int l2=num2.size()-1;
        
        string ans="";
        int c=0;
        
        while(l1>=0 && l2 >=0){
            int x =num1[l1--]-'0';
            int y =num2[l2--]-'0';
            
            int S = x+ y+ c;
            
            c=S/10;
            S=S%10;
            
            ans=to_string(S)+ans;
            
            
        }
        
        while(l1>=0 ){
            int x =num1[l1--]-'0';
            int S = x+  c;
            c=S/10;
            S=S%10;
            ans=to_string(S)+ans;
        }
         while(l2>=0 ){
            int x =num2[l2--]-'0';
            int S = x+  c;
            c=S/10;
            S=S%10;
            ans=to_string(S)+ans;
        }
        
        if(c){
           ans=to_string(c)+ans; 
        }
        
        return ans;
        
        
    }
};