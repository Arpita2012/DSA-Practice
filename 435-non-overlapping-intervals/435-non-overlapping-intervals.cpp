class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         sort(begin(intervals) , end(intervals));
    
    // track ending time of  previous  activity
    int free = intervals[0][1];
 
    // ans 
    // ++ when start of acyivity not > free
    int ans =0;
    
    for(int i=1;i<intervals.size();i++){
        
        if(intervals[i][0] < free){
            ans++;
            // cheeck if its ending less then
            free = min( free ,intervals[i][1] );
        }else{
            free = intervals[i][1];
        }
        
        
    }
    
    return ans;
    }
};