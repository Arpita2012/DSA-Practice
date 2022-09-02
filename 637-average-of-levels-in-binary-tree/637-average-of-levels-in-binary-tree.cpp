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
    vector<double> averageOfLevels(TreeNode* root) {
        
        queue<pair<TreeNode *, int>> Q;
        
        Q.push({root,0});
        
        int prev_level = 0;
        int cnt=0;double sum=0;;
        vector<double> ans;
        while(!Q.empty()){
            TreeNode * T = Q.front().first;
            int level = Q.front().second;
            cout<<" T : "<<T->val<<endl;
            
            Q.pop();
            
            if(T->left){
                Q.push({T->left, level+1});
            }
            
            
            if(T->right){
                Q.push({T->right, level+1});
            }
            
            
            if(level==prev_level){
                sum=sum+(T->val) ;
                cnt++;
            }else{
                cout<<"sum : "<<sum<<endl;
                ans.push_back((1.0 *sum)/cnt);
                sum=T->val;
                cnt=1;
                prev_level=level;
            }

        }
        
                       ans.push_back((1.0 *sum)/cnt);
 
        
        
        
        
        return ans;
        
        
    }
};