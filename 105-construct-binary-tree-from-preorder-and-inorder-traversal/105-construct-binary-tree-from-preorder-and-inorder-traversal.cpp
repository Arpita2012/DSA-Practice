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
class Solution {
public:
    
  int  searchInorder(vector<int>& inorder , int f, int l,int target){
       for(int i=f ; i<=l; i++){
           if(inorder[i]==target){
               return i;
           }
       }
       return -1;
   } 
    
    
   TreeNode* construct(vector<int>& preorder, vector<int>& inorder, int & idx,int f,int l){
       
      if( f>l){
          return NULL;
      }
       
       if(idx==preorder.size()){
           return NULL;
       }
       
       int a =preorder[idx++];
       //cout<<a<<endl;
       
       int a_idx_inorder = searchInorder(inorder ,  f,  l,a);
       
      
       TreeNode * head = new TreeNode(a);
       
       //cout<<head->val<<endl;
       
       head->left = construct(preorder,inorder,idx ,f, a_idx_inorder -1);
       head->right = construct(preorder,inorder,idx , a_idx_inorder +1,l);
       
       return head;
       
       
       
       
   }
        
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int idx =0;
        return construct(preorder,inorder,idx ,0, preorder.size() -1);
        
        
        
    }
};