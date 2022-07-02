class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
      
        
        int max_verti = -1;
        for(int i=verticalCuts.size()-1 ; i>0 ; i--){
            verticalCuts[i]-=verticalCuts[i-1];
            if(verticalCuts[i] >max_verti ){
                max_verti = verticalCuts[i]; 
            }
            
        }
        if(verticalCuts[0] >max_verti ){
                max_verti = verticalCuts[0]; 
        }
            
        
        
        
        int max_hori = -1;
        for(int i=horizontalCuts.size()-1 ; i>0 ; i--){
            horizontalCuts[i]-=horizontalCuts[i-1];
            if(horizontalCuts[i] >max_hori ){
                max_hori = horizontalCuts[i]; 
            }
            
        }
        if(horizontalCuts[0] >max_hori ){
                max_hori = horizontalCuts[0]; 
        }
        
        
        cout<<max_verti <<" "<< max_hori;
       
         return (1LL*max_verti*max_hori ) % 1000000007 ;
        

    }
    
   
    
    
};