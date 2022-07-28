class Solution {
public:
    
   
    
    
    string longestPalindrome(string s) {
        /*
        string T = s;
        reverse(T.begin(), T.end());
        string ans ="";
        //int l = longest_common_substring(T,s, T.length()-1, s.length()-1,ans);
        //cout<<l<<endl<<ans;
        
        int m = T.length();
        int n= s.length();
        
        int table[m+1][n+1];
        int len=0;
        int R,C;
        
        for(int i=0 ; i<=m;i++){
            for(int j=0 ; j<=n ;j++){
                if(i==0 || j==0){
                    table[i][j]=0;
                }else if(T[i-1]==s[i-1]){
                    table[i][j]=table[i-1][j-1]+1;
                    
                    if(len< table[i][j]){
                        len = table[i][j];
                        R=i;
                        C=j;
                    }
                    
                }else{
                    table[i][j]=0;
                }
            }
        }
        
        //string ans ="";
        
         while (table[R][C] != 0) {
           ans+= s[R - 1]; 


            R--;
            C--;
        }

        
        
        
        return ans;*/
         if (s.empty()) return "";
    if (s.size() == 1) return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) {
      if (s.size() - i <= max_len / 2) break;
      int j = i, k = i;
      while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
      i = k+1;
      while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
      int new_len = k - j + 1;
      if (new_len > max_len) { min_start = j; max_len = new_len; }
    }
    return s.substr(min_start, max_len);
        
        
    }
};