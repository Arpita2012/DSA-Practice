class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size() ;
        int n = matrix[0].size() ;
        
        int nums = m*n ; // total number of elements
        int hs = 0;      //horizontal start
        int he = n-1 ;   //hotizontal end
        int vs = 0 ;     //vertical start
        int ve = m-1 ;   //vertical end
        int i = 0 ;
        int j = 0 ;
        vector<int> ans ;
        while(nums){
            vs++ ;
            while(nums && j <= he){
                ans.push_back(matrix[i][j++]) ;
                nums-- ;
            }
            j-- ;
            i++ ;
            he--;
            while(nums && i <= ve){
                ans.push_back(matrix[i++][j]) ;
                nums-- ;
            }
            i-- ;
            j-- ;
            ve-- ;
            while(nums && j >= hs){
                ans.push_back(matrix[i][j--]) ;
                nums-- ;
            }
            j++;
            i--;
            hs++ ;
            while(nums && i >= vs){
                ans.push_back(matrix[i--][j]) ;
                nums-- ;
            }
            i++;
            j++;
        }
        return ans ;
    }
};