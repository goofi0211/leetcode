/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            vector<Node*>temp;
            for(int i=0;i<s;i++){
                Node* t=q.front();
                q.pop();
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
                temp.push_back(t);
            }
            for(int i=0;i<temp.size()-1;i++){
                temp[i]->next=temp[i+1];
            }
            temp[temp.size()-1]->next=nullptr;
        }
        return root;
    }
};