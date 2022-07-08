class Solution {
public:
    
    void dfs(vector<vector<char>>& grid, int i,int j,vector<vector<int>> &visited,int m,int n){
        
        if(i>=0 && j>=0 && i<m && j<n &&  (!visited[i][j])&& (grid[i][j]=='1')){
            visited[i][j]=1;
             dfs(grid, i+1,j,visited,m,n);
             dfs(grid, i-1,j,visited,m,n);
             dfs(grid, i,j+1,visited,m,n);
             dfs(grid, i,j-1,visited,m,n);
            
        }
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        
        vector<vector<int>> visited (m, vector<int>(n,0) );
        
        int cnt = 0;
        
        for(int i = 0 ; i< m ; i++){

            for(int j = 0 ; j< n ; j++){
                    
                 if(!visited[i][j] && (grid[i][j]=='1')){
                     dfs(grid, i,j,visited,m,n);
                     cnt++;
                 }
                
                
            }   
        }
        
        return cnt;
        
    }
};