class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
       
        for(int i=0 ;i <9 ; i++){
             map<char,int> m1;
             for(int j=0 ;j <9 ; j++){
            
                 if(board[i][j]=='.'){
                     continue;
                 }
                 
                 if(m1.find(board[i][j])==m1.end()){
                     m1[board[i][j]]=1;
                 }else{
                     
                     return false;
                 }
                 
             }
        }
        
          for(int j=0 ;j <9 ; j++){
             map<char,int> m1;
             for(int i=0 ;i <9 ; i++){
            
                 if(board[i][j]=='.'){
                     continue;
                 }
                 
                 if(m1.find(board[i][j])==m1.end()){
                     m1[board[i][j]]=1;
                 }else{
                     
                     return false;
                 }
                 
             }
        }
        
        
        /*for(int i=0 ;i <9 ; ){
            
            
            int e =i+3;
            for(;i< e ; i++  ){
                
                
                for(int j=0 ;j <9 ; ){
                    
                     map<char,int> m1;

                    int e_j =j+3;
                    for(;j< e_j ; j++  ){

                        if(board[i][j]=='.'){
                             continue;
                         }

                         if(m1.find(board[i][j])==m1.end()){
                             m1[board[i][j]]=1;
                         }else{

                             return false;
                         }



                    }

                } 
 
                
                
            }
            
        }   
        */
        
        for(int p=0 ; p< 9 ; p=p+3){
            
            for(int q=0 ; q< 9 ; q=q+3){
                
               // cout<<"\n---------------------------\n";
                //cout<<p <<" || "<<q<<endl;
                map<char,int> m1;
                
                for(int i= p ; i< p+3 ; i++){
                    for(int j= q ; j< q+3 ; j++){
                    
                        //cout<<"ij "<<i <<" || "<<j<<endl;
                        
                        if(board[i][j]=='.'){
                             continue;
                         }

                         if(m1.find(board[i][j])==m1.end()){
                             m1[board[i][j]]=1;
                         }else{

                             return false;
                         }

                        
                        
                        
                    }
                }
                
                
            }
        }
        
        
            
        
        return true;
    }
};