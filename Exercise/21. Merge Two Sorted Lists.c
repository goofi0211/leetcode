
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode*newhead;
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    if(l1->val<l2->val){
        newhead=l1;
        l1=l1->next;
    }
    else{
        newhead=l2;
        l2=l2->next;
    }
    struct ListNode *cur=newhead;
    while(l1!=NULL&&l2!=NULL){
        if(l1->val<l2->val){
            cur->next=l1;
            l1=l1->next;
            cur=cur->next;
        }
        else{
            cur->next=l2;
            l2=l2->next;
            cur=cur->next;
        }
    }
    if(l1==NULL&&l2!=NULL)
        cur->next=l2;
    else if(l2==NULL&&l1!=NULL)
        cur->next=l1;
    return newhead;
    
}