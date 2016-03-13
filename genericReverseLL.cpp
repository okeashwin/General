
/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.
*/

ListNode* Solution::reverseBetween(ListNode* head, int m, int n) {

    if(head==NULL || head->next==NULL) {
        return head;
    }
    ListNode *dummy=new ListNode(INT_MAX);
    dummy->next=head;
    ListNode *start=dummy, *end=dummy, *temp=head;
    for(int i=0;i<m-1;i++) {
        start=start->next;
    }
    // list needs to reverse from start->next;
    ListNode *first=start->next;
    for(int i=0;i<n;i++) {
        end=end->next;
    }
    ListNode *prev=NULL, *curr=first, *currN=first->next;
    ListNode *endN=end->next;
    while(curr!=endN) {
        currN=curr->next;
        curr->next=prev;
        prev=curr;
        curr=currN;
    }
    first->next=endN;
    start->next=end;
    
    return dummy->next;
}