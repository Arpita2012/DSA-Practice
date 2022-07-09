class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int o_r = mat.size();
        int o_c = mat[0].size();
        
        if((o_r * o_c) !=(r *c)){
            
            return mat;
        }
        
        vector<vector<int>> newMat(r , vector<int>(c,INT_MIN)) ;
        
        int n_i=0;
        int n_j =0;
        
        for(int i=0 ; i< o_r ; i++){
        
            
            
            for(int j=0 ; j< o_c ; j++){
                
                newMat[n_i][n_j++]=mat[i][j];
                
                if(n_j==c){
                    n_i++;
                    n_j=0;
                }
            }
            
        }
        
        return newMat;
        
        
        
        
        
    }
};