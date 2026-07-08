class Solution {
public:
    void solve(int index, string curr, string digits, vector<string> &ans, map<int,string> mp) {
        if (index == digits.size() and !curr.empty()) {
            ans.push_back(curr);
            return;
        }
        int num = digits[index] - '0';
        for (char c: mp[num]) {
            curr.push_back(c);
            solve(index + 1, curr, digits, ans, mp);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        map<int, string> mp = {
            {1, ""},
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };


        solve(0, "", digits, ans, mp);
        return ans;
    }
};
