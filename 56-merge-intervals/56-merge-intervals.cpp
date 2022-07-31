class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
         sort(arr.begin(),arr.end());                
        // Sort on start time
        int n = arr.size();

        vector<vector<int>> ans;                            
        //  final answer vector
        ans.push_back(arr[0]);
        int lastIdx = 0;                                               
        // Last index of answer vector

        for(int i = 1; i < arr.size(); i++){
            if(ans[lastIdx][1] >= arr[i][0]){                            
                // if the current interval overlap with
                ans[lastIdx][1] = max(ans[lastIdx][1],arr[i][1]);        
                // lastIdx element of answer vector
            }                                                            
            // then merge it to lastIdx element
            else{
                ans.push_back(arr[i]);                                   
                // No overlap with lastIdx, then push 
                lastIdx++;
            }
        }

        return ans;   
    }
};