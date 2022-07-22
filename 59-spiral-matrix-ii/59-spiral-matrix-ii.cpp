class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        
        vector<vector<int>> M(n, vector<int>(n,-1));
        
//         for(int i =0 ;i< n ;i++){
//             for(int j=0; j<n;j++){
//                 cout<< M[i][j]<<" ";
                
//             }cout<<endl;
//         }
        
        
        int left =0;
        int right=n-1;
        int top=0;
        int bottom = n-1;
        int cnt =1;
        while(cnt<=(n*n)){
            for(int i=left; i<=right; i++){
                M[top][i]=cnt++;
            }
            top++;
            for(int i=top; i<=bottom;i++ ){
                M[i][right]=cnt++;
            }
            right--;
            
            for(int i=right; i>=left;i--){
                M[bottom][i]=cnt++;
            }
            bottom--;
            
            for(int i = bottom; i>=top; i--){
                M[i][left]=cnt++;
            }
            left++;
            
            
            
        }
        
        
        
        return M;
        
    }
};