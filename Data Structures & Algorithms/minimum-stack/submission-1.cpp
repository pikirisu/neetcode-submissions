class MinStack {
public:
    stack<int> all;
    stack<int> min;
    MinStack() {
        
    }
    
    void push(int val) {
        all.push(val);

if (min.empty() || val <= min.top())
    min.push(val);
    }
    
    void pop() {
        if(all.top()==min.top())
        min.pop();
        all.pop();
    }
    
    int top() {
        return all.top();
    }
    
    int getMin() {
        return min.top();
    }
};
