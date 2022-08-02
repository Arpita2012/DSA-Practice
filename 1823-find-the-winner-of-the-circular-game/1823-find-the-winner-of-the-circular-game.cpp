class Solution {
public:
    int cnt(int n,int k){
        if(n==1)
            return 0;
        return (cnt(n-1,k) + k) % n;
    }
    int findTheWinner(int n, int k) {
        return cnt(n,k)+1;
    }
};