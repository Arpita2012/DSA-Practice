class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int>A ;
        A.push_back(1);
        if(rowIndex==0){
            return A;
        }
        A.push_back(1);
        if(rowIndex==1){
            return A;
        }
        
        
        
        for(int i=2; i<=rowIndex;i++){
            vector<int>T;
            T.push_back(1);
            for(int j=0;j<A.size()-1;j++){
                T.push_back(A[j]+A[j+1]);
            }
            T.push_back(1);
            
            A=T;
            
            
        }
        
        return A;
        
        
    }
};