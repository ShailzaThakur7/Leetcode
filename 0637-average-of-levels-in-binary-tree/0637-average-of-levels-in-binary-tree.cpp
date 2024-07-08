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
        vector<double> result;
        if (root == nullptr) {
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int levelSize = q.size(); // Number of nodes at the current level
            double levelSum = 0;
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                levelSum+=node->val;
                    
                    if(node->left!=NULL){
                        q.push(node->left);
                    }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            double average=levelSum/levelSize;
            result.push_back(average);
        }
        return result;
        
    }
};