class Solution {
public:
    string minWindow(string s, string t) {
          vector<string> ans;
        map<char,int> mp;

        // Storing frequency of each character resent in t string
        for(auto i: t){
            mp[i]++;
        }

        // Starting Point of window
        int i=0;
        // Ending Point of window
        int j=0;
        int count=mp.size();
        // st and mini for storing starting and ending point of our resultant substring
        int st=0;
        int mini=INT_MAX;

        // Actual Approach
        while(j<s.size()){
            mp[s[j]]--;

            if(mp[s[j]]==0){
                count--;
            }

            if(count==0){
                while(count==0){
                   if((j-i+1)<mini){
                       mini=j-i+1;
                       st=i;
                   }

                   mp[s[i]]++;

                   if(mp[s[i]]>0){
                       count++;
                   }

                   i++;
                }
            }
            
            j++;
        }
      
        // If No valid ans possible return empty string else return the final substring 
        if(mini==INT_MAX){
            return "";
        }
        else{
            return s.substr(st,mini);
        }   
    }
};