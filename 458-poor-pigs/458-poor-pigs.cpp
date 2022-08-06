class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs_cnt=0;
        
        int TT = minutesToTest/minutesToDie;
        
        while( pow(TT+1,pigs_cnt)< buckets){
            pigs_cnt++;
        }
        return pigs_cnt;
        
        
    }
};