class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int N= cost.size();
        int F[N];
        F[N-1]=cost[N-1];
        F[N-2]=cost[N-2];
        
        for(int i=N-3; i>=0;i--){
            
            F[i]=cost[i] + min(F[i+1],F[i+2]);
        }
        return F[0]>F[1]?F[1]:F[0];
    }
};