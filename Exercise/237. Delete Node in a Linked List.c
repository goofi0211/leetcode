/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //如果nxt指向null，代表目前的cur需要被改成null
 //但是不是直接將cur改成null，而是要將cur前面的人next指向null所以ˇ 要一個pre
void deleteNode(struct ListNode* node) {
    struct ListNode*cur=node,*nxt=node->next,*pre;
    while(nxt!=NULL){
        cur->val=nxt->val;
        pre=cur;
        cur=nxt;
        nxt=nxt->next;
    }
    pre->next=NULL;
}