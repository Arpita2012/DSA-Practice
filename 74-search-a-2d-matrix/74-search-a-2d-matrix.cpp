class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        
        int f=0; int l=m-1;
        bool flag =false;
        while(f<=l){
            
            //cout<< f<<" / row /  "<<l<<endl;
            int mid = l - (l-f)/2;
            //cout<<"mid r : "<< mid<<endl;
            if(target < matrix[mid][0]){
                l=mid-1;
               
            }else if (target > matrix[mid][n-1]){
                f=mid+1;
            }else{
                //binary search in this row
                
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
                
              break;  
            }
            
            
            
        }
        
        return flag;
        
        
    }
};