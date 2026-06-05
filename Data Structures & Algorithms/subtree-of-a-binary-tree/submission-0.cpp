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
    bool sameTree(TreeNode * p, TreeNode * q){
        if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;

        if(p->val!=q->val) return false;
        bool leftAns = sameTree(p->left,q->left);
        bool rightAns = sameTree(p->right,q->right);

        return leftAns && rightAns;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL) return false;
        if(sameTree(root,subRoot)) return true;
        bool leftAns = isSubtree(root->left,subRoot);
        bool rightAns = isSubtree(root->right,subRoot);

        return leftAns || rightAns; 
    }
};
