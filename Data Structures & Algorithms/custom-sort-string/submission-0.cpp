class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> mp;
        for (auto c: s) {
            mp[c] += 1;
        }
        string ans = "";
        for (auto c : order) {
            if (mp.contains(c)) {
                for (int i = 0; i < mp[c]; i++) {
                    ans += c;
                }
                mp[c] = 0;
            }
        }
        for (auto c: s) {
            if (mp[c] > 0) ans += c;
        }
        return ans;
    }
};