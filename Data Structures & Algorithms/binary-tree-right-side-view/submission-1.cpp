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
        queue<TreeNode*>q; 
        if(root == NULL){
            return {};
        }
        vector<int>arr;
        TreeNode* next;
        q.push(root);
        while(!q.empty()){
            int size = q.size(); 
            next = NULL;
            for(int i = 0;i < size;i++){
                TreeNode* top = q.front(); 
                q.pop();
                if(top){
                    next = top;
                    q.push(top->left);
                    q.push(top->right);
                    
                }
            }
            if(next)arr.push_back(next->val); 
            
        }
        return arr;
    }
 
};
