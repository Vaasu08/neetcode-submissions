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
    int rob(TreeNode* root) {
        vector<int>ans = dfs(root);
        return max(ans[0],ans[1]);
    }
    vector<int>dfs(TreeNode* root){
        if(root == NULL){
            return {0,0}; 
        }
        vector<int>leftpair = dfs(root->left);
        vector<int>rightpair = dfs(root->right);
        int withRoot = root->val + leftpair[1] + rightpair[1];
        int withoutRoot = max(leftpair[0],leftpair[1]) + max(rightpair[0], rightpair[1]);
        
        return {withRoot,withoutRoot};
    }
};