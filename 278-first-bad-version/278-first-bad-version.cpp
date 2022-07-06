// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int f=1;
        int l = n;
        
         while(f<=l){
             
             int m = l - (l-f)/2;
             
             if(isBadVersion(m)){
                 if(m!=1){
                     if(!isBadVersion(m-1)){
                         return m;
                     }
                     else{
                         l=m-1;
                     }
                     
                 }else{
                     return m;
                 }
             }else{
                 
                 f=m+1;
                 
             }
             
             
         }
        
        return 0;
        
        
        
    }
};