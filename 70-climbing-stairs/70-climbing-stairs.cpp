class Solution {
public:
    int climbStairs(int n) {
        
        int Stairs[n+1];
        
        Stairs[0]=0;
        
        Stairs[1]=1;
        
        if(n==1){
            return Stairs[1];
        }
        
      else{
            Stairs[2]=2;
            
            for(int i=3 ; i<=n;i++){
                Stairs[i]=Stairs[i-1]+Stairs[i-2];
            }
            
            return Stairs[n];
            
        
        }
        
        
        
        
        
        
    }
};