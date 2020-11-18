/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 用一個slow指標跟fast指標，
 fast每次走兩步slow每次走一步
 當fast走不下去
 slow就在位置不遠處了
 若長度為
 偶數要加1
 奇數不用加1
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast)
            return slow->next;
        return slow;
        
        
    }
};