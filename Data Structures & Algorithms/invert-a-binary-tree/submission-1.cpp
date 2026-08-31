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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<int>result;
        TreeNode* curr = root;
        traverseal(root);
        return root;
    }
    void traverseal(TreeNode* root){
        
        if(root->right && root->left){TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        }else{
            if(root->right){
                TreeNode* temp;
                temp = root->right;
                root->right = nullptr;
                root->left = temp;
            }else{
                TreeNode* temp;
                temp = root->left;
                root->left = nullptr;
                root->right = temp;
            }
        }
        if(root->left)traverseal(root->left);
        if(root->right)traverseal(root->right);
        

    }
    
};
