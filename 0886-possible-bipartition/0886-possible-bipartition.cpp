class Solution {
public:
   bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>mp(n);
        for(auto x:dislikes){
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]!=-1)
                continue;
            color[i]=1;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto x:mp[node]){
                    if(color[x]==-1){
                         color[x]=3-color[node];
                         q.push(x);
                    }
                    else if(color[x]==color[node])
                        return false;
                }
            }
        }
        return true;        
    }
};