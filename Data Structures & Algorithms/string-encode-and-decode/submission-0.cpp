class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for (auto s: strs) {
            int n = s.size();
            ans += to_string(n) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string str) {
        vector<string> ans;
        int i = 0;
        while (i < str.size()) {
            int sz = 0;
            while (str[i] != '#') {
                sz *= 10;
                sz += str[i]-'0';
                i++;
            }
            i++;
            string s = str.substr(i, sz);
            ans.push_back(s);
            i += sz;
        }
        return ans;
    }
};
