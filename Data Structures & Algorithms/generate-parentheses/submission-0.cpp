class Solution {
public:
    void solve(int n, int opened, int closed, string s, vector<string> &res){
        if(closed == opened && opened == n){
            res.push_back(s);
            return;
        }
        if(opened < n) solve(n, opened+1, closed, s + '(', res);
        if(closed < opened) solve(n, opened, closed + 1, s + ')', res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(n, 0, 0, "", res);
        return res;
    }
};
