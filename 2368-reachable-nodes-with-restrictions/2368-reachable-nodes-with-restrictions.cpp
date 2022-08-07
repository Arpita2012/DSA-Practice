class Solution {
public:
    
    
    void dfs(vector<vector<int>> &aList ,vector<bool> & visited , int & cnt, int s){
        visited[s]=true;
        cnt++;
        for(int i =0 ; i<aList[s].size(); i++){
            int x = aList[s][i];
            if(!visited[x]){
                 dfs(aList , visited , cnt, x);
            }
        }
        
    }
        
    
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
     
        vector<vector<int>> aList(n );
        
        set <int> S;
        
        for(auto R: restricted){
            S.insert(R);
        }
        
        
        
        for(int e = 0 ; e < edges.size(); e++){
             //finding element in vector take O(n) -> thus convert it to set O(1) 
            // if((find(restricted.begin(), restricted.end(), edges[e][0])==restricted.end() )   && (find(restricted.begin(), restricted.end(), edges[e][1])==restricted.end() )){
           
            if((S.find(edges[e][0])==S.end() )   && (S.find(edges[e][1])==S.end() )){
                
                aList[edges[e][0]].push_back(edges[e][1]);
                aList[edges[e][1]].push_back(edges[e][0]);
                
                /*S.insert(edges[e][0]);
                S.insert(edges[e][1]);
                cout<<edges[e][0]<<" "<<edges[e][1];
                */
            }
            
        }
        
//         for(auto y : aList){
//             for(int i = 0 ; i< y.size(); i++){
//                 cout<<y[i]<<" ";
//             }cout<<endl;
            
//         }
        
       //bool * visited = new bool[n];
        vector<bool> visited(n,false);
        
        //fill_n(visited , n , false);
        
        //visited[0]=true;
        
        
        int cnt=0;
        
       // dfs(aList , visited , cnt, 0);
       //return cnt;
        
        /*if(S.find(0)==S.end()){
            return 1;
        }else{
            return S.size();
        }
        */
        
        
        
        queue<int> Q;
        Q.push(0);
        visited[0]=true;
        
        while(!Q.empty()){
            
            int F = Q.front();
            Q.pop();
            
            cnt++;
            for(int i =0 ; i<aList[F].size(); i++){
            int x = aList[F][i];
                if(!visited[x]){
                    visited[x]=true;
                     Q.push(x);
                }
            }
            
            
            
            
        }
        
        
        
        
        return cnt;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};