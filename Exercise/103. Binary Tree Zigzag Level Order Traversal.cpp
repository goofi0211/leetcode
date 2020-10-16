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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        int even=1;
        while(!q.empty()){
            int s=q.size();
            vector<int>temp;
            for(int i=0;i<s;i++){
                TreeNode * t=q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
            if(even%2==0){
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            else
                ans.push_back(temp);
            even++;
        }
        return ans;
        
    }
};