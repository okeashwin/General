
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

typedef struct TreeNode Node;
typedef struct StackNode {
    Node *node;
    struct StackNode *next;
}stack;

void push(stack **top, Node *node) {
    stack *new_=malloc(sizeof(stack));
    new_->node=node;
    new_->next=NULL;
    if(*top==NULL) {
        *top=new_;
    }
    else {
        new_->next=(*top);
        (*top)=new_;
    }
    printf("Top of stack : %d\n", (*top)->node->val);
}
int isEmpty(stack **top) {
    if(*top==NULL) {
        return 1;
    }
    return 0;
    
}
Node *pop(stack **top) {
    if(isEmpty(top)) {
        return NULL;
    }
    Node *temp=(*top)->node;
    *top=(*top)->next;
    return temp;
    
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    if(root==NULL) {
        *returnSize=0;
        return NULL;
    }
    
    stack *aux1=NULL, *aux2=NULL;
    push(&aux1, root);
    int nodes=1;
    Node *popped=NULL;
    while(!isEmpty(&aux1)) {
        popped=pop(&aux1);
        if(popped->left!=NULL) {
            push(&aux1, popped->left);
            nodes++;
        }
        if(popped->right!=NULL) {
            push(&aux1, popped->right);
            nodes++;
        }
        printf("%d\n",popped->val);
        push(&aux2, popped);
    }
    int *result=malloc(sizeof(int)*nodes);
    memset(result,0,sizeof(int)*nodes);
    *returnSize=nodes;
    int i=0;
    while(!isEmpty(&aux2)) {
        *(result+i)=pop(&aux2)->val;
        i++;
    }
    return result;
    }

int main() {
    Node *root=malloc(sizeof(Node));root->val=1;
    root->left=malloc(sizeof(Node)); root->left->val=2;
    root->right=malloc(sizeof(Node)); root->right->val=3;
    root->left->left=malloc(sizeof(Node)); root->left->left->val=4;
    root->left->right=malloc(sizeof(Node)); root->left->right->val=5;
    root->right->left=malloc(sizeof(Node)); root->right->left->val=6;
    root->right->right=malloc(sizeof(Node)); root->right->right->val=7;

    int ret=0;
    int *res=postorderTraversal(root, &ret);
}