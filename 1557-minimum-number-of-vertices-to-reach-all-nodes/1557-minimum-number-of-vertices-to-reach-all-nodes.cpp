class Solution {
public:
   
//      void dfs(vector<vector<int>> &aList ,vector<bool> & visited ,  int s){
//         visited[s]=true;
        
//         for(int i =0 ; i<aList[s].size(); i++){
//             int x = aList[s][i];
//             if(!visited[x]){
//                  dfs(aList , visited ,x);
//             }
//         }
        
//     // }
        
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
//         vector<vector<int>> aList(n );
        
//         for(int e = 0 ; e < edges.size(); e++){
             
//                 aList[edges[e][0]].push_back(edges[e][1]);
       
//         }
        
//          vector<bool> visited(n,false);
        
//          vector<int>  ANS;
        
//         for(int i= 0 ; i <n ; i++){
//             if(!visited[i]){
//                 ANS.push_back(i);
//                 dfs(aList , visited , i);
//             }
//         }
        
//         return ANS;
        
        vector<int> res, in(n);
        
        for(auto edge: edges)
          in[edge[1]]++;
        
        for(int i=0; i<n; ++i)
          if(in[i]==0) 
              res.push_back(i);
        
        return res;

        
    }
};