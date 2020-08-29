//用兩者指標兩個差距為n，當快的指標走到null時，slow那個指標所指的點就是要刪除的點

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode*slow=head ,*fast=head,*pre=head;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    while(fast!=NULL){
        pre=slow;
        fast=fast->next;
        slow=slow->next;
    }
    if(pre==slow)
        return slow->next;
    pre->next=slow->next;
    return head;
}