class Solution {
public:
    string reverseWords(string s) {
        
        int N_s = s.length();
        
        string ans ="";
        
        stringstream ss(s);
        string word;
        
        while(ss>>word){
            
            int N = word.length();
            for(int i=0, j=N-1; i<j; i++ , j--){
                swap(word[i],word[j]);

            }
           ans=ans + word+ " ";
        }
        
        
        return ans.substr(0, N_s);
        
    }
};