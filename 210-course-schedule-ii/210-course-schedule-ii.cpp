
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>&  prerequisites) {
        vector<int> res;
        vector<int> indegree(numCourses,0);
        vector<vector<int>> graph(numCourses,vector<int>());
        
        for(auto pre:prerequisites)
        {
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> que;
        for(int i=0;i<indegree.size();i++)
            if(indegree[i]==0)
                que.push(i);
                
        while(!que.empty())
        {
            int u = que.front();que.pop();
            res.push_back(u);
            for(auto v:graph[u])
            {
                indegree[v]--;
                if(indegree[v] == 0)
                    que.push(v);
            }
        }
        if(res.size()==numCourses)
            return res;
        else
            return vector<int>();
    }
};
/*   
    void bfs(vector<vector<int>> &aList,int s, vector<bool>& visited , vector<int> & ans ){
      
        queue<int> q;
        
        q.push(s);
        visited[s]=true;
        
        while(!q.empty()){
            int v = q.front();
            q.pop();
            
            for(auto x : aList[v]){
                if(!visited[x]){
                    visited[x]=true;
                    q.push(x);
                }
            }
            
            ans.push_back(v);
            
        }
        
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> aList(numCourses);
        
        for(auto x:prerequisites){
            aList[x[1]].push_back(x[0]);
        }
        
        
        
        vector<int>ans;
        for(int i=0 ; i<numCourses;i++){
            //if(!visited[i]){
                vector<bool>visited(numCourses,false);
                
                bfs(aList,i, visited, ans);
                
                if(ans.size()==numCourses){
                    return ans;
                }
                ans.clear();
             //}
        }
       
        return ans;
        
        
        
        
        
        
    }
    
    
   
    void dfs(vector<vector<int>> &aList,int s, vector<bool>& visited , vector<int> & ans ){
        
        
        visited[s]=true;
        ans.push_back(s);
        
        for(auto x: aList[s]){
            cout<<x<<endl;
            if(!visited[x]){
                dfs(aList,x, visited, ans);
            }
        }
        
        
    }
    
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
     
        
        vector<vector<int>> aList(numCourses);
        
        for(auto x:prerequisites){
            aList[x[1]].push_back(x[0]);
        }
        
//         for(auto a : aList){
//             for(auto b: a){
//                 cout<<b<<" ";
//             }cout<<endl;
            
//         }
        
        vector<bool>visited(numCourses,false);
        
        vector<int>ans;
        for(int i=0 ; i<numCourses;i++){
            if(!visited[i]){
                
                
                dfs(aList,i, visited, ans);
                
                if(ans.size()==numCourses){
                    return ans;
                }
                ans.clear();
            }
        }
       
        return ans;
        
        
        
        
       
        return ans;
        
        
        
    }*/
