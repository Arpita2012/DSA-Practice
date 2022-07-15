class Solution {
public:
    int findWithThisPoint(vector<vector<int>>&grid,int ind, int rows, int cols)
    {
        int col = ind;
        
        for(int ind = 0; ind < rows; ind++)
        {
            if(grid[ind][col] == 1)
            {
                if(col == cols-1)
                    return -1;
                
                if(grid[ind][col + 1] == -1)
                    return -1;
                
                col++;
            }
            else
            {
                if(col == 0)
                    return -1;
                
                if(grid[ind][col - 1] == 1)
                    return -1;
                
                col--;
            }
        }
        
        return col;
    }    
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        int rows = grid.size(), cols = grid[0].size();
        
        vector<int> ans;
        
        for(int ind = 0; ind < cols; ind++)
        {
            int isPossible = findWithThisPoint(grid, ind, rows, cols);
            ans.push_back(isPossible != -1 ? isPossible : -1);
        }
        
        return ans;
    }
};