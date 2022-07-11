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
    vector<int> rightSideView(TreeNode* root) {
        
        //rightmost node in level order trversal
        
         vector<int>  ans ;
        queue <pair<TreeNode*,int>> q;
        
        if(!root){
            return ans;
        }
        
        q.push({root,0});
        
        int prev_level= 0;
        int prev_node_data = INT_MIN;
        
        while(!q.empty()){
            
            TreeNode* t = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(prev_level==level){
               
                prev_node_data = t->val;
            }else{
                 ans.push_back(prev_node_data);
                 prev_node_data = t->val;
                prev_level=level;
            }
            
            
            
           // cout<<"t : "<<t->val<<" || "<< level<<endl;
            
            
            
            if(t->left){
                 q.push({t->left,level+1});
            }
            
            if(t->right){
                 q.push({t->right,level+1});
            }
             
            
            
            
        }
        ans.push_back(prev_node_data);
        return ans;
        
        
    }
};