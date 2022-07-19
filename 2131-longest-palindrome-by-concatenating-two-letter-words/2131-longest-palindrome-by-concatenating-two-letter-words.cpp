class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>freq;
        
        for(auto i: words)freq[i]++;
        
        int palindLen=0;
        bool flg=0;
        for(auto j: words){
            if(!freq[j])continue;
            string s="";
            s+=j[1],s+=j[0];
            if(freq[s]>0){
                if(s[0]==s[1]){
                    if(freq[s]%2)flg=1,freq[s]--;
                    palindLen+=2*freq[s];
                    freq[s]=0;
                }
                else if(s[0]!=s[1]){
                    palindLen+=4*min(freq[j],freq[s]);
                    freq[j]=0;
                    freq[s]=0;
                }
            }
        }
        if(flg)palindLen+=2;
        return palindLen;
    }
    
};