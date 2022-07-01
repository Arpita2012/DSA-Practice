class Solution {
public:
    
    bool static mysorted(const vector<int>& A , const vector<int>& B ){
        return A[1] > B[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
      
        sort(boxTypes.begin(), boxTypes.end() , mysorted);
        
        int remainingCnt = truckSize;
        int max_unit=0;
        int truckCnt =-1;
        int unit =-1;
        
        
        int i = 0 ;
        for(; i< boxTypes.size() ; i++){
            //cout<<boxTypes[i][0]<<" "<< boxTypes[i][1] <<" rem "<< remainingCnt
               // <<" max_unit "<< max_unit<<endl;; 
            bool flag =true;
            truckCnt = boxTypes[i][0];
            unit = boxTypes[i][1];
            
            if(remainingCnt > truckCnt ){
                remainingCnt -= truckCnt ;
                max_unit +=  truckCnt * unit;
                flag = false;
            }
            
            //true flag implies that there is no ith box type left whose
            //all boxes can be accomodatedd in truck thus we can break from loop
            if(flag){
             break;   
            }
            
      
        }
        if((remainingCnt != 0 ) && (i< boxTypes.size())){
            
            max_unit +=  remainingCnt * unit;
            remainingCnt = 0 ;
        }
         

        
        return max_unit;
        
        
        
    }
    
};