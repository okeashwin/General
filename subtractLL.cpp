/*
Given a singly linked list, modify the value of first half nodes such that :

    1st node’s new value = the last node’s value - first node’s current value
    2nd node’s new value = the second last node’s value - 2nd node’s current value,

and so on …

*/

void reverseList(ListNode *middle) {
    if(middle==NULL || middle->next==NULL) {
        return;
    }
    ListNode *curr=middle->next, *currN, *prev=NULL;
    while(curr!=NULL) {
        currN=curr->next;
        curr->next=prev;
        prev=curr;
        curr=currN;
    }
    middle->next=prev;
}

ListNode* Solution::subtract(ListNode* head) {
    if(head==NULL) {
        return head;
    }
    ListNode *fast=head, *middle=head;
    while(fast->next && fast->next->next) {
        middle=middle->next;
        fast=fast->next;
        fast=fast->next;
    }
    
    reverseList(middle);
    ListNode *off=middle->next, *temp=head;
    while(off!=NULL) {
        temp->val=off->val-temp->val;
        off=off->next;
        temp=temp->next;
    }
    
    reverseList(middle);
    return head;
}
