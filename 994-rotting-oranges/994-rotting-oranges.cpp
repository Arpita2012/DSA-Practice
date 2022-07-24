class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         int row=grid.size(), col=grid[0].size();
    
    queue<pair<int,int>> q;
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
        }
    }
    
    q.push({-1,-1});
    int t=0;
    
    while(!q.empty()){
        int a=q.front().first;
            int b=q.front().second;
            
            if(a==-1 && b==-1 && q.size()==1){
                q.pop();
                break;
            }
            else if(a==-1 && b==-1 && q.size()>1){
                q.pop();
                q.push({-1,-1});
                t++;
            }
            else{
                if(a+1<row && grid[a+1][b]==1){
                    q.push({a+1,b});
                    grid[a+1][b]=2;
                }
                if(b+1<col && grid[a][b+1]==1){
                    q.push({a,b+1});
                    grid[a][b+1]=2;
                }
                if(a-1>=0 && grid[a-1][b]==1){
                    q.push({a-1,b});
                    grid[a-1][b]=2;
                }
                if(b-1>=0 && grid[a][b-1]==1){
                    q.push({a,b-1});
                    grid[a][b-1]=2;
                }
                q.pop();
            }
    }
    
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(grid[i][j]==1){
                return -1;
            }
        }
    }
    
    return t;
    }
};