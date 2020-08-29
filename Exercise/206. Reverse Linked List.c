//需要3個指標pre cur nxt cur->next=pre and so on ...
struct ListNode* reverseList(struct ListNode* head){
    if(!head)
        return NULL;
    struct ListNode*pre=NULL,*cur=head,*nxt=head->next;
    while(nxt){
        cur->next=pre;
        pre=cur;
        cur=nxt;
        nxt=nxt->next;
    }
    cur->next=pre;
    return cur;
}