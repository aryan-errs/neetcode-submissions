class MinStack {
public:
    stack<pair<int,int>> st;
    int minEl = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        int minElement;
        if(!st.empty()){
            minElement = min(st.top().second, val);
        }
        else minElement = val;
        st.push({val, minElement});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
