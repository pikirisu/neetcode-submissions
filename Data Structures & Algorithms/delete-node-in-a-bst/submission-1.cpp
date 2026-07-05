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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return nullptr;
       if(key<root->val){
        root->left = deleteNode(root->left,key);
       }
       else if(key>root->val){
        root->right = deleteNode(root->right,key);
       }
       else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            return nullptr;
        }
        else if(root->left==NULL && root->right!=NULL){
            TreeNode * store =  root->right;
            delete root;
            return store;
        }
        else if(root->left!=NULL && root->right==NULL){
            TreeNode * store = root->left;
            delete root;
            return store;
        }
        else{
            TreeNode * store = root->right->left;
            TreeNode * newRoot = root->right;
            newRoot->left = root->left;
            
            delete root;
            TreeNode * temp = newRoot->left;
            while(temp->right!=NULL){
                temp=temp->right;
            }
            temp->right = store;
            return newRoot;
        }
       }
       return root;
    }
};