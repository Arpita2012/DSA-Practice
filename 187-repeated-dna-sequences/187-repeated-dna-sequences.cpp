class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.length()<=10){
            return ans;
        }
        
        map<string,int> m;
        for(int i=0 ; i<= s.length()-10; i++){
            //cout<<i<<endl;
            //cout<<s.substr(i,i+10)<<endl;
            
            string temp = s.substr(i,10);
            if(m.find(temp)==m.end()){
                m[temp]=1;
            }else{
                m[temp]++;
            }
            
        }
        
        for(auto x: m){
            //cout<<x.first<<" "<<x.second<<endl;
            if(x.second>=2){
                ans.push_back(x.first);
            }
        }
        return ans;
        
        
    }
};