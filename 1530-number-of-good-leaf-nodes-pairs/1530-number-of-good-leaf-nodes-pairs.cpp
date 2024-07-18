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
    int countPairs(TreeNode* root, int distance) {
        int result=0;
        dfs(root,distance,result);
        return result;        
    }
private:
    vector<int> dfs(TreeNode* node,int distance,int& result){
        if(!node) return{};
        
        
        if(!node->left && !node->right)return{1};
        
        vector<int> leftdistances=dfs(node->left,distance,result);
        vector<int> rightdistances=dfs(node->right,distance,result);
        
        for(int l:leftdistances){
            for(int r:rightdistances){
                if(l+r<=distance){
                    result++;
                }
            }
        }
        
        vector<int> distances;
        for(int l:leftdistances){
            if(l+1<distance){
                distances.push_back(l+1);
            }
        }
        for(int r:rightdistances){
            if(r+1<distance){
                distances.push_back(r+1);
            }
        }
        
        return distances;
    }
};