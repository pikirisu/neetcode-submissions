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
    int count =0;

    void solve(TreeNode * root, int curr_max){
        if(root==NULL)
        return;

        if(root->val>=curr_max){
            count++;
        }

        curr_max = max(curr_max,root->val);

        solve(root->left, curr_max);
        solve(root->right, curr_max);
        
    }

    int goodNodes(TreeNode* root) {
        solve(root,root->val);
        return count;
    }
};
