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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)
            return nullptr;
        TreeNode* t=new TreeNode(preorder[0]);
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==preorder[0]){
                vector<int>newp;
                vector<int>newi;
                newp.assign(preorder.begin()+1,preorder.begin()+1+i);
                newi.assign(inorder.begin(),inorder.begin()+1);
                t->left = buildTree(vector<int>& newp, vector<int>& newi);
                vector<int>rnewp;
                vector<int>rnewi;
                rnewp.assign(preorder.begin()+i+1,preorder.end());
                rnewi.assign(inorder.begin()+i+1,inorder.end());
                t->right = buildTree(vector<int>& rnewp, vector<int>& rnewi);
            }
        }
        return t;
    }
};