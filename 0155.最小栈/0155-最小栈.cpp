class MinStack {
private:
    stack<int> dataStack;
    stack<int> minStack;

public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        dataStack.push(x);
        if( minStack.empty() ){
            minStack.push(x);
        }else if( x < minStack.top() ){
            minStack.push(x);
        }else{
            minStack.push( minStack.top() );
        }

    }
    
    void pop() {
        dataStack.pop();
        minStack.pop();
    }
    
    int top() {
        return dataStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */