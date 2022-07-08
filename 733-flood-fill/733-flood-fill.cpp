class Solution {
public:
    
    void dfs(vector<vector<int>>&  res ,vector<vector<int>>&  visited, int sr, int sc, int c,int m,int n ,int sourceColor){
        //cout<<sr << " "<<sc<<endl;
        if(sr<m && sc<n&& sr>=0 && sc>=0 && (!visited[sr][sc]) &&  res[sr][sc]==sourceColor){
            //cout<<" bng"<<endl;
            visited[sr][sc]=1;
            res[sr][sc]=c;
            
          
            
            dfs(res , visited, sr+1, sc , c ,m,n,sourceColor);
            dfs(res , visited, sr-1, sc , c  ,m,n,sourceColor );
            dfs(res , visited, sr, sc+1 , c  ,m,n,sourceColor);
            dfs(res , visited, sr, sc-1 , c  ,m,n,sourceColor);
            
        }
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        
        vector<vector<int>> res = image;
        
        int  m =image.size();
        int n = image[0].size();
        vector<vector<int>> visited(m, vector<int> (n , 0 ));
        
        int sourceColor = image[sr][sc];
        
        //cout<<visited.size()<<" "<< visited[0].size()<<" "<<visited[m-1][n-1]<<endl;
        
        dfs(res , visited, sr, sc , color ,m,n ,sourceColor);
        
        return res;
        
    }
};