class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int N = dominoes.length();
        
        int * F = new int[N];
        fill_n(F,N,0);
        
        if(dominoes[0]=='R'){
            F[0]=N;
        }
        
        for(int i=1 ; i< N ; i++){
            if(dominoes[i]=='R'){
                F[i]=N;
            }else if(dominoes[i]=='.'){
                if(F[i-1]>0){
                    F[i]=F[i-1]-1;
                }
            }
            
            //
            
        }
        
        // for(int i=0 ; i<N ;i++){
        //     cout<<F[i]<<" ";    
        // }
        
        cout<<endl;
        int * F_rev = new int[N];
        fill_n(F_rev,N,0);
        
        if(dominoes[N-1]=='L'){
            F_rev[N-1]= -N;
        }
        
        for(int i=N-2 ; i>=0 ; i--){
            if(dominoes[i]=='L'){
                F_rev[i]= -N;
            }else if(dominoes[i]=='.'){
                if(F_rev[i+1]<0){
                    F_rev[i]=F_rev[i+1]+1;
                }
            }
            
            //cout<<F_rev[i]<<" ";    
            
        }
        
        string ans="";
           for(int i=0 ; i<N ;i++){
            //cout<<F_rev[i]<<" ";    
               if(F_rev[i] + F[i] > 0){
                   ans.push_back('R');
               }else if(F_rev[i] + F[i] < 0){
                   ans.push_back('L');
                   
               }else{
                   ans.push_back('.');
                   
               }
        }
        
        return ans;
        
        
        
    }
};