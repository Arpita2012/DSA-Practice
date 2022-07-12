class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> bulls(10,0),cow1(10,0),cow2(10,0);
        int bull=0,cow=0;
        for(int i=0;i<secret.size();i++)
        {
            if(secret[i]==guess[i])
            {
                bulls[secret[i]-'0']++;
                bull++;
            }
            cow2[guess[i]-'0']++;
            cow1[secret[i]-'0']++;
        }
        for(int i=0;i<10;i++)
        {
            cow+=min(cow1[i],cow2[i])-bulls[i];
        }
        string ans=to_string(bull)+'A'+to_string(cow)+'B';
        return ans;
    }
};