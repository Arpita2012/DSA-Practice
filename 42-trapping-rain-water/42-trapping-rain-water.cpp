class Solution {
public:
    int trap(vector<int>& height) {
        /* DP TC : O(N) | SC : O(N)
        int N = height.size();
        
        if(N==0){
            return 0;
        }
        
        vector<int>leftMax(N,0);
        vector<int>rightMax(N,0);
        
        leftMax[0]=height[0];
        
        for(int i=1; i<N; i++){
            leftMax[i]=max(leftMax[i-1],height[i]);
        }
        
        
        rightMax[N-1]=height[N-1];
        
        for(int i=N-2; i>=0; i--){
            rightMax[i]=max(rightMax[i+1], height[i]);
        }
        
        int water =0;
        
        for(int i=0 ; i<N; i++){
            water = water + min(leftMax[i],rightMax[i])-height[i];
        }
        
        return water;
        */
        
        
        //Stack  TC - O(N) | SC - O(N)
        
        
        stack<int>S;
         int N = height.size();
        int water =0 ;
        for(int current=0 ; current<N; current++){
            
            //int current = height[i];
            
            while(!S.empty() and height[current] > height[S.top()]  ){
                int Top = S.top();
                S.pop();
                
                if(S.empty()){
                    break;
                }
                
                int distance = current - S.top() - 1;
                int bounded_height = min(height[current], height[S.top()]) - height[Top];
                
                water += distance * bounded_height;
                
                
            }
            
            S.push(current);
            
        }
        
        return water;
        
        
        
        
    }
};