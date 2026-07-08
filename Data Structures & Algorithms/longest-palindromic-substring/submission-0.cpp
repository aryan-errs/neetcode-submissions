class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int len = 0;
        for(int i = 0; i < s.size(); i++){
            // odd length
            int l = i-1, r = i+1;
            string temp = "";
            temp += s[i];
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                temp = s[l] + temp + s[r];
                if(r-l+1 > len){
                    len = r-l+1;
                    ans = temp;
                }
                l--;
                r++;
            }
            if(r-l+1 > len){
                len = r-l+1;
                ans = temp;
            }
            l = i, r = i+1;
            temp = "";
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                temp = s[l] + temp + s[r];
                if(r-l+1 > len){
                    len = r-l+1;
                    ans = temp;
                }
                l--;
                r++;
            }
            if(r-l+1 > len){
                len = r-l+1;
                ans = temp;
            }
        }
        return ans;
    }
};
