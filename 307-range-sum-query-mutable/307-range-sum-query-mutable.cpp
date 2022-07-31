class NumArray {
public:
    
    int * TREE=NULL;
    int N;
    
    NumArray(vector<int>& nums) {
    N=nums.size();
        TREE = new int [2*N];
        
        int j=0;
        for(int i=N; i<2*N; i++){
            TREE [i] = nums[j++];
        }
        //NOTE : We assume index starting from 1 to have 2*i as left and 2*i+1 as riight child
        for(int i=N-1 ; i>0; i--){
            TREE[i]= TREE[2*i]+ TREE[2*i+1];
        }
        
        
        
    }
    
    void update(int index, int val) {
        
        //nums[index]=val;
        
        index= index+N;
        
        TREE[index]=val;
        
        while(index>0){
            int left = index;
            int right=index;
            
            if(index%2==0){
                //this is left child
                right = index+1;
            }else{
                left = index-1;
            }
            
            TREE[index/2] = TREE[left]+TREE[right];
            index = index/2;
            
            
        }
        
    }
    
    int sumRange(int l, int r) {
        
        // get leaf with value 'l'
        l =l+N;
        // get leaf with value 'r'
        r =r+ N;
        int sum = 0;
        while (l <= r) {
            if ((l % 2) == 1) {
               sum += TREE[l];
               l++;
            }
            if ((r % 2) == 0) {
               sum += TREE[r];
               r--;
            }
            l =l/ 2;
            r = r/2;
        }
        return sum;
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */