class Stack {
private:
    queue<int> aux1;
    queue<int> aux2;
public:
    // Push element x onto stack.
    void push(int x) {
        if(aux1.empty())
        {
            aux2.push(x);
        }
        else
        {
            aux1.push(x);
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> *curr;
        queue<int> *notCurr;
        if(aux1.empty())
        {
            curr = &aux2;
            notCurr = &aux1;
        }
        else
        {
            curr = &aux1;
            notCurr = &aux2;
        }
        
        int size = curr->size();
        while(size!=1)
        {
            notCurr->push(curr->front());
            curr->pop();
            size--;
        }
        
        // Curr has one element, which is the 'popped off stack'
        curr->pop();
        
    }

    // Get the top element.
    int top() {
        queue<int> *curr;
        if(aux1.empty())
        {
            curr = &aux2;
        }
        else
        {
            curr = &aux1;
        }
        
        return curr->back();
        
    }

    // Return whether the stack is empty.
    bool empty() {
        return aux1.empty() && aux2.empty();
        
    }
};