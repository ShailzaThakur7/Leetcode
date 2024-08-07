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
        vector<int> result;
        if(root==NULL){
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int level=q.size();
            TreeNode* last=NULL;
            
            for(int i=0;i<level;++i){
                TreeNode* node=q.front();
                q.pop();
                last=node;
                
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            result.push_back(last->val);
        }
        return result;
        
        
        
    }
};