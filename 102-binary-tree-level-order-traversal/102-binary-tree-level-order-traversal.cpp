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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue <pair<TreeNode* ,int>> Q;
        
        if(!root){
            return res;
        }
        
        Q.push({root,0});
        
        
        int curr_level =0;
        
        vector<int> res_temp ;
        
        while(!Q.empty()){
            
            TreeNode * T = Q.front().first;
            int level = Q.front().second;
            
            //cout<< T->val <<" : "<<level <<endl;
            
            if(curr_level == level){
                //cout<<"H1\n";
                res_temp.push_back(T->val);
            }else{
                  //cout<<"H21\n";
                res.push_back(res_temp);
                res_temp.clear();
                res_temp.push_back(T->val);
                curr_level = level;
            }
            //cout<<" --------"<<endl;
            
           
            
            Q.pop();
            
            if(T->left){
                Q.push({T->left,level+1});
            }
            
            if(T->right){
                Q.push({T->right,level+1});
            }
            
            
            
            
        }
        
        if(res_temp.size()>0){
             res.push_back(res_temp);
        }
        
        
        return res;
        
        
        
    }
};