class Solution {
public:
    string makeGood(string s) {
        
        
        string ans="";
        
        
        stack<char> Stk;
        
        for(int i= 0 ; i< s.length() ; i++){
            
            if(Stk.empty()){
                Stk.push(s[i]);
            }else{
                
                if((Stk.top() != s[i]) &&(toupper(Stk.top())==s[i] ||toupper(s[i] )==Stk.top() )){
                    Stk.pop();
                }else{
                    Stk.push(s[i]);
                }
                
            }
            
        }
        
        
        while(!Stk.empty()){
            ans = Stk.top() + ans;
            Stk.pop();
            
        }
        
        return ans;
        

    }
};