class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        bool flag=false;
        for(int mid =0 ; mid<m ; mid++){
        
        int f_c =0 , l_c = n-1;
                
        while(f_c<= l_c){
            //cout<< f_c<<" col /  "<<l_c<<endl;
            int mid_c = l_c - (l_c - f_c)/2;
            //cout<<"mid col "<<mid_c<<endl;

            if(target ==matrix[mid][mid_c]){
                flag= true;
                break;
            }

            else if(target < matrix[mid][mid_c]){
                l_c = mid_c-1;
            }else{
                f_c =mid_c+1;
            }

         }
            
         if(flag){
             break;
         }   
    }
        return flag;
}
};