// Constant space, Linear time
// Reversing the 2nd half of the LL in place.
 
void reverseList(ListNode *node) {
    if(node==NULL || node->next==NULL) {
        return;
    }
    
    ListNode *prev=NULL, *curr=node->next, *currN=NULL;
    while(curr!=NULL) {
        currN=curr->next;
        curr->next=prev;
        prev=curr;
        curr=currN;
    }
    node->next=prev;
}
int Solution::lPalin(ListNode* head) {
    if(head==NULL || head->next==NULL) {
        return 1;
    }
    ListNode *slow=head, *fast=head;
    while(fast) {
        fast=fast->next;
        if(fast && fast->next) {
            slow=slow->next;
            fast=fast->next;
        }
    }
    ListNode *middle=slow;
    reverseList(slow);
    ListNode *offset=middle->next, *temp=head;
    while(offset!=NULL) {
        if(offset->val!=temp->val) {
            return 0;
        }
        offset=offset->next;
        temp=temp->next;
    }
    return 1;
}
