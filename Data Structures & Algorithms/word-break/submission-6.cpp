class Solution {
public:
    bool solve(string s, int index, vector<int>& dp, vector<string>& wordDict){
        if(index >= s.size()){
            return true;
        }
        if(dp[index] != -1) return dp[index];
        for(auto word: wordDict){
            if(s.substr(index,word.size()) == word){
                if(solve(s, index+word.size(), dp, wordDict)){
                    dp[index] = 1;
                    return true;
                }
            }
        }
        dp[index] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return solve(s, 0, dp, wordDict);
    }
};
