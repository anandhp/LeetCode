/**
*   Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
*   
*   push(x) -- Push element x onto stack.
*   pop() -- Removes the element on top of the stack.
*   top() -- Get the top element.
*   getMin() -- Retrieve the minimum element in the stack.
*
**/

class MinStack {
public:
    void push(int x) {
        baseStack.push(x);
        if (minStack.empty() || minStack.top() >= baseStack.top())
            minStack.push(x);
    }

    void pop() {
        if (!minStack.empty() && minStack.top() == baseStack.top())
            minStack.pop();
        baseStack.pop();    
    }

    int top() {
        return baseStack.top();
    }

    int getMin() {
        return minStack.top();
    }

private:
    std::stack<int> baseStack;
    std::stack<int> minStack;
};