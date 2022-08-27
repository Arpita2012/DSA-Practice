class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n2=nums2.size();
        int n1 = nums1.size();
        
        map<int,int> A;
        
        stack<int> s;
        
        for(int i = n2-1;i>=0 ; i--){
            
            while(!s.empty() && s.top()<nums2[i]){
                s.pop();
            }
            
            if(!s.empty() && s.top()> nums2[i]){
                A[nums2[i]] = s.top();
                
            }else{
                A[nums2[i]]=-1;
            }
            s.push(nums2[i]);
            
        }
        
        
        vector<int> ans(n1,-1);
         for(int i = 0; i<n1; i++){
             ans[i]=A[nums1[i]];
         }
        
        return ans;
        
        
    }
};