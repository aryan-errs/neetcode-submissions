class Solution {
public:
    // bool solve(string s, int index, vector<bool>& dp, vector<string>& wordDict){
    //     if(index >= s.size()){
    //         return true;
    //     }
    //     if(dp[index]) return dp[index];
    //     for(auto word: wordDict){
    //         if(s.substr(index,word.size()) == word){
    //             dp[index] = solve(s, index+word.size(), dp, wordDict);
    //         }
    //     }
    //     return dp[index];
    // }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[s.size()] = true;
        for(int i = s.size()-1; i>=0; i--){
            for(auto word: wordDict){
                if(i + word.size() <= s.size() && s.substr(i, word.size()) == word){
                    dp[i] = dp[i+ word.size()];
                }
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
};
