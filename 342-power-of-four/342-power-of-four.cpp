class Solution {
public:
    bool isPowerOfFour(int n) {
        long x = 1;
        
        while (x<=n){
            if (n == x ){
                return true;
            }
            x=x<<2;
        }
        
        return false;
        
    }
};