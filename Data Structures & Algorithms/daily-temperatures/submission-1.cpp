class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> result(n, 0);
        stack<int> st;
        st.push(n-1);
        for(int i = n-2; i >= 0; i--){
            while(!st.empty() && temps[st.top()] <= temps[i]){
                st.pop();
            }
            if(!st.empty()) result[i] = st.top()-i;
            st.push(i);
        }
        return result;
    }
};
