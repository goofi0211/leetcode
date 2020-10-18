/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //將int 丟入ostringstream會自動轉為string
 //從istringstream讀出的流 會依據空格分開(如果一開始有空格的話)
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        myserialize(root,out);
        return out.str();
    }
    void myserialize(TreeNode*root,ostringstream &out){
        if(!root){
            out<<"# ";
            return ;
        }
        out<<root->val<<" ";
        myserialize(root->left,out);
        myserialize(root->right,out);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        TreeNode*root=mydeserialize(in);
        return root;
    }
    TreeNode *mydeserialize(istringstream& in){
        string temp;
        in>>temp;
        TreeNode* tnode;
        if(temp!="#"){
            cout<<temp;
            tnode = new TreeNode(stoi(temp));
            tnode->left = mydeserialize(in);
            tnode->right = mydeserialize(in);
        }
        else
            return nullptr;
        return tnode;
    }
};