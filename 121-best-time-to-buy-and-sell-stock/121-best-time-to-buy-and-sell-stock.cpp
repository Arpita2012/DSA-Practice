class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int N= prices.size();
        //int * profit = new int[N];
        //fill_n(profit , N , 0);
        
        int purchase = prices[0];
        
        int maxProf =0 ;
        
        for(int i = 1; i<N ; i++){
            
            if(purchase > prices[i]){
                purchase = prices[i];
            }
            
            //cout<<profit[i]<<" ";   
            
            if(maxProf< prices[i] - purchase)
                maxProf= prices[i] - purchase;
            
        }
        return maxProf;
        
    }
};