class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mi=INT_MAX;
    for(int i=0;i<strs.size();i++)
    {
        if(strs[i].length()<mi)
        {
            mi=strs[i].length();
        }
    }
    
    int j=0;
    string ans="";
    int i;
    while(mi--)
    {
        int flag=0;
      for( i=0;i<strs.size()-1;i++)
      {
          if(strs[i][j]!=strs[i+1][j])
          {
              flag=1;
          }
      }
        if(flag==0)
        {
            ans+=strs[i][j];
        }else{
            break;
        }
        j++;
        
    }
    return ans;
    
    
    }
};