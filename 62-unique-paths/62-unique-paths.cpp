class Solution {
public:
    
    int cnt(int TT[][110], int m ,int n ){
        
        if(m==1||n==1){
            TT[m][n]=1;
        }
        
        if(TT[m][n]!=0){
            return TT[m][n];
        }
        else{
            TT[m][n]= cnt(TT, m, n-1)  + cnt(TT, m-1,  n) ;
            
        }
        
        return TT[m][n];
    
    }
    
    
    int uniquePaths(int m, int n) {
        
       /*
       //Recursive solution - O(2^n)
       if(m==1 ||n==1){
            return 1;
        }
        
        else 
            return uniquePaths(m, n-1)  + uniquePaths( m-1,  n) ;
        */
        
        // DP - Memoization
        
        int TT[110][110];
        
        memset(TT,0,sizeof(TT));
        
        for(int i=0;i<=m;i++){
            TT[i][1]=1;
        }
        
        for(int i=0;i<=n;i++){
            TT[1][i]=1;
        }
        
        return cnt(TT,m,n);
        
        
    }
};