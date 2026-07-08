class Solution {
public:
    void solve(int index, string temp, string digits, unordered_map<char,string> mp, vector<string> &res){
        if(temp.length() == digits.length()){
            res.push_back(temp);
            return;
        }
        for(char c: mp[digits[index]]){
            temp.push_back(c);
            solve(index+1, temp, digits, mp,res);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length() == 0){
            return res;
        }
        unordered_map<char, string> mp = {
            {'2' , "abc"},
            {'3' , "def"},
            {'4' , "ghi"},
            {'5' , "jkl"},
            {'6' , "mno"},
            {'7' , "pqrs"},
            {'8' , "tuv"},
            {'9' , "wxyz"},
        };
        solve(0, "", digits, mp, res);
        return res;

    }
};
