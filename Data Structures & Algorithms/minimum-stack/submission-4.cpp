class MinStack {
public:
    stack<pair<int,int>> st;
    int minEl = INT_MAX;
    MinStack() {
        minEl = INT_MAX;
    }
    
    void push(int val) {
        if(!st.empty()){
            minEl = min(minEl, val);
            st.push({val, minEl});
            
        }else {
            st.push({val, val});
            minEl = val;
        }
        
    }
    
    void pop() {
        st.pop();
        if(st.empty()){
            minEl = INT_MAX;
            return;
        }
        minEl = st.top().second;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
