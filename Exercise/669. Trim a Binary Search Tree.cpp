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
//if the node>high than this node must be replace to it's left child
//if the node<low than this node must be replace to it's right child 
//make sure that the child follow the rule so recursive it

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root)return nullptr;
        if(root->val>high)
            return trimBST(root->left,low,high);
        if(root->val<low)
            return trimBST(root->right,low,high);
        else{
            root->left=trimBST(root->left,low,high);
            root->right=trimBST(root->right,low,high);
        }
        return root;
    }
    
};