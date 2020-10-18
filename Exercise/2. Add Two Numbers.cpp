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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode*tail=&dummy;//the pointer point to the tail of linklist
        int sum=0;
        while(l1&&l2){//make sure that l1 and l2 not be the null pointer 
            int value=(l1->val+l2->val+sum)%10;
            sum=(l1->val+l2->val+sum)/10;
            ListNode*temp=new ListNode(value);
            tail->next=temp;
            tail=tail->next;
            l1=l1->next;
            l2=l2->next;
        }
        if(sum&&l1){
            ListNode*temp=new ListNode(sum);
            tail->next=addTwoNumbers(temp,l1);
        }
        else if(sum&&l2){
            ListNode*temp=new ListNode(sum);
            tail->next=addTwoNumbers(temp,l2);
        }
        else if(sum){
             ListNode*temp=new ListNode(sum);
             tail->next=temp;
        }
        else if(!sum&&l1){
            tail->next=l1;
        }
        else if(!sum&&l2){
            tail->next=l2;
        }
        return dummy.next;
    }
};