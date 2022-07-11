class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> umap;
        int l=0,r=0;
        int maxLen=0,maxCount=0;
        
        for(;r<s.size();r++)
        {
            umap[s[r]]++;
            maxCount = max(umap[s[r]],maxCount);
            
            if(r-l+1-maxCount>k)
            {
                umap[s[l]]--;
                l++;
            }
            maxLen = max(r-l+1,maxLen);
        }
        return maxLen; 
    }
};