class Solution {
public:
    
    bool permutation(vector<int> &V, int str_idx){
        
        if(str_idx==V.size()){
            return checkPower2(V);
            
        }
        
        for(int i= str_idx; i<V.size(); i++){
            swap(V[str_idx], V[i]);
            if (permutation(V,str_idx+1)){
                return true;
            }
            swap(V[str_idx], V[i]);
            
        }
        
        return false;
        
    }
    
    bool checkPower2(vector<int> &V){
        if (V[0] == 0)
            return false;
        int NUM=0;
        
        for(auto x :V){
            NUM=NUM*10+x;
        }
        
//         cout<<endl<<NUM<<endl;
//          bitset<64> b1(NUM);
        
//         return b1.count()==1? true:false;
        
         while (NUM > 0 && ((NUM & 1) == 0))
            NUM >>= 1;

       
        return NUM == 1;
        
        
    }
    
    
    bool reorderedPowerOf2(int n) {
        
        vector<int> V;
        
        int NUM= n;
        
        while(NUM>0){
            int LD =NUM%10;
            
            V.push_back(LD);
            
            NUM=NUM/10;
            cout<<LD<< " ";
            
        }
        
        reverse(V.begin(), V.end());
        
        
        return permutation(V,0);
        
        
        
    }
};