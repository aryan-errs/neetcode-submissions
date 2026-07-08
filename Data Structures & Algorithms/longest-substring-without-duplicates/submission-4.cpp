class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        set<char> st;
        int j = 0, i = 0; 
        while(i < s.size()){
            if(j < s.size() and st.find(s[j]) == st.end()){
                st.insert(s[j]);
                j++;
                ans = max(ans, j-i);
            }
            else{
                st.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};
