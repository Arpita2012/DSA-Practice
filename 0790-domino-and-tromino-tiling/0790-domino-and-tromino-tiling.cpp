class Solution {
public:
     long long int solve(vector<vector<long long int>> &dp, int n, bool isBothEmpty){
        if(n <= 2) return (isBothEmpty ? n : n-1);
        if(dp[n][isBothEmpty] != -1) return dp[n][isBothEmpty];
        long long int ans = 0;
        if(isBothEmpty)
            ans = solve(dp,n-1,true) + solve(dp,n-2,true) + 2*solve(dp,n-1,false);
        else 
            ans = solve(dp,n-1,false) + solve(dp,n-2,true);
        return dp[n][isBothEmpty] = ans%((int)1e9+7);
    }
    int numTilings(int n) {
        vector<vector<long long int>> dp(n+1, vector<long long int>(2,-1));
        return solve(dp, n, true);
    }
};