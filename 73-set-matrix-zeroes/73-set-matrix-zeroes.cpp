class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool setfirstCol = false;
        bool setfirstRow = false;
        //first col
        for(int i=0 ;i<m ; i++){
            if(matrix[i][0]==0){
                setfirstCol=true;
                break;
            }
        }
        
        //first row
        for(int i=0 ;i<n ; i++){
            if(matrix[0][i]==0){
                setfirstRow=true;
                break;
            }
        }
        
        for(int i=1;i<m ; i++){
            for(int j=1;j<n ; j++){
                
                if(matrix[i][j]==0){
                    //setting first row and col
                    
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                    
                }
                
            }
        }
        
        for(int i=1;i<m ; i++){
            
            if(matrix[i][0]==0)
                for(int j=1;j<n ; j++){
                    matrix[i][j]=0;
                }
        }
        
        
        
        for(int j=1;j<n ; j++){
            
            if(matrix[0][j]==0)
                for(int i=1;i<m ; i++){
                    matrix[i][j]=0;
                }
        }
        
        if(setfirstCol){
             for(int i=0;i<m ; i++){
                 matrix[i][0]=0;
             }
        }
        
        
        if(setfirstRow){
             for(int j=0;j<n ; j++){
                 matrix[0][j]=0;
             }
        }
        
        
        
    }
};