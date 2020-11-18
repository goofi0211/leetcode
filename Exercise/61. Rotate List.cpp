/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return nullptr;
        if(k==0)return head;//not need to rotate
        int cnt=0;//count the number of node
        ListNode* cur=head;
        while(cur){
            cnt++;
            cur=cur->next;
        }
        int ftail=cnt-(k%cnt);
        if(ftail==cnt)//not need to rotate
            return head;
        int t=1;
        cur=head;
        while(t!=ftail){
            t++;
            cur=cur->next;
        }
        ListNode* newhead=cur->next;//the next of the ftail will be the newhead
        cur->next=nullptr;
        cur=newhead;
        while(cur->next!=nullptr){
            cur=cur->next;
        }
        cur->next=head;
        return newhead; 
    }
};