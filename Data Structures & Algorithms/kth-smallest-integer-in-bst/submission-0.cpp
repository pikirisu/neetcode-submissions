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
    void preorder(TreeNode * root, int& k,int &store){
        if(root==NULL) return;
        if(store!=-1) return;

        preorder(root->left,k,store);
        k--;
        if(k==0) store = root->val;

        preorder(root->right,k,store);

    }
    int kthSmallest(TreeNode* root, int k) {
        int store = -1;
        int K = k; 
        preorder(root,K,store);
        return store;
    }
};
