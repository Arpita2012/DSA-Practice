/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
   /*// METHOD 1 
   vector<int> save;
    int i=-1;
    void inorder(TreeNode* root ){
        if(!root){
            return;
        }
        inorder(root->left);
        save.push_back(root->val);
        inorder(root->right);
        
    }
    
    public:
   
    BSTIterator(TreeNode* root) {
        
        inorder(root);
        
    }
    
    int next() {
        i++;
        if(i<save.size())
            return save[i];
        return -1;
    }
    
    bool hasNext() {
        if(i+1 < save.size()){
            return true;
            
        }else{
            return false;
        }
    }*/
     
    public:
    
    //METHOD 2 O(h) - space complexity
    stack<TreeNode*> S;
    TreeNode* curr =NULL;
   
    BSTIterator(TreeNode* root) {
        
        
        
        curr=root;
        
        while(curr){
            S.push(curr);
            curr=curr->left;
        }
        
        
        
    }
    
    int next() {
       
           TreeNode * temp = S.top(); 
           S.pop();

           if(temp->right){
               curr = temp->right;
                 while(curr){
                    S.push(curr);
                    curr=curr->left;
                }
           }
           
          
        
        return temp->val;  
    }
    
    bool hasNext() {
        if(S.empty() && curr==NULL){
            return false;
        }
        else
            return true;
        
        
    }
    
    
    
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */