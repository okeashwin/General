#include <iostream>
#include <stack>

using namespace std;

class MinStack {
private:
    stack<int> dataStack;
    stack<int> minStack;
public:
    void push(int x) {
        dataStack.push(x);
        if(minStack.empty())
        {
            minStack.push(x);
        }
        else
        {
            int currMin = minStack.top();
            if(x <= currMin)
            {
                minStack.push(x);
            }
        }
        
    }

    void pop() {
        int popped = dataStack.top();
        dataStack.pop();
        
        if(popped == minStack.top())
        {
            minStack.pop();
        }
    }

    int top() {
        return dataStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main()
{
    MinStack test;
    test.push(0);
    test.push(1);
    test.push(0);
    cout << test.getMin() << endl;
    test.pop();
    cout << test.getMin() << endl;
}