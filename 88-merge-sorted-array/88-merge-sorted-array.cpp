class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int l1 =m-1;
        int l2 = n-1;
        
        for(int i= m+n-1 ; i>=0;i--){
            
            if(l2+1>0 &&(l1+1==0 ||nums2[l2]>nums1[l1])){
                nums1[i]=nums2[l2];
                l2--;
            }else{
                nums1[i]=nums1[l1];
                l1--;
            }
           
            
        }
        
    }
};