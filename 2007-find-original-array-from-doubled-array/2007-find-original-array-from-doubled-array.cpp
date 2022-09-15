class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        vector<int> original;
       
        
     sort(changed.begin(), changed.end());
        
     int N= changed.size();
        map<int,int> M;
        
        for(auto c : changed){
            M[c]++;
            
            
        }
        
        
        for(int i =0 ; i< N; i++){
            
            if(M[changed[i]]==0){
                continue;
            }
            M[changed[i]]--;
             if(M[changed[i] *2]==0){
                return {};
            }
            
            
            original.push_back(changed[i]);
            
            
            M[changed[i]*2]--;
            
        }

    
       return original;
        
    }
};