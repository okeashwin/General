#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
    int val;
    struct stack *next;
}stack;

int isEmpty(stack **top) {
    if(*top==NULL) return 1;
    return 0;
}


void push(stack **top, int val) {
    stack *n=malloc(sizeof(stack));
    n->val=val;
    n->next=NULL;
    if(*top==NULL) *top=n;
    else  {
        n->next=*top;
        *top=n;
    }
    printf("%d\n", (*top)->val);
}

void pop(stack **top) {
    if(isEmpty(top)) return;
    *top=(*top)->next;
}

int top(stack **top) {
    if(isEmpty(top)) return -1;
    return (*top)->val;
}

typedef struct {
    stack *s1, *s2;
} Queue;

/* Create a queue */
void queueCreate(Queue *queue, int maxSize) {
    queue->s1=NULL;
    queue->s2=NULL;
}

/* Push element x to the back of queue */
void queuePush(Queue *queue, int element) {
    push(&(queue->s1), element);
}

/* Removes the element from front of queue */
void queuePop(Queue *queue) {
    if(!isEmpty(&(queue->s2))) {
        pop(&(queue->s2));
        return;
    }
    while(!isEmpty(&(queue->s1))) {
        int val=top(&(queue->s1));
        pop(&(queue->s1));
        push(&(queue->s2), val);
    }
    pop(&(queue->s2));
}

/* Get the front element */
int queuePeek(Queue *queue) {
    printf("s2 : %d\ts1:%d\t\n",isEmpty(&(queue->s1)), isEmpty(&(queue->s2)));
    if(!isEmpty(&(queue->s2))) return top(&(queue->s2));
    while(!isEmpty(&(queue->s1))) {
        int val=top(&(queue->s1));
        pop(&(queue->s1));
        printf("peek val : %d\n",val);
        push(&(queue->s2), val);
    }
    return top(&(queue->s2));
}

/* Return whether the queue is empty */
int queueEmpty(Queue *queue) {
    return isEmpty(&(queue->s1)) && isEmpty(&(queue->s2));
}

/* Destroy the queue */
void queueDestroy(Queue *queue) {
}

int main() {
    Queue q;
    queueCreate(&q,1);
    //q=malloc(sizeof(Queue));
    printf("%p\n", &q);
    queuePush(&q,1);
    printf("%d\n",queuePeek(&q));
    return 0;
}