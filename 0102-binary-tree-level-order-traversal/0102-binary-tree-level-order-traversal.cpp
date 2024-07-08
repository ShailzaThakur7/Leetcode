// #include <vector>
// #include <queue>

// using namespace std;

// // Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        
        queue<TreeNode*> q;
        q.push(root); // Push the root node into the queue
        
        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes at the current level
            vector<int> levelNodes; // To store nodes at the current level
            
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Add the node's value to the current level vector
                levelNodes.push_back(node->val);
                
                // Add left and right children to the queue if they exist
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            // Add the current level vector to the result
            result.push_back(levelNodes);
        }
        
        return result;
    }
};
