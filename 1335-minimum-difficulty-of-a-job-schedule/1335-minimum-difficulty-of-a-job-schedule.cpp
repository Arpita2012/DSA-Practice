class Solution {
public:
    int minDifficulty(vector<int>& v, int d) {
           int n=v.size();
        v.insert(v.begin(),0);
        vector<vector<int>> dp(n+1,vector<int>(d+1,1e7));
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int k=1;k<=min(i,d);k++){
                int mx=INT_MIN;
                for(int j=i;j>=k;j--){
                    mx=max(mx,v[j]);
                    dp[i][k]=min(dp[i][k],dp[j-1][k-1]+mx);
                }
            }
        }
       // cout<<dp[n][d]<<endl;
        return (dp[n][d]==1e7)?-1:dp[n][d];
    }
};